import 'package:flutter/material.dart';

class AppName extends StatelessWidget {
  const AppName({
    super.key,
  });

  @override
  Widget build(BuildContext context) {
    return const Column(
      children: [
        Text(
          'TrombArea',
          style: TextStyle(
            color: Colors.black,
            fontFamily: 'Inter',
            fontSize: 38,
            fontWeight: FontWeight.w700,
            letterSpacing: 6.4,
          ),
        ),
        Text(
          "C'est trop génial !",
          style: TextStyle(
              fontSize: 10,
              letterSpacing: 8,
              color: Colors.black54,
              fontWeight: FontWeight.bold),
        ),
      ],
    );
  }
}
