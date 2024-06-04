# Firebase

## Introduction

Ce document explique comment Trombarea utilise Firebase pour stocker les données des utilisateurs ainsi que les déclencheurs et actions associés. Firebase est une plateforme de développement d'applications mobiles et web qui offre un service de base de données en temps réel, Firestore.

## Configuration Firebase

Pour accéder aux données Firebase, nous devons d'abord configurer l'accès à la base de données. Pour ce faire, nous devons créer un compte Firebase et un projet Firebase. Une fois le projet créé, nous pouvons accéder à la console Firebase et créer une base de données Firestore. Nous pouvons ensuite configurer l'accès à la base de données en utilisant les informations fournies par Firebase. Cette configuration est réalisée dans le fichier firebase.js.

```javascript
import firebase from 'firebase/compat/app';
import 'firebase/compat/firestore';
import dotenv from 'dotenv';

dotenv.config();

const firebaseConfig = {
  apiKey: process.env.FIREBASE_API_KEY,
  authDomain: process.env.FIREBASE_AUTH_DOMAIN,
  projectId: process.env.FIREBASE_PROJECT_ID,
};

firebase.initializeApp(firebaseConfig);
const db = firebase.firestore();

export { db };

```

## Structure de la base de données

La base de données Firestore est une base de données NoSQL. Elle est composée de collections qui contiennent des documents. Chaque document est composé de champs et de valeurs.
Notre base de données est composé de 2 collections : users et applets. 

### Collection users

La collection users contient les informations des utilisateurs de l'application ainsi que celle renseignées par l'utilisateur tels que des webhooks, sa localisation, etc. Chaque document de la collection users est identifié par l'uuid de l'utilisateur.


```js
{
  "discordWebhook": "",
  "location": {
    "_latitude": 43.611015,
    "_longitude": 3.877171
  },
  "slackWebhook": "",
  "teamsWebhook": "",
  "telegramWebhook": ""
}
```

### Collection applets

La collection applets contient les triggers et actions que les utilisateurs ont créés. Chaque document de la collection applets est identifié par un identifiant unique.

```js
{
  "action": {
      "service": "crypto",
      "type": "default",
      "values": {
        0: "bitcoin"
      },
      "platform": {
        "service": "discord",
        "type": "sendTo"
        "values": {
          0: "https://discord.com/api/webhooks/..."
        }
      }
    },
    "active": false,
    "createTime": {
      "_nanoseconds": 0,
      "_seconds": 1671416400
    },
    "favoritesCounter": 15,
    "oneshot": false,
    "public": true,
    "title": "Receive bitcoin price every day",
    "trigger": {
      "service": "time",
      "type": "default",
      "values": {
        0: "18:00:00"
      }

    },
    "userUid": "qFcA0tlR4ufZGqqz45ieWaAibLI2"
  }
}
```

Par exemple, l'applet si dessus est composé d'un trigger de type time qui s'active tous les jours à 18h et d'une action qui envoie les informations de la crypto-monnaie bitcoin sur le webhook discord de l'utilisateur.