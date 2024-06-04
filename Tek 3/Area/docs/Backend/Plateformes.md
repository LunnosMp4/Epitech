# Plateformes

## Ajouter une plateforme

Pour ajouter une nouvelle plateforme à l'application IFTTT, suivez les étapes suivantes :

1. Créez un fichier JavaScript pour votre nouvelle plateforme dans le dossier `platforms` (par exemple, `slack.js` pour une plateforme Slack). Assurez-vous que ce fichier expose les fonctions nécessaires pour interagir avec cette plateforme.

2. Dans le fichier de votre nouvelle plateforme, développez des fonctions pour interagir avec cette plateforme. Ces fonctions doivent effectuer des actions spécifiques, telles que l'envoi de messages. Respectez aussi le nommage des fonctions pour une meilleure lisibilité. Pour slack nous utilisons la convention suivante : `sendTextToSlack()`.<br><br>
Voici un exemple de fichier de plateforme :

```javascript
import fetch from 'node-fetch';

async function sendTextToSlack(message, slackWebhookUrl) {
  try {
    const response = await fetch(slackWebhookUrl, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({
        text: message,
      }),
    });

    if (!response.ok)
      throw new Error(`Failed to send message to Slack. Status: ${response.status}`);
    console.log('Message sent successfully to Slack!');
  } catch (error) {
    console.error('Error sending message to Slack:', error.message);
  }
}

export { sendTextToSlack };
```

3. Intégrez votre nouvelle plateforme dans la fonction `sendToPlatform` (dans le fichier `sendToPlatform.js`). Ajoutez un cas pour votre nouvelle plateforme et appelez la fonction appropriée pour effectuer l'action souhaitée.<br><br>
Voici un exemple de la fonction sendToPlatform :
    
```javascript
    async function sendToPlatform(selectedPlatform, value, platformData, dataUser) {
      switch (selectedPlatform) {
        case "slack":
        return sendTextToSlack(value, platformData.webhook);
        // Ajoutez d'autres cas pour vos plateformes ici
        default:
        return false;
      }
    }
    export { sendToPlatform };
```

4. Pour ajouter votre nouvelle plateforme à la liste des plateformes disponibles dans l'application, il vous faudra modifier le fichier `about.json`, celui ci permet de communiquer avec le front et liste la totalité des plateformes mais également des déclencheurs et actions ainsi que leurs parametre, pour notre cas il vous suffit d'ajouter la nouvelle plateforme comme ceci :

```javascript
"server": {
  "services": [
  {
    "name": "slack",
    "actions": [{
      "name": "",
      "description": ""
    }],
    "reactions": [
      {
        "name": "sendTo",
        "description": "Send a message to a Slack channel",
        "parameters": [
          {
            "type": "string",
            "value": "webhook url",
            "exemples": "https://hooks.slack.com/services/..."
          }
        ]
      }
    ]
    [...]
    ]
  },
  [...]
  ]
}
```

5. Et voilà ! Vous avez ajouté une nouvelle plateforme à Trombarea !