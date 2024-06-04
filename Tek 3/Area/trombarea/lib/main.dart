import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/services.dart';
import 'package:trombarea/pages/loading_page.dart';
import 'firebase_options.dart';
import 'package:trombarea/services/firebase_auth_service.dart';
import 'color_schemes.g.dart';
import 'package:flutter_web_plugins/url_strategy.dart';

bool shouldUseFirestoreEmulator = false;
Future<void> main() async {
  usePathUrlStrategy();
  WidgetsFlutterBinding.ensureInitialized();
  SystemChrome.setPreferredOrientations([
    DeviceOrientation.portraitUp,
    DeviceOrientation.portraitDown,
  ]);
  await Firebase.initializeApp(options: DefaultFirebaseOptions.currentPlatform);
  if (shouldUseFirestoreEmulator) {
    FirebaseFirestore.instance.useFirestoreEmulator('localhost', 8080);
  }
  Future.delayed(const Duration(seconds: 1), () {
    registerForAuthStateChanges();
  });
  runApp(const TrombAreaApp());
}

class TrombAreaApp extends StatelessWidget {
  const TrombAreaApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'TrombArea',
      theme: ThemeData(useMaterial3: true, colorScheme: lightColorScheme, fontFamily: 'Exo 2'),
      // darkTheme: ThemeData(useMaterial3: true, colorScheme: darkColorScheme),
      home: const LoadingPage(),
    );
  }
}
