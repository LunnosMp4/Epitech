import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:trombarea/pages/navigation_page.dart';
import 'package:trombarea/pages/login/login_page.dart';

class LoadingPage extends StatelessWidget {
  const LoadingPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return StreamBuilder<User?>(
      stream: FirebaseAuth.instance.authStateChanges(),
      builder: (context, snapshot) {
        if (snapshot.connectionState == ConnectionState.waiting) {
          return const CircularProgressIndicator();
        } else {
          final bool isUserLoggedIn = snapshot.hasData;
          if (isUserLoggedIn) {
            Future.microtask(() {
              Navigator.of(context).push(
                MaterialPageRoute(
                  builder: (context) => const NavigationPage(),
                ),
              );
            });
          } else {
            Future.microtask(() {
              Navigator.of(context).push(
                MaterialPageRoute(
                  builder: (context) => const LoginPage(),
                ),
              );
            });
          }
          return const SizedBox();
        }
      },
    );
  }
}
