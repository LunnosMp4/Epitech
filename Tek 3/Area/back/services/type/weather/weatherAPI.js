import { getWeatherData, getWeatherString } from './weather-action.js';
import { sendToPlatform } from '../../platform/sendToPlatform.js';
import { blackList, apiTimers } from '../../../app.js';

// Vérifie si l'API OpeWweatherMap n'est pas déjà dans la blackListe et son état d'utilisation
function checkGetWeathersAPI(index, type, counter, timestamp) {
  if (type === "getWeather" && !blackList.includes("getWeather")) {
    const currentTime = new Date();
    if (counter >= 10) {
      blackList.push(["getWeather", currentTime.getTime() + apiTimers[index][1]]);
      apiTimers[index][2] = 0;
      apiTimers[index][3] = 0;
    }
    else if (currentTime - timestamp >= 30000) {
      apiTimers[index][2] = 0;
      apiTimers[index][3] = 0;
    }
  }
}

async function weatherAction(action, dataUser) {
  try {
    // Prends les données d'une api qui donne le temps
    const data = await getWeatherData(dataUser.location._lat, dataUser.location._long);

    // Prends le temps à l'instant T pour savoir quand l'action s'est passé
    var currentDate = new Date();
    apiTimers[0][2] += 1;
    apiTimers[0][3] = currentDate.getTime() + apiTimers[0][1];

    // Utilise directement await ici
    return await sendToPlatform(action.platform.service, getWeatherString(data), action.values, dataUser);
  } catch (err) {
    console.log("Error:", err);
    return false;
  }
}

export { weatherAction, checkGetWeathersAPI };