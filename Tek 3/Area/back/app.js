import express from 'express';
import dotenv from 'dotenv';

import { getCollection } from './management/collections.js';
import { checkTrigger } from './management/triggers-actions.js';
import { checkBlackList, checkAPI } from './management/blackList-api.js';
import { getAbout, updateAbout } from './about/getAbout.js';

import { updateCollectionData } from './services/type/spotify/spotify-api.js'

import { getToken, getCollectionData } from './services/type/twitter/twitter-api.js';

import cors from 'cors';
import axios from 'axios';
import querystring from 'querystring';
import { Buffer } from 'buffer';

const app = express();

app.use(cors());

// Port utilisé
const port = 8080;

// Import utilisé pour avoir les données du .env
dotenv.config();

let isProcessing = false;

var apiTimers = await getAbout();

// Black liste des api
var blackList = [];

// Vérifie toutes les secondes si une collection a été mise à jour agit en conséquence
setInterval(async () => {
  // Si la boucle est en cours d'exécution, ne faites rien
  if (isProcessing) {
    return;
  }

  try {
    // Marquer la boucle comme en cours d'exécution
    isProcessing = true;

    // Mets à jour les collections
    var appletsCollection = await getCollection("applets");
    var usersCollection = await getCollection("users");

    // Vérifie l'état des api et si une d'elle doit aller dans la blackList
    checkAPI();

    // Vérifie si un élément de la blackList doit être enlevé
    checkBlackList();
    // Vérifie si une action est à faire
    await checkTrigger(appletsCollection, usersCollection);

  } catch (error) {
    console.error("Erreur:", error);
  } finally {
    // Marquer la boucle comme terminée
    isProcessing = false;
  }
}, 1000);

app.get('/about.json', async (req, res) => {
  try {
    const data = await updateAbout(req);
    res.json(data);
  } catch (error) {
    console.error(`Une erreur est survenue : ${error.message}`);
    res.status(500).json({ error: 'Une erreur est survenue lors de la lecture ou de la mise à jour du fichier JSON.' });
  }
});

app.get('/spotify_callback', async (req, res) => {
  const username = req.query.state || null;
  const code = req.query.code || null;
  if (code) {
    try {
      const response = await axios({
        method: 'post',
        url: 'https://accounts.spotify.com/api/token',
        data: querystring.stringify({
          code: code,
          redirect_uri: process.env.SPOTIFY_REDIRECT_URI,
          grant_type: 'authorization_code'
        }),
        headers: {
          'Content-Type': 'application/x-www-form-urlencoded',
          'Authorization': 'Basic ' + (Buffer.from(process.env.SPOTIFY_CLIENT_ID + ':' + process.env.SPOTIFY_CLIENT_SECRET).toString('base64'))
        }
      });
      updateCollectionData("users", username, "spotifyExistingAccessToken", response.data.access_token);
      updateCollectionData("users", username, "spotifyRefreshToken", response.data.refresh_token);
      res.redirect('https://open.spotify.com/intl-fr');
    } catch (error) {
      console.error('Erreur lors de la récupération du token ou des données:', error);
    }
  } else {
    res.redirect('/#/error/invalid_token');
  }
});

app.get('/twitter_callback', async (req, res) => {
	const error = req.query.error;

  if (error) {
    console.log(`Erreur d'authentification: ${req.query.error_description}`);
  }
  const username = req.query.state;
  const code = req.query.code;

  if (code) {
    try {
      const codeVerif = getCollectionData("users", username, "twitterCodeVerifier");
      const tokenData = await getToken(code, codeVerif);
      updateCollectionData("users", username, "twitterExistingAccessToken", tokenData.access_token);
      updateCollectionData("users", username, "twitterRefreshToken", tokenData.refresh_token);
      res.redirect('https://twitter.com/home');
    } catch (error) {
      console.error('Erreur :', error);
    }
  }
});

// Lance l'api sur le port spécifié
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});

export { blackList,apiTimers  };