import fetch from 'node-fetch';

async function sendTextToTeams(message, slackWebhookUrl) {
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
    throw new Error(`Failed to send message to Microsoft Teams. Status: ${response.status}`);
    console.log('Message sent successfully to Microsoft Teams!');
  } catch (error) {
    console.error('Error sending message to Microsoft Teams:', error.message);
  }
}

export { sendTextToTeams };