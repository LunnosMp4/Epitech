import fetch from 'node-fetch';
import dotenv from 'dotenv';

import { sendToPlatform } from '../../platform/sendToPlatform.js';

dotenv.config();

const toHours = (minutes) => {
  return (minutes / 60).toFixed(2);
}

const formatStats = (data, gameMode) => {
  if (data && data[gameMode]) {
    const stats = data[gameMode];

    return `**In ${gameMode} mode:**
    - Total Wins: ${stats.wins}
    - Total Kills: ${stats.kills}
    - K/D Ratio: ${stats.kd.toFixed(2)}
    - Win Rate: ${stats.winRate}%`;
  } else {
    return `No data available for ${gameMode} mode.`;
  }
};

async function getFortniteString(userName) {
  const headers = {
    Authorization: process.env.FORTNITE_API_KEY,
  };

  const apiUrlWithParams = `https://fortnite-api.com/v2/stats/br/v2?name=${userName}`;

  try {
    const response = await fetch(apiUrlWithParams, { headers });
    const playerData = await response.json();

    const overallStats = formatStats(playerData.data.stats.all, "overall");
    const soloStats = formatStats(playerData.data.stats.all, "solo");
    const duoStats = formatStats(playerData.data.stats.all, "duo");
    const squadStats = formatStats(playerData.data.stats.all, "squad");

    return `**Player:** ${playerData.data.account.name}\n**Battle Pass Level:** ${playerData.data.battlePass.level}\n**Total Playtime:** ${toHours(playerData.data.stats.all.overall.minutesPlayed)} hours\n\n${overallStats}\n${soloStats}\n${duoStats}\n${squadStats} https://upload.wikimedia.org/wikipedia/commons/7/7c/Fortnite_F_lettermark_logo.png`;
  } catch (error) {
    console.error(error);
    return "Error fetching player data.";
  }
}

async function fortniteAction(action, dataUser) {
  try {
      const data = await getFortniteString(action.values[0]);

      return await sendToPlatform(action.platform.service, data, action.platform.values, dataUser);
  } catch (err) {
      console.log("Error:", err);
      return false;
  }
}

export { fortniteAction, getFortniteString };