import dotenv from 'dotenv';
import SteamAPI from 'steamapi';
import country from 'country-list';

import { sendToPlatform } from '../../platform/sendToPlatform.js';

dotenv.config();

let steam = new SteamAPI(process.env.STEAM_API_KEY);

async function getStatsString(steamID) {
  const user = await steam.getUserSummary(steamID);
  const level = await steam.getUserLevel(steamID);
  const badges = await steam.getUserBadges(steamID);

  let text = `**Name:** ${user.nickname}\n**SteamID:** ${user.steamID}\n**Country:** ${country.getName(user.countryCode)}\n`;
  if (user.realName != undefined)
    text += `**Real name:** ${user.realName}\n`;
  text += `**Level:** ${level}\n**XP:** ${badges.playerXP}\n**Next level:** ${badges.playerNextLevelXP} xp\n**Current level:** ${badges.playerCurrentLevelXP}\n`;
  text += `**Created at:** ${new Date(user.created * 1000).toLocaleDateString()}\n**Last log off:** ${new Date(user.lastLogOff * 1000).toLocaleDateString()}\n`;
  const state = user.personaState == 0 ? "Offline" : user.personaState == 1 ? "Online" : "Busy";
  text += `**State:** ${state}\n`;
  text += `${user.avatar.large}`;
  return text;
}

async function getGamesString(steamID) {
  const user = await steam.getUserSummary(steamID);
  const games = await steam.getUserOwnedGames(steamID);
  const recentGames = [];
  
  for (let i = 0; i < games.length; i++) {
    recentGames.push({
        name: games[i].name,
        playTime: Math.round(games[i].playTime / 60)
    });
  }

  recentGames.sort((a, b) => {
      return b.playTime - a.playTime;
  });

  let text = `**Most played games for ${user.nickname}**\n\n**Total games:** ${games.length}\n`;
  for (let i = 0; i < 10; i++) {
    text += `**${i + 1}.** ${recentGames[i].name} - ${recentGames[i].playTime} hours\n`;
  }
  text += `${user.avatar.large}`;

  return text;
}

async function getFriendsString(steamID) {
  const user = await steam.getUserSummary(steamID);
  const friends = await steam.getUserFriends(steamID);
  const friendList = [];

  for (let i = 0; i < friends.length; i++) {
    friendList.push({
        steamID: friends[i].steamID,
        name: "",
        friendSince: friends[i].friendSince
    });
  }

  for (let i = 0; i < friendList.length; i++) {
    const friend = await steam.getUserSummary(friendList[i].steamID);

    if (friend.nickname != undefined)
      friendList[i].name = friend.nickname;
  }

  friendList.sort((a, b) => {
      return b.friendSince - a.friendSince;
  });

  let text = `**Friends of ${user.nickname}**\n\n**Total friends:** ${friends.length}\nHere are the 10 newest friends:\n\n`;
  for (let i = 0; i < 10; i++) {
    text += `**${i + 1}.** ${friendList[i].name}\n`;
  }
  text += `${user.avatar.large}`;

  return text;
}

async function steamAction(action, dataUser) {
  try {
    const actions = {
      "friends" : getFriendsString,
      "games" : getGamesString,
      "stats" : getStatsString
    }

    const data = await actions[action.type](action.values[0]);

    return await sendToPlatform(action.platform.service, data, action.platform.values, dataUser);
  } catch (err) {
    console.log("Error:", err);
    return false;
  }
}

export { steamAction };