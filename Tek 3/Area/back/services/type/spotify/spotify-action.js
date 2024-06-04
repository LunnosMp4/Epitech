import { getCollectionData, verifyAndRefreshToken, getPlaylistIdByName, getTrackUriByNameAndArtist, updateCollectionData } from './spotify-api.js';
import axios from 'axios';

async function addMusicToPlayList(musicName, artistName, playListName, username) {
	const existingAccessToken = await getCollectionData("users", username, "spotifyExistingAccessToken");
	const refreshToken = await getCollectionData("users", username, "spotifyRefreshToken");
	if (existingAccessToken && refreshToken) {
    console.log("YES");
		const result = await verifyAndRefreshToken(existingAccessToken, refreshToken);
		if (result.isValid && existingAccessToken != result.accessToken) {
			updateCollectionData("users", username, "spotifyExistingAccessToken", result.accessToken);
			existingAccessToken = result.accessToken;
		}
		try {
      const playlistId = await getPlaylistIdByName(playListName, existingAccessToken);
      if (!playlistId)
        return console.log("Playlist non trouvée.");

      const trackUri = await getTrackUriByNameAndArtist(musicName, artistName, existingAccessToken);
      if (!trackUri)
        return console.log("Piste non trouvée.");

      await axios({
        method: 'post',
        url: `https://api.spotify.com/v1/playlists/${playlistId}/tracks`,
        data: {
            uris: [trackUri]
        },
        headers: {
            'Authorization': 'Bearer ' + existingAccessToken,
            'Content-Type': 'application/json'
        }
      });
      console.log("{play_list_name} Added");
      return true;
		} catch (error) {
			console.error('Erreur lors de l\'ajout de la piste à la playlist:', error);
		}
	}
	return false;
}

export { addMusicToPlayList };