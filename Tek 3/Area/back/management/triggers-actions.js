import { weatherAction } from '../services/type/weather/weatherAPI.js';
import { cryptoAction } from '../services/type/crypto/cryptoAPI.js';
import { getWeatherTriggerCond } from '../services/type/weather/weather-trigger.js'
import { getTimeCond } from '../services/type/time/time-trigger.js';
import { deleteDoc, updateActiveField, updateActionParameter } from './collections.js';
import { sendToPlatform } from '../services/platform/sendToPlatform.js';
import { checkAPI, checkBlackList } from './blackList-api.js'
import { blackList, apiTimers } from '../app.js';
import { getTriggerType } from '../about/getAbout.js'
import { getCollection } from './collections.js';
import { openEpitechDoor } from '../services/type/epitech-doors/epitech-doors-action.js';
import { lolAction } from '../services/type/lol/lol-action.js';
import { cocktailAction } from '../services/type/cocktail/cocktail-action.js';
import { fortniteAction } from '../services/type/fortnite/fortnite-action.js';
import { steamAction } from '../services/type/steam/steam-action.js';
import { factAction } from '../services/type/fact/fact-action.js';
import { getSpotifyTriggerCond } from '../services/type/spotify/spotify-trigger.js';
import { addMusicToPlayList } from '../services/type/spotify/spotify-action.js';
import { discordAction } from '../services/platform/discord/discord-action.js';

// Tous les types de trigger
const triggerTypes = await getTriggerType();

async function checkTrigger(appletsCollection, usersList) {
  // Parcours les éléments de la liste des triggers

  appletsCollection = await getCollection("applets");
  for (const applet of appletsCollection) {

    const user = usersList.find(obj => obj.id === applet.userUid);

    if (applet.active && await conditionTo(applet.trigger.service, applet.trigger.type, applet.trigger.values, user)) {
      // Si un trigger est trouvé il lance son action
      await findAction(applet, applet.trigger, usersList);
    }
  }
}

function sendTo(action, currentUser) {
  if (!blackList.some(element => element[0] === action.type)) {
    if (action.service === "weather")
      return weatherAction(action, currentUser);
    else if (action.service === "crypto")
      return cryptoAction(action, currentUser);
    else if (action.service === "lol")
      return lolAction(action, currentUser);
    else if (action.service === "cocktail")
      return cocktailAction(action, currentUser);
    else if (action.service === "fortnite")
      return fortniteAction(action, currentUser);
    else if (action.service === "steam")
      return steamAction(action, currentUser);
    else if (action.service === "fact")
      return factAction(action, currentUser);
    else if (action.service === "discord")
      return discordAction(action, currentUser);
  }
  return false;
}

async function openDoor(action) {
  if (!blackList.some(element => element[0] === action.service)) {
    const doorsList = ["HUB", "4eme", "Foyer", "Meetup", "SM1", "SM2", "Stream", "Admissions", "Incubateur"];
    if (doorsList.includes(action.values[0])) {
      var currentDate = new Date();
      apiTimers[apiTimers.findIndex(item => item[0] === action.service)][2] += 1;
      apiTimers[apiTimers.findIndex(item => item[0] === action.type)][3] = currentDate.getTime() + apiTimers[apiTimers.findIndex(item => item[0] === action.type)][1];
      return await openEpitechDoor(action.values[0]);
    }
  }
  return false;
}

async function findAction(uniqueApplet, uniqueTrigger, usersList) {
  const promises = [];

  for (const [index, action] of uniqueApplet.action.entries()) {
    checkAPI();
    checkBlackList();
    if (action.platform.type === "sendTo") {
      promises.push(sendTo(action, usersList.find(obj => obj.id === uniqueApplet.userUid)));
    } else if (action.type === "openDoor")
      promises.push(openDoor(action));
    else if (action.type === "musicPlayList") {
      promises.push(addMusicToPlayList(action.values[0], action.values[1], action.values[2], uniqueApplet.userUid));
    }
    await sleep(500);
  }
  const results = await Promise.all(promises);

  if (uniqueApplet.oneShot && results.some(result => result === true))
    await updateActiveField('applets', uniqueApplet.id, 'active', false);
}

async function conditionTo(service, type, values, user) {
  if (service === "time") {
    return getTimeCond(type, values);
  } else if (service === "weather") {
    return await getWeatherTriggerCond(type, values, user);
  } else if (service === "spotify") {
    return await getSpotifyTriggerCond(user.id);
  }
  return false;
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

export { checkTrigger, findAction, conditionTo, deleteDoc };