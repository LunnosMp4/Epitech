import { blackList, apiTimers } from '../../../app.js';

export function checkOpenDoorAPI(index, type, counter, timestamp) {
  if (type === "openDoor" && !blackList.includes("openDoor")) {
    const currentTime = new Date();
    if (counter >= 5) {
      blackList.push(["openDoor", currentTime.getTime() + apiTimers[index][1]]);
      apiTimers[index][2] = 0;
      apiTimers[index][3] = 0;
    }
    else if (currentTime - timestamp >= 30000) {
      apiTimers[index][2] = 0;
      apiTimers[index][3] = 0;
    }
  }
}