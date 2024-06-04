import fetch from 'node-fetch';
import dotenv from 'dotenv';

dotenv.config();

async function sendTextToTelegram(message, chatId) {
  const botToken = process.env.TELEGRAM_BOT_TOKEN;
  try {
    const apiUrl = `https://api.telegram.org/bot${botToken}/sendMessage`;

    return fetch(apiUrl, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({
        chat_id: chatId,
        text: message,
      }),
    })
    .then(response => {
      if (!response.ok) {
        throw new Error(`Failed to send message to Telegram. Status: ${response.status}`);
      }
      console.log('Message sent successfully to Telegram!');
    })
  } catch (error) {
    console.error('Error sending message to Telegram:', error.message);
  }
}

export { sendTextToTelegram };