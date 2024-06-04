import { checkGetWeathersAPI } from '../services/type/weather/weatherAPI.js';

import { checkOpenDoorAPI } from '../services/type/epitech-doors/epitech-doors-API.js';

import { blackList, apiTimers } from '../app.js';

function checkAPI() {
  // Parcours les éléments de la liste et vérifie si chaque API disponible est utilisable ou non
  for (const elements of apiTimers) {
    let [type, , counter, timestamp] = elements;
    // Test toutes les API (ici une)
    checkGetWeathersAPI(apiTimers.findIndex(item => item[0] === type), type, counter, timestamp);
    checkOpenDoorAPI(apiTimers.findIndex(item => item[0] === type), type, counter, timestamp);
  }
}

// Vérifie si le temps de ban est égalé ou dépassé et agit en conséquence
function checkBlackList() {
  const currentDate = new Date();
  var index = 0;

  for (const elements of blackList) {
    if (elements[1] <= currentDate.getTime())
      blackList.splice(index, 1);
    index++;
  }
}

export { checkAPI, checkBlackList };