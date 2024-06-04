import 'package:flutter/material.dart';
import 'package:trombarea/services/getservice_service.dart';

class BlockCard extends StatelessWidget {
  const BlockCard(
      {super.key,
      this.isTrigger = false,
      this.isPlatform = false,
      required this.callback,
      this.serviceSelected});

  final bool isTrigger;
  final bool isPlatform;
  final VoidCallback callback;
  final String? serviceSelected;

  @override
  Widget build(BuildContext context) {
    return Card(
      elevation: 0,
      color: const Color.fromARGB(150, 226, 232, 247),
      margin: const EdgeInsets.all(7),
      child: Padding(
        padding: const EdgeInsets.all(20),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceAround,
          children: [
            Text(
                isTrigger
                    ? 'Si'
                    : isPlatform
                        ? 'Par'
                        : 'Alors',
                style: Theme.of(context).textTheme.headlineSmall!.copyWith(
                    color: Colors.black87,
                    fontWeight: FontWeight.w600,
                    shadows: <Shadow>[
                      const Shadow(
                        offset: Offset(2, 2),
                        blurRadius: 30.0,
                        color: Color.fromARGB(80, 0, 0, 0),
                      ),
                    ],
                    letterSpacing: 5)),
            const SizedBox(width: 15),
            if (serviceSelected == null)
              ElevatedButton.icon(
                onPressed: () {
                  callback();
                },
                icon: const Icon(Icons.add_circle, fill: 1),
                label: Text(
                    isTrigger
                        ? 'Ajouter un trigger'
                        : isPlatform
                            ? 'Ajouter une plateforme'
                            : 'Ajouter une action',
                    style: const TextStyle(letterSpacing: 1.2)),
                style: ButtonStyle(
                  foregroundColor:
                      MaterialStateProperty.all<Color>(Colors.white),
                  backgroundColor: MaterialStateProperty.all<Color>(isTrigger
                      ? Theme.of(context).colorScheme.tertiary
                      : Theme.of(context).colorScheme.secondary),
                  padding: MaterialStateProperty.all<EdgeInsets>(
                      const EdgeInsets.symmetric(horizontal: 10, vertical: 20)),
                ),
              ),
            if (serviceSelected != null)
              ElevatedButton(
                onPressed: () {
                  callback();
                },
                style: ButtonStyle(
                  foregroundColor:
                      MaterialStateProperty.all<Color>(Colors.white),
                  backgroundColor: MaterialStateProperty.all<Color>(
                      getServiceColor(serviceSelected!)),
                  padding: MaterialStateProperty.all<EdgeInsets>(
                      const EdgeInsets.symmetric(horizontal: 10, vertical: 20)),
                ),
                child: Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 20),
                  child: Row(
                    mainAxisSize: MainAxisSize.min,
                    children: [
                      Icon(getServiceIcon(serviceSelected!, null, null)),
                      const SizedBox(width: 25),
                      Text(serviceSelected!,
                          style: const TextStyle(letterSpacing: 1.2)),
                    ],
                  ),
                ),
              ),
          ],
        ),
      ),
    );
  }
}
