import axios from 'axios';

async function getToken(authCode, codeVerifier) {
	const params = new URLSearchParams();
	params.append('code', authCode);
	params.append('grant_type', 'authorization_code');
	params.append('client_id', process.env.TWITTER_CLIENT_ID);
	params.append('redirect_uri', process.env.TWITTER_REDIRECT_URI);
	params.append('code_verifier', codeVerifier);

	try {
		const response = await axios.post('https://api.twitter.com/2/oauth2/token', params.toString(), {
			headers: {
				'Content-Type': 'application/x-www-form-urlencoded'
			}
		});

		return response.data;
	} catch (error) {
	  console.log('Error here :', error);
	}
}

async function getCollectionData(collection, username, data_name) {
  const myCollection = db.collection(collection);
  const documentRef = myCollection.doc(username);

  try {
    const doc = await documentRef.get();
    if (doc.exists) {
      return doc.data()[data_name];
    } else {
      console.error("Document n'existe pas!");
      return null;
    }
  } catch (error) {
    console.error("Erreur lors de la récupération du document:", error);
    return null;
  }
}

async function fetchData(accessToken, link) {
	try {
		const response = await axios.get(link, {
			headers: {
					'Authorization': `Bearer ${accessToken}`
			}
		});

		return response.data;
	} catch (error) {
		console.error('Erreur lors de la récupération des données de {link}:', error);
		throw error;
	}
}

export { getToken, getCollectionData };