import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';

IconData getServiceIcon(String serviceName, String? serviceType, String? serviceValue) {
  switch (serviceName) {
    case 'time':
      return FontAwesomeIcons.clock;
    case 'weather':
      if (serviceType == 'weatherCondition' && serviceValue is String) {
        return getServiceIconType(serviceValue);
      } else {
        return FontAwesomeIcons.cloudSun;
      }
    case 'crypto':
      return FontAwesomeIcons.moneyCheckDollar;
    case 'cocktail':
      return FontAwesomeIcons.martiniGlassCitrus;
    case 'epitech_doors':
      return FontAwesomeIcons.doorClosed;
    case 'lol':
      return FontAwesomeIcons.gamepad;
    case 'fortnite':
      return FontAwesomeIcons.gamepad;
    case 'steam':
      return FontAwesomeIcons.steam;
    case 'discord':
      return FontAwesomeIcons.discord;
    case 'slack':
      return FontAwesomeIcons.slack;
    case 'mail':
      return FontAwesomeIcons.envelope;
    case 'teams':
      return FontAwesomeIcons.microsoft;
    case 'telegram':
      return FontAwesomeIcons.telegram;
    case 'spotify':
      return FontAwesomeIcons.spotify;
    default:
      return FontAwesomeIcons.question;
  }
}

IconData getServiceIconType(String? serviceValue) {
  switch (serviceValue) {
    case 'clouds':
      return FontAwesomeIcons.cloud;
    case 'rain':
      return FontAwesomeIcons.cloudRain;
    case 'clear':
      return FontAwesomeIcons.sun;
    default:
      return FontAwesomeIcons.cloudSun;
  }
}

Color getServiceColor(String serviceName) {
  switch (serviceName) {
    case 'time':
      return Colors.brown.shade300;
    case 'weather':
      return const Color.fromARGB(186, 177, 183, 228);
    case 'crypto':
      return Colors.amber.shade300;
    case 'cocktail':
      return const Color(0xbbea2a8a);
    case 'epitech_doors':
      return const Color(0xbb0c52a4);
    case 'lol':
      return const Color(0xbb05819c);
    case 'fortnite':
      return const Color(0xbb05819c);
    case 'steam':
      return const Color(0xbb1b2838);
    case 'discord':
      return const Color(0xbb5868eb);
    case 'slack':
      return const Color(0xbb48174a);
    case 'mail':
      return Colors.amber.shade500;
    case 'teams':
      return const Color(0xbb2e3a9b);
    case 'telegram':
      return const Color(0xbb2ca0d9);
    case 'spotify':
      return const Color(0xbb1fd660);
    default:
      return Colors.grey.shade400;
  }
}
