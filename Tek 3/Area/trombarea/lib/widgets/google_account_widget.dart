import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';

class GoogleAccount extends StatelessWidget {
  const GoogleAccount({
    super.key,
    required this.user,
    required this.isMobile,
  });

  final User? user;
  final bool isMobile;

  @override
  Widget build(BuildContext context) {

    return Column(
      children: [
        CircleAvatar(
          backgroundImage: NetworkImage(user?.photoURL ?? ''),
          radius: isMobile ? 60 : 100,
        ),
        const SizedBox(height: 16),
        Text(
          user?.displayName ?? '',
          style:
              TextStyle(fontSize: isMobile ? 20.0 : 42.0),
        ),
      ],
    );
  }
}
