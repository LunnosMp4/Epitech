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