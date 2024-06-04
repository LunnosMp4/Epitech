import fetch from 'node-fetch';

const extractImageUrls = (text) => {
  const imageUrlRegex = /(https?:\/\/\S+\.(?:png|jpg|jpeg|gif|webp|bmp|svg|tiff|ico))/gi;
  const imageUrls = text.match(imageUrlRegex);

  return imageUrls || [];
};

async function sendTextToDiscord(text, webhookUrl) {
  const color = Math.floor(Math.random()*16777215).toString(16);
  
  const imageUrls = extractImageUrls(text);

  try {
    const payload = {
      "content": null,
      "embeds": [
        {
          "title": "Trombarea",
          "description": "",
          "color": parseInt(color, 16),
          "timestamp": new Date().toISOString(),
          "fields": []
        }
      ],
      "attachments": []
    };

    if (imageUrls.length == 1) {
      payload.embeds[0].thumbnail = {
        "url": imageUrls[0]
      };
      text = text.replace(imageUrls[0], '');
    }

    payload.embeds[0].fields.push({
      "name": "Here your datas :",
      "value": "‎\n" + text,
    });

    const response = await fetch(webhookUrl, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(payload),
    });

    if (response.ok) {
      console.log('Message sent successfully to Discord.');
      return true;
    } else {
      console.error('Failed to send message to Discord:', response.status, response.statusText);
      return false;
    }
  } catch (error) {
    console.error('Error sending message to Discord:', error.message);
    return false;
  }
}

async function discordAction(action, dataUser) {
  try {
    var webhook;

    if (length(action.values) < 2)
      webhook = dataUser.discordWebhook;
    else
      webhook = action.values[1];

    return await sendTextToDiscord(action.values[0], webhook);
  } catch (err) {
    console.log("Error:", err);
    return false;
  }
}

export { sendTextToDiscord, discordAction };