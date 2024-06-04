import { sendTextToDiscord } from './discord/discord-action.js';
import { sendTextToSlack } from './slack/slack-action.js';
import { sendTextToTeams } from './teams/teams-action.js';
import { sendTextToTelegram } from './telegram/telegram-action.js';
import { sendEmail } from './gmail/gmail-action.js';

async function sendToPlatform(selectedPlatform, text, values, dataUser) {
	switch (selectedPlatform) {
		case "discord":
         const webhookData = values[0] === "" ? dataUser.discordWebhook : values[0];
         return sendTextToDiscord(text, webhookData);
         break;
		case "mail":
         return sendEmail(text, dataUser.mail);
         break;
		case "slack":
         return sendTextToSlack(text, dataUser.slackWebhook);
         break;
		case "teams":
         return sendTextToTeams(text, dataUser.teamsWebhook);
         break;
		case "telegram":
         return sendTextToTelegram(text, dataUser.telegramWebhook);
         break;
		default:
         return false;
         break;
	}
}

export { sendToPlatform };