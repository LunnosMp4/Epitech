# Trombarea

## Introduction

L'objectif de ce projet est de découvrir, dans son ensemble, la plateforme logicielle que nous avons choisie grâce à la création d'une application métier.

Pour ce faire, nous devons mettre en place une suite logicielle qui fonctionne de manière similaire à IFTTT et/ou Zapier.

Cette suite logicielle sera divisée en trois parties :

Un serveur d'application pour implémenter toutes les fonctionnalités répertoriées.
Un client web pour utiliser l'application depuis notre navigateur en interrogeant le serveur d'application.
Un client mobile pour utiliser l'application depuis notre téléphone en interrogeant le serveur d'application.
Aucun processus métier ne sera exécuté côté client web et mobile, qui ne servira que d'interface utilisateur et redirigera les demandes de/vers le serveur d'application.

## Les technologies utilisées

### Côté backend

Notre serveur d'application est développé en Node.js, un environnement d'exécution JavaScript côté serveur, et utilise le framework Express.js pour faciliter la création de notre API REST.    

1. **Express.js :**

    > - **Facilité d'Utilisation :** Express.js, en tant que framework de Node.js, nous permet de mettre en place notre serveur web de manière simple et efficace.<br><br>
    > - **Communauté et Support :** Avec une large communauté d'utilisateurs, obtenir de l'aide ou puiser dans une bibliothèque extensive de middleware est facilité.

2. **Firebase Cloud :**

    > - **Base de Données en Temps Réel :** Firebase Cloud nous permet d’interagir avec une base de données en temps réel, assurant que nos utilisateurs bénéficient des données les plus actualisées sans avoir besoin de rafraîchir manuellement.<br><br>
    > - **Évolutivité :** En s'appuyant sur l'infrastructure de Google Cloud, Firebase nous offre une plate-forme hautement évolutive, capable de gérer des applications à fort trafic sans compromettre la performance.<br><br>
    > - **Développement Rapide :** Grâce à une multitude de services prêts à l'emploi (authentification, stockage de fichiers, fonctions cloud, etc.), Firebase nous permet de développer rapidement des fonctionnalités sans la complexité de construire des solutions back-end from scratch.

### Côté frontend

Notre client android / web est développé en Flutter, un framework open-source créé par Google pour le développement d'applications multiplateformes.
L'avantage de Flutter est qu'il permet de développer une application pour Android, iOS, Windows, Mac, Linux et le web à partir d'une seule base de code.

1. **Flutter :**

    > - **Multiplateforme :** Flutter nous permet de développer une application pour Android, iOS, Windows, Mac, Linux et le web à partir d'une seule base de code.<br><br>
    > - **Rapidité :** Flutter est un framework très rapide, il permet de développer des applications avec une très bonne performance.<br><br>
    > - **Hot Reload :** Flutter permet de modifier le code source de l'application en cours d'exécution, sans avoir à la recompiler.<br><br>
    > - **Widgets :** Flutter utilise des widgets pour construire l'interface utilisateur de l'application, ce qui permet de créer des interfaces utilisateur personnalisées et réactives.

2. **Firebase :** 

    > - **Authentification :** Firebase nous permet de gérer l'authentification des utilisateurs de notre application.<br><br>