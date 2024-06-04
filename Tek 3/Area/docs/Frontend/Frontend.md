# Frontend

Le frontend de l'application est construit en utilisant Flutter, un framework de développement mobile open-source de Google. Flutter permet de créer des applications pour Android, iOS et Web à partir d'une seule base de code.

Dans le dossier `lib/`, vous trouverez l'architecture suivante :

- `main.dart` : C'est le point d'entrée de l'application Flutter. Il initialise l'application et appelle le widget racine.
- `models/` : Ce dossier contient les modèles de données utilisés dans l'application. Ces modèles définissent la structure des données que l'application utilise.
- `pages/` : Ce dossier contient les différentes pages ou écrans de l'application. Chaque fichier représente une page spécifique de l'application.
- `services/` : Ce dossier contient les services utilisés dans l'application. Les services peuvent inclure des tâches telles que la récupération de données à partir d'une API, la gestion de l'état de l'application, etc.
- `widgets/` : Ce dossier contient les widgets réutilisables utilisés dans l'application. Un widget est un élément d'interface utilisateur qui peut être utilisé à plusieurs endroits dans l'application.

## Installation

Tout est géré a l'aide de Docker, il suffit donc de lancer la commande suivante :

```bash
docker-compose build
```

Cette commande va construire l'image Docker de l'application pour le web mais également l'apk pour Android. Cela peut prendre quelques minutes.

Pour acceder à l'application web, il suffit de lancer la commande suivante :

```bash
docker run -d -p 5000:80 trombarea-flutter-build
```

L'application est maintenant accessible à l'adresse suivante : [http://localhost:5000](http://localhost:5000)

Pour Android, il vous suffit de récupérer le fichier `app-release.apk` dans le dossier `build/android/outputs/apk/release/` et de l'installer sur votre téléphone.

## Développement

Si vous souhaitez développer l'application, il vous faudra installer Flutter sur votre machine. Pour cela, suivez les instructions sur le site officiel : [https://flutter.dev/docs/get-started/install](https://flutter.dev/docs/get-started/install)

Une fois Flutter installé, vous pouvez lancer le web en utilisant la commande suivante :

```bash
flutter run -d chrome --web-hostname localhost --web-port 5000
```

Le port 5000 est important si vous utilisez la connection avec google car ce port est le seul autorisé par Google.<br>
Vous pouvez également lancer l'application sur Android en utilisant la commande suivante :

```bash
flutter run -d <device-id>
```

Et meme générer l'apk en utilisant la commande suivante :

```bash
flutter build apk
```
