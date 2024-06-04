import fs from 'fs';
import util from 'util';

const readFileAsync = util.promisify(fs.readFile);

async function getTriggerType() {
  try {
    const data = await readFileAsync('about/about.json', 'utf8');
    const jsonData = JSON.parse(data);

    if (jsonData && jsonData.server && jsonData.server.services && Array.isArray(jsonData.server.services)) {
      const servicesList = jsonData.server.services;

      const actionNamesList = [];

      for (const service of servicesList) {
        if (service.actions && Array.isArray(service.actions)) {
          for (const action of service.actions) {
            if (action.name && action.name !== "") {
              actionNamesList.push(action.name);
            }
          }
        }
      }

      return actionNamesList;
    } else {
      throw new Error('Le fichier JSON ne contient pas les données attendues.');
    }
  } catch (error) {
    console.error(`Une erreur est survenue : ${error.message}`);
    throw error;
  }
}

async function updateAbout(req) {
  const readFileAsync = util.promisify(fs.readFile);
  const data = await readFileAsync('about/about.json', 'utf8');
  const jsonData = JSON.parse(data);

  if (jsonData.server.current_time) {
    var currentDate = new Date();
    jsonData.server.current_time = currentDate.getTime();
  }

  if (jsonData.client.host) {
    jsonData.client.host = req.ip;
  }

  return jsonData;
}

async function getAbout() {
  try {
    const data = await readFileAsync('about/about.json', 'utf8');
    const jsonData = JSON.parse(data);

    const results = [];

    if (jsonData && jsonData.server && jsonData.server.services && Array.isArray(jsonData.server.services)) {
      const servicesList = jsonData.server.services;

      for (const service of servicesList) {
        if (service.reactions && Array.isArray(service.reactions)) {
          for (const reaction of service.reactions) {
            if (reaction.time_to_add) {
              results.push([reaction.name, reaction.time_to_add, 0, 0]);
            }
          }
        }
      }

      return results;
    } else {
      throw new Error('Le fichier JSON ne contient pas les données attendues.');
    }
  } catch (error) {
    console.error(`Une erreur est survenue : ${error.message}`);
    throw error;
  }
}

export { getAbout, getTriggerType, updateAbout};