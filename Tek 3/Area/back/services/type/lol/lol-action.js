import fetch from 'node-fetch';
import dotenv from 'dotenv';

import { sendToPlatform } from '../../platform/sendToPlatform.js';

dotenv.config();

function goodUserName(userName) {
  const resultString = userName.replace(/ /g, '%20');
  return resultString;
}


function setAll(data1, data2, data3, profIconId) {
  const iconUrl = "https://ddragon.leagueoflegends.com/cdn/13.20.1/img/profileicon/" + profIconId + ".png";
  const winPercentageSoloQ = (data3[0].wins * 100) / (data3[0].wins + data3[0].losses);
  const winPercentageFlex = (data3[1].wins * 100) / (data3[1].wins + data3[1].losses);
  const fullData = `${iconUrl}Name: ${data1.name}\nLevel: ${data1.summonerLevel}\nRegion: ${data2.tagLine}\n\nSoloQ\nRank: ${data3[0].tier} ${data3[0].rank}\nWinrate: ${winPercentageSoloQ.toFixed(0)}%\n\nFlex\nRank: ${data3[1].tier} ${data3[1].rank}\nWinrate: ${winPercentageFlex.toFixed(0)}%\n`;
  return fullData;
}

async function getLolString(userName) {
  try {
    const api_key = process.env.LOL_API_KEY;

    const account_url = "https://euw1.api.riotgames.com/lol/summoner/v4/summoners/by-name/" + goodUserName(userName);
    const puid_url = "https://europe.api.riotgames.com/riot/account/v1/accounts/by-puuid/";
    const profil_url = "https://euw1.api.riotgames.com/lol/league/v4/entries/by-summoner/"

    const response1 = await fetch(account_url + `?api_key=${api_key}`);
    if (response1.status === 200) {
      const data1 = await response1.json();
      const response2 = await fetch(puid_url + `${data1.puuid}` + `?api_key=${api_key}`);
      if (response2.status === 200) {
        const data2 = await response2.json();
        const response3 = await fetch(profil_url + `${data1.id}` + `?api_key=${api_key}`);
        if (response3.status === 200) {
          const data3 = await response3.json();
          return setAll(data1, data2, data3, data1.profileIconId);
        } else {
          throw new Error(`Erreur ${response3.status}: Impossible d'obtenir les données du joueur.`);
        }
      } else {
        throw new Error(`Erreur ${response2.status}: Impossible d'obtenir les données du joueur.`);
      }
    } else {
      throw new Error(`Erreur ${response1.status}: Impossible d'obtenir les données du joueur.`);
    }
  } catch (error) {
    console.error(error.message);
  }
}

async function lolAction(action, dataUser) {
  try {
    // Prends les données d'une api qui donne le temps
    const data = await getLolString(action.values[0]);

    // Utilise directement await ici
    return await sendToPlatform(action.platform.service, data, action.platform.values, dataUser);
  } catch (err) {
    console.log("Error:", err);
    return false;
  }
}

export { lolAction };