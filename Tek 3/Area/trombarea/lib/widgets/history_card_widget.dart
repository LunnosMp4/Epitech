import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:intl/intl.dart';
import 'package:trombarea/models/applet/applet_model.dart';
import 'package:trombarea/services/getservice_service.dart';

class HistoryCard extends StatefulWidget {
  const HistoryCard({
    super.key,
    required this.applet,
    required this.timestamp,
  });

  final Applet applet;
  final Timestamp timestamp;

  @override
  State<HistoryCard> createState() => _HistoryCardState();
}

class _HistoryCardState extends State<HistoryCard> {
  late String? plateformService;

  String _formatDate(DateTime date) =>
      DateFormat.MMMMd('fr').addPattern('à').add_Hm().format(date);

  @override
  void initState() {
    plateformService = widget.applet.action.isNotEmpty ? widget.applet.action[0].platform?.service : '';
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Card(
      elevation: 0,
      color: getServiceColor(plateformService ?? ''),
      margin: const EdgeInsets.all(8),
      child: Row(
        children: [
          Expanded(
            child: ListTile(
              leading: Container(
                padding: const EdgeInsets.all(12),
                decoration: BoxDecoration(
                  color: Colors.white24,
                  borderRadius: BorderRadius.circular(16),
                ),
                child: FaIcon(
                  getServiceIcon(plateformService ?? '', null, null),
                  color: Colors.white70,
                  size: 24,
                ),
              ),
              title: Text(
                _formatDate(widget.timestamp.toDate()),
                style: Theme.of(context).textTheme.bodyLarge!.copyWith(
                      fontWeight: FontWeight.bold,
                      color: Colors.white70,
                      letterSpacing: 2,
                    ),
              ),
              subtitle: Text(
                widget.applet.title,
                style: Theme.of(context).textTheme.bodyMedium!.copyWith(
                      color: Colors.white70,
                      letterSpacing: 1.2,
                    ),
              ),
              contentPadding: const EdgeInsets.symmetric(
                horizontal: 16,
                vertical: 4,
              ),
            ),
          ),
        ],
      ),
    );
  }
}
