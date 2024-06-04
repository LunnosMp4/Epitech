import 'package:flutter/material.dart';

class WebTitle extends StatelessWidget {
  const WebTitle({
    super.key,
    required this.title,
  });

  final String title;

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        const SizedBox(height: 90),
        Text(title,
            style: Theme.of(context).textTheme.displayLarge!.copyWith(
              fontWeight: FontWeight.w900,
              shadows: <Shadow>[
                const Shadow(
                    offset: Offset(2, 2),
                    blurRadius: 5,
                    color: Color.fromARGB(255, 210, 210, 210)),
              ],
              letterSpacing: 10
            )),
        const SizedBox(height: 90),
      ],
    );
  }
}
