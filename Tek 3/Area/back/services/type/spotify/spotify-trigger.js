import { verifyAndRefreshToken, getPlaylistIdByName, getTrackUriByNameAndArtist, getCollectionData, updateCollectionData} from './spotify-api.js';
import axios from 'axios';

var lastMusic = null;

async function getSpotifyTriggerCond(user) {
	var newMusic = null;
	const existingAccessToken = await getCollectionData("users", user, "spotifyExistingAccessToken");
	const refreshToken = await getCollectionData("users", user, "spotifyRefreshToken");
	if (existingAccessToken && refreshToken) {
		const result = await verifyAndRefreshToken(existingAccessToken, refreshToken);
		if (result.isValid && existingAccessToken != result.accessToken) {
			updateCollectionData("users", user, "spotifyExistingAccessToken", result.accessToken);
			existingAccessToken = result.accessToken;
		}
		const recentlyPlayed = await axios({
			method: 'get',
			url: 'https://api.spotify.com/v1/me/player/recently-played',
			headers: {
					'Authorization': 'Bearer ' + existingAccessToken
			}
		});

		newMusic = recentlyPlayed.data.items[0].track;
	}
	if (lastMusic && newMusic && lastMusic != newMusic)
			return true;
	return false;
}

export { getSpotifyTriggerCond };