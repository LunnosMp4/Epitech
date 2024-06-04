import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:flutter_svg/flutter_svg.dart';
import 'package:trombarea/pages/navigation_page.dart';
import 'package:trombarea/services/firebase_auth_service.dart';
import 'package:trombarea/services/google_auth_service.dart';
import 'package:trombarea/widgets/icon_text_button_widget.dart';
import 'package:trombarea/widgets/large_button_widget.dart';
import 'package:trombarea/services/cloud_firestore_service.dart';

class LoginFormWidget extends StatelessWidget {
  final TextEditingController emailController;
  final TextEditingController passwordController;
  final GoogleAuthService _googleAuthService = GoogleAuthService();

  LoginFormWidget({
    Key? key,
    required this.emailController,
    required this.passwordController,
  }) : super(key: key);

  Future<void> _handleGoogleSignIn(BuildContext context) async {
    final User? user = await _googleAuthService.signInWithGoogle();

    if (user != null) {
      if (await CloudFireStoreService.userDocumentExists() == false) {
        CloudFireStoreService.createUserDocument();
      }

      Navigator.of(context).pushReplacement(
        MaterialPageRoute(
          builder: (context) => const NavigationPage(),
        ),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    var colorScheme = Theme.of(context).colorScheme;

    return Container(
      padding: const EdgeInsets.all(30),
      width: 400,
      child: Column(
        children: [
          const Text(
            'Se connecter',
            style: TextStyle(
                fontSize: 18,
                letterSpacing: 3,
                color: Colors.black54,
                fontWeight: FontWeight.bold),
          ),
          const SizedBox(height: 10),
          Container(
            width: double.infinity,
            decoration: BoxDecoration(
              border: Border.all(
                  color: colorScheme.outlineVariant.withOpacity(0.4), width: 1),
              borderRadius: BorderRadius.circular(16),
            ),
            padding: const EdgeInsets.all(30),
            child: Column(
              mainAxisSize: MainAxisSize.min,
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Fields(
                    emailController: emailController,
                    colorScheme: colorScheme,
                    passwordController: passwordController),
                const SizedBox(height: 25),
                LargeButton(
                  text: "S'inscrire",
                  backgroundColor: colorScheme.tertiaryContainer.withOpacity(0.7),
                  onPressed: () {
                    signUpByEmail(
                      emailController.text,
                      passwordController.text,
                      () {
                        Navigator.of(context).push(
                          MaterialPageRoute(
                            builder: (context) => const NavigationPage(),
                          ),
                        );
                      },
                    );
                  },
                ),
                const SizedBox(height: 10),
                LargeButton(
                  text: "Se connecter",
                  backgroundColor: colorScheme.primary.withOpacity(0.3),
                  onPressed: () {
                    signInByEmail(
                      emailController.text,
                      passwordController.text,
                      () {
                        Navigator.of(context).push(
                          MaterialPageRoute(
                            builder: (context) => const NavigationPage(),
                          ),
                        );
                      },
                    );
                  },
                ),
                Divider(
                  thickness: 1,
                  color: colorScheme.outlineVariant.withOpacity(0.2),
                  height: 40,
                ),
                IconTextButton(
                  text: 'Se connecter avec Google',
                  icon: SvgPicture.asset(
                    'assets/google-icon.svg',
                    height: 20,
                  ),
                  onPressed: () {
                    _handleGoogleSignIn(context);
                  },
                )
              ],
            ),
          ),
        ],
      ),
    );
  }
}

class Fields extends StatelessWidget {
  const Fields({
    super.key,
    required this.emailController,
    required this.colorScheme,
    required this.passwordController,
  });

  final TextEditingController emailController;
  final ColorScheme colorScheme;
  final TextEditingController passwordController;

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        TextField(
          controller: emailController,
          textAlign: TextAlign.center,
          autofillHints: const [AutofillHints.email],
          decoration: InputDecoration(
            labelText: 'Email',
            labelStyle: const TextStyle(
                color: Colors.black45, letterSpacing: 2, fontSize: 12),
            alignLabelWithHint: true,
            filled: true,
            fillColor: colorScheme.secondaryContainer.withOpacity(0.3),
            border: OutlineInputBorder(
              borderSide: BorderSide.none,
              borderRadius: BorderRadius.circular(10),
            ),
          ),
        ),
        const SizedBox(height: 10),
        TextField(
          controller: passwordController,
          textAlign: TextAlign.center,
          obscureText: true, // Pour masquer le mot de passe
          decoration: InputDecoration(
            labelText: 'Mot de passe',
            labelStyle: const TextStyle(
                color: Colors.black45, letterSpacing: 2, fontSize: 12),
            filled: true,
            fillColor: colorScheme.secondaryContainer.withOpacity(0.3),
            border: OutlineInputBorder(
              borderSide: BorderSide.none,
              borderRadius: BorderRadius.circular(10),
            ),
          ),
        ),
      ],
    );
  }
}
