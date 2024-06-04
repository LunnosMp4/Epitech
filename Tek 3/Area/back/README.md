# B-DEV-500-MPL-5-1-area-enzo.daumalle

## 1. LE PROJET

L'objectif de ce projet est de découvrir, dans son ensemble, la plateforme logicielle que nous avons choisie grâce à la création d'une application métier.  

Pour ce faire, nous devons mettre en place une suite logicielle qui fonctionne de manière similaire à IFTTT et/ou Zapier.  
  
Cette suite logicielle sera divisée en trois parties :  
  
Un serveur d'application pour implémenter toutes les fonctionnalités répertoriées.  
Un client web pour utiliser l'application depuis notre navigateur en interrogeant le serveur d'application.  
Un client mobile pour utiliser l'application depuis notre téléphone en interrogeant le serveur d'application.  
Aucun processus métier ne sera exécuté côté client web et mobile, qui ne servira que d'interface utilisateur et redirigera les demandes de/vers le serveur d'application.  

## 2. DOCKER-COMPOSE
Pour lancer notre application, nous avons suivi le sujet et avons utilisé Docker-Compose.

Avec Docker-Compose, nous sommes capables de définir, configurer, et exécuter les multiples conteneurs de nos applications de manière simplifiée et organisée, le tout à partir d’un fichier YAML unique. Ce fichier de configuration permet de déclarer toutes les services, réseaux et volumes nécessaires pour faire fonctionner notre stack, garantissant que les environnements soient reproductibles, isolés et consistants, indépendamment de l'endroit où ils sont déployés.

Pour exécuter le code, vous avez simplement besoin d'effectuer:

- docker-compose up

puis, une fois l'utilisation terminée:

- docker-compose down



## 3. TECHNOLOGIES UTILISÉES

Voici un aperçu des technologies que nous avons intégrées et les avantages intrinsèques qu’elles apportent à notre infrastructure.

1. Express.js :

    Facilité d'Utilisation : Express.js, en tant que framework de Node.js, nous permet de mettre en place notre serveur web de manière simple et efficace.

    Communauté et Support : Avec une large communauté d'utilisateurs, obtenir de l'aide ou puiser dans une bibliothèque extensive de middleware est facilité.

2. Dotenv :

    Sécurisation des Données Sensibles : En utilisant Dotenv pour la gestion de nos variables d'environnement, nous assurons que les informations sensibles (telles que les clés API, etc.) ne sont jamais hard-codées dans notre codebase, ajoutant une couche cruciale de sécurité.

    Facilité de Configuration : La simplicité de configuration et d'utilisation de Dotenv nous permet d'isoler les configurations spécifiques à l'environnement, offrant une flexibilité dans l'exécution du code dans divers scénarios (développement, test, production, etc.)

3. Firebase Cloud :

    Base de Données en Temps Réel : Firebase Cloud nous permet d’interagir avec une base de données en temps réel, assurant que nos utilisateurs bénéficient des données les plus actualisées sans avoir besoin de rafraîchir manuellement.

    Évolutivité : En s'appuyant sur l'infrastructure de Google Cloud, Firebase nous offre une plate-forme hautement évolutive, capable de gérer des applications à fort trafic sans compromettre la performance.

    Développement Rapide : Grâce à une multitude de services prêts à l'emploi (authentification, stockage de fichiers, fonctions cloud, etc.), Firebase nous permet de développer rapidement des fonctionnalités sans la complexité de construire des solutions back-end from scratch.

## 4. API UTILISÉES

- OpeWweatherMap
Utilisé pour savoir la météo à un endroit clé

## 5. FONCTIONS ET DESCRIPTIONS

### [`checkTrigger`](back/management/triggers-actions.js#L11)
Regarde si un trigger est vrai.
### [`findAction`](back/management/triggers-actions.js#L22)
Cherche l'action du trigger demandé.
### [`conditionTo`](back/management/triggers-actions.js#L44)
Vérifie si les paramètres du trigger sont valide en fonction de son type


### [`getCollection`](back/management/collections.js#L4)
Importe une collection de Cloud Firebase.
### [`deleteDoc`](back/management/collections.js#L19)
Supprime le document passer en paramètre.


### [`checkAPI`](back/management/blackList-api.js#L3)
Vérifie l'état des API.
### [`checkBlackList`](back/management/collections.js#L13)
Regarde si les temps de black liste ont été fait ou non.



### [`getTimeCond`](back/services/type/time/time-trigger.js#L2)
Vérifie la validité des paramètres des triggers de type: temps.



### [`getWeatherData`](back/services/type/weather/weather-action.js#L8)
Prends les informations de l'api OpeWweatherMap.
### [`getWeatherString`](back/services/type/weather/weather-action.js#L24)
Formate les données envoyés en paramètre.


### [`getWeatherTriggerCond`](back/services/type/weather/weather-action.js#L4)
Vérifie la validité des paramètres des triggers de type: météo.
### [`weatherTrigger`](back/services/type/weather/weather-action.js#L12)
Vérifie si le paramètre demandé est le même que le temps actuel envoyé en paramètre.


### [`checkGetWeathersAPI`](back/services/type/weather/weather-action.js#L8)
Vérifie si l'API OpeWweatherMap n'est pas déjà dans la blackListe et son état d'utilisation.
### [`weatherAction`](back/services/type/weather/weather-action.js#L24)
Prends les données d'une api qui donne le temps et les envoie sur la bonne platforme.