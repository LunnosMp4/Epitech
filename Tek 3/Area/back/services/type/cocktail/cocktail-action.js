import fetch from 'node-fetch';
import dotenv from 'dotenv';

import { sendToPlatform } from '../../platform/sendToPlatform.js';

dotenv.config();

async function getCocktailString(alcool) {
  const apiUrl = 'https://the-cocktail-db.p.rapidapi.com/filter.php?i=' + alcool;
  const apiKey = process.env.COCKTAIL_API_KEY;
  const options = {
    method: 'GET',
    headers: {
      'X-RapidAPI-Key': apiKey,
      'X-RapidAPI-Host': 'the-cocktail-db.p.rapidapi.com'
    }
  };

  try {
    const response = await fetch(apiUrl, options);

    if (response.status === 200) {
      const data = await response.json();
      number = 10;
      var fullData = "";
      for (let i = 0; i < number; i++) {
        const drink = data.drinks[i];
        fullData += `\n\n${drink.strDrink}\n${drink.strDrinkThumb}`;
      }
      fullData = fullData.slice(1);
      return fullData;
    } else {
      throw new Error(`Erreur ${response.status}: Impossible d'obtenir les données.`);
    }
  } catch (error) {
    console.error(error.message);
    throw error;
  }
}

async function cocktailAction(action, dataUser) {
  try {
    const data = await getCocktailString(action.values[0]);

    // Utilise directement await ici
    return await sendToPlatform(action.platform.service, data, action.platform.values, dataUser);
  } catch (err) {
    console.log("Error:", err);
    return false;
  }
}

export { cocktailAction };