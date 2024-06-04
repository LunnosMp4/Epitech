import { getWeatherData } from './weather-action.js';
import { blackList, apiTimers } from '../../../app.js';

// Vérifie la validité des paramètres des triggers de type: météo
async function getWeatherTriggerCond(type, values, user) {
  const st = weatherTrigger(type, values, user).then(result => result);
  if (st) {
    const index = apiTimers.findIndex(item => item[0] === "getWeather");
    var currentDate = new Date();
    apiTimers[index][2] += 1;
    apiTimers[index][3] = currentDate.getTime() + apiTimers[index][1];
  }
  return st;
}

// Vérifie si le paramètre demandé est le même que le temps actuel envoyé en paramètre
async function weatherTrigger(type, values, user) {
  if (blackList.includes("getWeather"))
    return false;
  var status = [];

  const data = await getWeatherData(user.location._lat, user.location._long);

  if (type == "weatherCondition") {
    const main = data.weather[0].main.toLowerCase();
    console.log("current weather:", main);
    status.push(main === values[0].toLowerCase());
  }

  if (type == "temperature") {
    const operators = {
      "<": (a, b) => a < b,
      ">": (a, b) => a > b,
      "=": (a, b) => a === b,
      "<=": (a, b) => a <= b,
      ">=": (a, b) => a >= b
    };

    const [operator, value] = values[0].match(/([^\d]+)(\d+)/).slice(1);
    const temp = (parseInt(data.main.temp)) - 273.15;

    status.push(operators[operator](temp, value));
  }
  return status.every((value) => value === true);
}

export { getWeatherTriggerCond, weatherTrigger };