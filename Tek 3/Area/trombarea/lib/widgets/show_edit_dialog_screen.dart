import 'package:flutter/material.dart';
import 'package:trombarea/services/firebase_auth_service.dart';

class ShowEditDialog extends StatelessWidget {
  ShowEditDialog({
    Key? key,
    required this.field,
    required this.currentValue,
    required this.updateCallback,
  }) : super(key: key);

  final String field;
  final String currentValue;
  final TextEditingController editingController = TextEditingController();
  final Function(String, String) updateCallback;

  @override
  Widget build(BuildContext context) {
    return AlertDialog(
      title: Text('Modifier $field'),
      content: TextField(
        controller: editingController,
      ),
      actions: <Widget>[
        TextButton(
          child: const Text('Annuler'),
          onPressed: () {
            Navigator.of(context).pop();
          },
        ),
        TextButton(
          child: const Text('Enregistrer'),
          onPressed: () async {
            final newValue = editingController.text;
            if (field == 'Email') {
              bool updated = await updateEmail(newValue);
              if (updated) {
                updateCallback(field, newValue);
              }
            } else if (field == 'Nom') {
              // TODO: update name if we can
            }
            /* Add your custom field here with else if */
            Navigator.of(context).pop();
          },
        ),
      ],
    );
  }
}
