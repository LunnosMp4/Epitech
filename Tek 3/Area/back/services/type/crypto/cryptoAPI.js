import { getCryptoString } from "./crypto-action.js";
import { sendToPlatform } from '../../platform/sendToPlatform.js';

async function cryptoAction(action, dataUser) {
  try {
    // Prends les données d'une api qui donne le temps
    const data = await getCryptoString(action.values[0]);

    // Utilise directement await ici
    return await sendToPlatform(action.platform.service, data, action.platform.values, dataUser);
  } catch (err) {
    console.log("Error:", err);
    return false;
  }
}

export { cryptoAction };