import 'package:cloud_firestore/cloud_firestore.dart';

class User {
  const User({
    required this.discordWebhook,
    required this.location,
    required this.slackWebhook,
    required this.teamsWebhook,
    required this.telegramWebhook,
  });

  final String discordWebhook;
  final GeoPoint location;
  final String slackWebhook;
  final String teamsWebhook;
  final String telegramWebhook;


  Map<String, dynamic> toMap() {
    return {
      'discordWebhook': discordWebhook,
      'location': location,
      'slackWebhook': slackWebhook,
      'teamsWebhook': teamsWebhook,
      'telegramWebhook': telegramWebhook,
    };
  }

  User.fromMap(Map<String, dynamic> userMap)
      : discordWebhook = userMap['discordWebhook'],
        location = userMap['location'],
        slackWebhook = userMap['slackWebhook'],
        teamsWebhook = userMap['teamsWebhook'],
        telegramWebhook = userMap['telegramWebhook'];
}
