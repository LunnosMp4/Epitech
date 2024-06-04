import firebase from 'firebase/compat/app';
import 'firebase/compat/firestore';
import dotenv from 'dotenv';

// Import utilisé pour avoir les données du .env
dotenv.config();

// Configuration de l'accès du code aux données de Firebase
const firebaseConfig = {
  apiKey: process.env.FIREBASE_API_KEY,
  authDomain: process.env.FIREBASE_AUTH_DOMAIN,
  projectId: process.env.FIREBASE_PROJECT_ID,
};

firebase.initializeApp(firebaseConfig);
const db = firebase.firestore();

// Exportation la variable d'utilisation
export { db };