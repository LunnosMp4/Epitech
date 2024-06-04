import 'package:trombarea/models/service_info_model.dart';

final List<ServiceInfo> triggerServices = [
  ServiceInfo('time', 'Horaires', false, [
    'hours',
    'date'
  ], [
    'Définir une heure qui se lance chaque jour',
    'Définir une date unique'
  ], [
    ['Heure'],
    ['Date']
  ]),
  ServiceInfo('weather', 'Météo', false, [
    'weatherCondition',
    'temperature'
  ], [
    'Choisir un temps (pluie, soleil, etc...)',
    'Entrer une température avec une condition (ex: ">24")'
  ], [
    [
      ['clouds', 'rain', 'clear']
    ],
    ['Température'],
  ]),
  ServiceInfo('spotify', 'Spotify', false, [
    'lastMusicChanged'
  ], [
    'Vérifier si la dernière musique écoutée a changé'
  ], [
    []
  ])
];

final List<ServiceInfo> actionServices = [
  ServiceInfo('crypto', 'Crypto', false, [
    'getCrypto'
  ], [
    'Récupérer les données d\'une crypto'
  ], [
    ['Nom de la crypto']
  ]),
  ServiceInfo('cocktail', 'Cocktails', false, [
    'getCocktail'
  ], [
    'Récupérer les recettes d\'un cocktail'
  ], [
    ['Nom du cocktail']
  ]),
  ServiceInfo('epitech_doors', 'Epitech', false, [
    'openDoor'
  ], [
    'Ouvrir la porte Epitech spécifiée'
  ], [
    ['Porte']
  ]),
  ServiceInfo('lol', 'LoL', false, [
    'getLol'
  ], [
    'Récupérer les statistiques d\'un joueur Lol'
  ], [
    ['Nom du joueur']
  ]),
  ServiceInfo('fortnite', 'Fortnite', false, [
    'getFortnite'
  ], [
    'Récupérer les statistiques d\'un joueur Fortnite'
  ], [
    ['Nom du joueur']
  ]),
  ServiceInfo('discord', 'Discord', true, [
    'sendTo'
  ], [
    'Envoyer un message personalisé sur un webhook'
  ], [
    ['Message', 'Webhook']
  ]),
  ServiceInfo('slack', 'Slack', true, [
    'sendTo'
  ], [
    'Envoyer un message sur un webhook'
  ], [
    ['Webhook']
  ]),
  ServiceInfo('teams', 'Teams', true, [
    'sendTo'
  ], [
    'Envoyer un message sur un webhook'
  ], [
    ['Webhook']
  ]),
  ServiceInfo('mail', 'Email', true, [
    'sendTo'
  ], [
    'Envoyer un message par mail'
  ], [
    ['Email']
  ]),
  ServiceInfo('telegram', 'Telegram', true, [
    'sendTo'
  ], [
    'Envoyer un message sur un webhook'
  ], [
    ['Webhook']
  ]),
  ServiceInfo('spotify', 'Spotify', false, [
    'musicPlayList'
  ], [
    'Ajouter une musique dans une playlist définie'
  ], [
    ['Titre', 'Artiste', 'Playlist']
  ]),
  ServiceInfo('steam', 'Steam', false, [
    'getStats',
    'getFriends',
    'getGames'
  ], [
    'Récupérer mes stats du compte',
    'Récupérer mes 10 amis ajoutés récemment',
    'Récupérer mes 10 jeux les plus joués'
  ], [
    ['Steam ID'],
    ['Steam ID'],
    ['Steam ID']
  ])
];
