# Management

## Introduction

La gestion dans Trombarea englobe un ensemble de fonctionnalités essentielles pour gérer les données des utilisateurs, les déclencheurs/actions et les opérations de gestion courantes. Cette section de la documentation explique comment chaque composant est géré.

## Collection Firestore

Le fichier `collection.js` est un module qui fournit des fonctions pour la gestion des collections Firestore, y compris la mise à jour de champs, la récupération de collections et la suppression de documents. Voici quelques-unes de ses fonctions les plus importantes :

- `getCollection(collection)`: Cette fonction permet de récupérer les données d'une collection Firestore spécifique. Les données sont renvoyées sous forme de tableau.

- `updateField(collection, id, fieldName, fieldValue)`: Cette fonction met à jour un champ spécifique dans un document de la collection.

- `updateActiveField(collection, id, fieldName, fieldValue)`: Une version de updateField spécialement conçue pour la gestion des champs "actifs". Elle met à jour le champ "actif" d'un document.

- `updateActionParameter(collection, id, actionIndex, parameterName, parameterValue)`: Cette fonction est utilisée pour mettre à jour les paramètres d'une action dans un document. Elle est utilisée pour les actions spécifiques.

- `deleteDoc(id)`: Cette fonction supprime un document spécifié par son ID.

## Actions et déclencheurs

Le fichier `triggers-actions.js` gère l'exécution des actions associées aux déclencheurs dans l'application. Il utilise plusieurs autres fichiers pour exécuter des actions spécifiques en fonction des déclencheurs. Voici quelques points importants :

- `checkTrigger(appletsCollection, usersList)`: Cette fonction parcourt la liste des déclencheurs et exécute les actions associées en fonction des conditions.

- `sendTo(action, currentUser)`: Cette fonction envoie une action vers la plateforme ou le service approprié en fonction des paramètres.

- `openDoor(action)`: Une fonction spécifique pour ouvrir des portes dans le contexte de l'application.

- `findAction(uniqueApplet, uniqueTrigger, usersList)`: Cette fonction recherche et exécute les actions associées à un déclencheur unique.

- `conditionTo(type, parameters)`: Cette fonction vérifie les conditions pour décider si une action doit être exécutée.

- `sleep(ms)`: Une fonction utilitaire pour ajouter une pause dans l'exécution du code.

## Blacklist

Le fichier `blacklist.js` gère la liste noire des API et effectue des vérifications liées aux API. Voici comment il fonctionne :

- `checkAPI()`: Cette fonction vérifie la disponibilité de différentes API en fonction de la liste des API actives. En effet, certaines API nous sont limitées en termes de nombre de requêtes par minute. Cette fonction vérifie donc si le nombre de requêtes par minute a été atteint et désactive l'API si c'est le cas.

- `checkBlackList()`: Cette fonction vérifie si le temps de bannissement pour une API particulière a été atteint et effectue des actions en conséquence.