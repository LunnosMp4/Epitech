# TrombArea

Plateforme d'automatisation de sa vie numérique  

## 1. LE PROJET

L'objectif de ce projet est de découvrir, dans son ensemble, la plateforme logicielle que nous avons choisie grâce à la création d'une application métier.  

Pour ce faire, nous devons mettre en place une suite logicielle qui fonctionne de manière similaire à IFTTT et/ou Zapier.  
  
Cette suite logicielle sera divisée en trois parties :  
  
Un serveur d'application pour implémenter toutes les fonctionnalités répertoriées.  
Un client web pour utiliser l'application depuis notre navigateur en interrogeant le serveur d'application.  
Un client mobile pour utiliser l'application depuis notre téléphone en interrogeant le serveur d'application.  
Aucun processus métier ne sera exécuté côté client web et mobile, qui ne servira que d'interface utilisateur et redirigera les demandes de/vers le serveur d'application.  

## 2. FONCTIONNALITÉS

L'application offrira les fonctionnalités suivantes :  
  
L'utilisateur s'inscrit sur l'application pour obtenir un compte.  
L'utilisateur enregistré confirme ensuite son inscription sur l'application avant de pouvoir l'utiliser.  
L'application demande ensuite à l'utilisateur authentifié de s'abonner à des Services.  
Chaque service propose les composants suivants :  
Type Action.  
Type REAction.  
L'utilisateur authentifié compose une AREA en interconnectant une Action à une REAction précédemment configurée.  
L'application déclenche automatiquement les AREA grâce à des déclencheurs.  
Le serveur d'application n'est exploité que pour les clients web et/ou mobiles, qui devront exposer toutes ses fonctionnalités via une API REST.  

## 3. AUTHENTIFICATION / IDENTIFICATION

L'utilisation de l'application nécessite de connaître l'utilisateur en question.  
  
Pour ce faire, il est nécessaire de mettre en œuvre les options suivantes :  
  
Une méthode d'authentification de l'utilisateur via un nom d'utilisateur / mot de passe. Dans ce cas, le client transmet la demande au serveur d'application qui la traitera.  
Une méthode d'identification des utilisateurs via OAuth2 (par exemple, Yammer / Twitter / Facebook / etc.). Dans ce cas, le client traite lui-même cette identification et avertit le serveur d'application en cas de réussite.  
Concernant la méthode d'identification, veillez à associer le compte tiers à un utilisateur du système.  

## 4. CHOIX DES TECHNOS

### Pour le backend :
- Rust : Assez compliqué a mettre en place, demande trop de temps étant donné que personne n'a travaillé avec donc il faut apprendre.
- Python (fastapi) : Plutot simple et rapide a utilisé mais tout le monde n'est pas vraiment a l'aise avec.
- Java : Meme problème que rust ici
- NodeJS : Simple a mettre en place et tout le monde sait faire du js, nous pourrons aussi le coder en TypeScript en créant nos propres typages. C'est donc c'est le choix le plus judicieux

### Pour le front :
- React Native : On sait l'utiliser mais ce n'est pas cross plateforme.
- Flutter : La partie Frontend du groupe s'est déjà initier au Flutter, en plus de celà, Flutter est un framework assez récent avec des privilèges pour firebase car les deux services viennent de Google, et il nous permet de faire du crossplateforme.


## Contributeurs:

WilliamAndreo  
0yco  
LunnosMp4  
RyuOkami83
ArnauldT  
