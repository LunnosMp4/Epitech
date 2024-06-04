import 'package:flutter/material.dart';

class ProfileElevatedButton extends StatelessWidget {
  const ProfileElevatedButton({
    super.key,
    required this.text,
    required this.color,
    this.callback,
    this.desktopVersion = false,
  });

  final String text;
  final Color color;
  final VoidCallback? callback;
  final bool desktopVersion;

  @override
  Widget build(BuildContext context) {
    return OutlinedButton(
      onPressed: callback,
      style: OutlinedButton.styleFrom(
          foregroundColor: color,
          side: BorderSide(color: color.withOpacity(0.2)),
          shape: RoundedRectangleBorder(
            borderRadius: BorderRadius.circular(10),
          ),
          minimumSize: Size.fromHeight(desktopVersion ? 80 : 50)),
      child: Text(text,
          style: TextStyle(
              fontSize: desktopVersion ? 18 : null,
              letterSpacing: 1.2,
              fontWeight: FontWeight.bold)),
    );
  }
}
