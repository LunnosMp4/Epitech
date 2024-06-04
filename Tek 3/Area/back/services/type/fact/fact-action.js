import fetch from 'node-fetch';

import { sendToPlatform } from '../../platform/sendToPlatform.js';

async function getFactString() {
  try {
    const url = `https://uselessfacts.jsph.pl/api/v2/facts/random?language=en`;
    const response = await fetch(url, {
      method: 'GET',
      headers: {
        'Content-Type': 'application/json',
      },
    });

    console.log(response);

    const data = await response.json();

    console.log(data.text);

    return data.text;
  } catch (error) {
    console.error('Error processing useless facts API:', error);
    return false;
  }
}

async function factAction(action, dataUser) {
  try {
    const data = await getFactString();

    return await sendToPlatform(action.platform.service, data, action.platform.values, dataUser);
  } catch (err) {
    console.log("Error:", err);
    return false;
  }
}

export { factAction, getFactString };