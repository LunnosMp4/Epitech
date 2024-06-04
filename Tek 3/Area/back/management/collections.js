import { db } from '../firebase/firebase.js';

async function updateActionParameter(collection, id, actionIndex, parameterName, parameterValue) {
  const documentRef = db.collection(collection).doc(id.toString());

  try {
    const documentSnapshot = await documentRef.get();
    if (!documentSnapshot.exists) {
      throw new Error('Document does not exist');
    }

    const data = documentSnapshot.data();
    if (!data || !Array.isArray(data.action) || actionIndex < 0 || actionIndex >= data.action.length) {
      throw new Error('Invalid data or action index');
    }

    const updatedAction = [...data.action];
    updatedAction[actionIndex].parameters.data.done.current = parameterValue; // Modifiez le paramètre

    // Mettez à jour le champ action dans le document Firestore avec le tableau mis à jour
    await documentRef.update({ action: updatedAction });

    console.log(`Paramètre "${parameterName}" mis à jour avec succès à ${parameterValue}`);
  } catch (error) {
    console.error(`Erreur lors de la mise à jour du paramètre "${parameterName}" :`, error);
  }
}

// Importe une collection de Cloud Firebase
async function getCollection(collection) {
  const myCollection = db.collection(collection);
  const querySnapshot = await myCollection.get();

  const myData = [];
  querySnapshot.forEach((doc) => {
    myData.push({
      id: collection != "users" ? parseInt(doc.id, 10) : doc.id,
      ...doc.data()
    });
  });
  return myData;
}
// Mets à jour le document passé en paramètre
async function updateField(collection, id, fieldName, fieldValue) {
  const documentRef = db.collection(collection).doc(id.toString());

  const updateData = {};
  updateData[fieldName] = fieldValue;

  await documentRef.update(updateData)
    .then(() => {
      console.log(`Champ "${fieldName}" mis à jour avec succès à ${fieldValue}`);
    })
    .catch((error) => {
      console.error(`Erreur lors de la mise à jour du champ "${fieldName}" :`, error);
    });
}

async function updateActiveField(collection, id, fieldName, fieldValue) {
  try {
    await updateField(collection, id, fieldName, fieldValue);
    console.log(`Mise à jour du champ "${fieldName}" terminée avec succès.`);
  } catch (error) {
    console.error(`Erreur lors de la mise à jour du champ "${fieldName}":`, error);
  }
}

// Supprime le document passé en paramètre
function deleteDoc(id) {
  db.collection("applets").doc(id.toString()).delete().then(() => {
    console.log("Document successfully deleted!");
  }).catch((error) => {
    console.error("Error removing document: ", error);
  });
}

export { getCollection, deleteDoc, updateField, updateActiveField, updateActionParameter };