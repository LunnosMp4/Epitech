import 'package:flutter/material.dart';
import 'package:trombarea/services/getservice_service.dart';

class ServiceCard extends StatelessWidget {
  const ServiceCard({
    super.key,
    required this.name,
    required this.title,
    required this.callback,
  });

  final String name;
  final String title;
  final VoidCallback callback;

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      width: 130,
      child: ElevatedButton(
        onPressed: () {
          callback();
        },
        style: ButtonStyle(
            elevation: MaterialStateProperty.all(10),
            backgroundColor:
                MaterialStateProperty.all<Color>(getServiceColor(name)),
            shape: MaterialStateProperty.all<RoundedRectangleBorder>(
                RoundedRectangleBorder(
                    borderRadius: BorderRadius.circular(16)))),
        child: Padding(
          padding: const EdgeInsets.all(8),
          child: Center(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              mainAxisSize: MainAxisSize.min,
              children: [
                Icon(getServiceIcon(name, null, null),
                    size: 48, color: Colors.white70),
                const SizedBox(height: 15),
                Text(title,
                    style: Theme.of(context).textTheme.labelLarge!.copyWith(
                        color: Colors.white70, fontWeight: FontWeight.w900)),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
