# Backend

Le backend de trombarea est responsable de la gestion des données, des services et des automatisations. Voici comment vous pouvez le configurer et le lancer ainsi que les différents composants qui le composent.

## Configuration de l'Environnement

1. **Configuration du .env**<br><br>
Avant de lancer le backend, assurez-vous que vous avez configuré correctement le fichier `.env`. Celui-ci contient les clés d'API et d'autres variables d'environnement nécessaires au bon fonctionnement de l'application.

2. **Installation des dépendances**<br><br>
Assurez-vous d'avoir toutes les dépendances nécessaires installées en exécutant `npm install` dans le dossier `backend`.

## Lancement du Backend

1. Construction des Images Docker

    ```bash
    docker-compose build
    ```

    Cette commande construira les images Docker en utilisant les configurations définies dans le fichier docker-compose.yml.

2. Lancement des Conteneurs Docker

    ```bash
    docker-compose up
    ```

    Cette commande démarrera tous les services backend nécessaires, y compris la base de données, les serveurs Web, et d'autres dépendances.

## Architecture

Voici l'architecture du backend de Trombarea

```bash
├── .gitignore
├── app.js                      # Point d'entrée de l'application
├── docker-compose.yml
├── Dockerfile
├── package-lock.json
├── package.json
├── README.md
├── about                       # Informations sur les déclencheurs, les actions et les plateformes
│   ├── about.json
│   └── getAbout.js
├── firebase                    # Configuration de Firebase : Authentification et Firestore
│   └── firebase.js
├── management                  # Gestion des données : collections, déclencheurs/actions, liste noire
│   ├── blackList-api.js
│   ├── collections.js
│   └── triggers-actions.js
└── services                    # Services disponibles : plateformes et types
    ├── platform                # Plateformes : Slack, Discord, etc.
    │   ├── sendToPlatform.js
    │   ├── ...
    └── type                    # Types : Date, Météo, etc.
        ├── ...
```
