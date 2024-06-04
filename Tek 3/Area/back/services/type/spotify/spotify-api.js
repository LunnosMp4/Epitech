import { db } from '../../../firebase/firebase.js';
import fetch from 'node-fetch';
import axios from 'axios';

async function verifyAndRefreshToken(accessToken, refreshToken) {
	try {
		const response = await fetch('https://api.spotify.com/v1/me', {
			headers: {
			'Authorization': `Bearer ${accessToken}`
			}
		});

		if (response.ok) {
			return { accessToken, isValid: true };
		} else {
			const refreshResponse = await fetch('/refresh_token', {
				method: 'POST',
				headers: {
						'Content-Type': 'application/json'
				},
				body: JSON.stringify({ refreshToken })
			});

			const data = await refreshResponse.json();

			if (refreshResponse.ok) {
				return { accessToken: data.accessToken, isValid: true };
			} else {
				return { accessToken: null, isValid: false };
			}
		}
	} catch (error) {
		console.error('An error occurred:', error);
		return { accessToken: null, isValid: false };
	}
}

async function getPlaylistIdByName(playlistName, accessToken) {
	try {
			const response = await axios.get('https://api.spotify.com/v1/me/playlists', {
					headers: {
							'Authorization': 'Bearer ' + accessToken
					}
			});
			const playlists = response.data.items;
			const playlist = playlists.find(p => p.name === playlistName);
			return playlist ? playlist.id : null;
	} catch (error) {
			console.error('Erreur lors de la récupération de l\'ID de la playlist:', error);
			throw error;
	}
}

async function getTrackUriByNameAndArtist(trackName, artistName, accessToken) {
	try {
			const response = await axios.get(`https://api.spotify.com/v1/search`, {
					headers: {
							'Authorization': 'Bearer ' + accessToken
					},
					params: {
							q: `${trackName} artist:${artistName}`,
							type: 'track',
							limit: 1
					}
			});
			const tracks = response.data.tracks.items;
			return tracks.length > 0 ? tracks[0].uri : null;
	} catch (error) {
			console.error('Erreur lors de la récupération de l\'URI de la piste:', error);
			throw error;
	}
}

async function getCollectionData(collection, username, data_name) {
  const myCollection = db.collection(collection);
  const documentRef = myCollection.doc(username);
  const docSnapshot = await documentRef.get();

  if (docSnapshot.exists) {
    const data = docSnapshot.data();
    return data[data_name] || null;
  } else {
    return null;
  }
}

async function updateCollectionData(collection, username, data_name, newValue) {
  const myCollection = db.collection(collection);
  const documentRef = myCollection.doc(username);

  try {
    await documentRef.update({
      [data_name]: newValue
    });
    return true;
  } catch (error) {
    console.error("Erreur lors de la mise à jour du document:", error);
    return false;
  }
}

export { verifyAndRefreshToken, getPlaylistIdByName, getTrackUriByNameAndArtist, getCollectionData, updateCollectionData};