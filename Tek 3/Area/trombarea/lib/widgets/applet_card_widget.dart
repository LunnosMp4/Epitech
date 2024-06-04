import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:intl/intl.dart';
import 'package:material_symbols_icons/symbols.dart';
import 'package:trombarea/models/applet/applet_model.dart';
import 'package:trombarea/services/cloud_firestore_service.dart';
import 'package:trombarea/services/getservice_service.dart';
import 'package:trombarea/services/firebase_auth_service.dart';

class AppletCard extends StatelessWidget {
  const AppletCard({
    super.key,
    required this.appletData,
    required this.appletDoc,
    this.marketPlace = false,
  });

  final Applet appletData;
  final QueryDocumentSnapshot<Map<String, dynamic>> appletDoc;
  final bool marketPlace;

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      width: 600,
      child: Card(
        margin: const EdgeInsets.all(8.0),
        color: getServiceColor(appletData.active
            ? appletData.action.first.platform?.service ??
                appletData.action.first.service
            : ''),
        child: Padding(
          padding: const EdgeInsets.all(8.0),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              HeadLine(appletData: appletData, appletDoc: appletDoc),
              ListTile(
                title: Text(appletData.title,
                    style: Theme.of(context).textTheme.titleLarge!.copyWith(
                        fontWeight: FontWeight.w900,
                        letterSpacing: 1.5,
                        color: Colors.white70)),
                subtitle: Text(marketPlace ? appletData.userName : '',
                    style: const TextStyle(
                        color: Colors.white70, letterSpacing: 1.5)),
              ),
              FooterLine(appletData: appletData, marketPlace: marketPlace),
            ],
          ),
        ),
      ),
    );
  }
}

class HeadLine extends StatefulWidget {
  const HeadLine({
    super.key,
    required this.appletData,
    required this.appletDoc,
  });

  final Applet appletData;
  final QueryDocumentSnapshot<Map<String, dynamic>> appletDoc;

  @override
  State<HeadLine> createState() => _HeadLineState();
}

class _HeadLineState extends State<HeadLine> {
  final String? userUid = getCurrentUserUid();
  bool isFavorite = false;

  late Stream<List<String>> userFavoritesStream;

  @override
  void initState() {
    super.initState();
    userFavoritesStream = CloudFireStoreService.getUserFavoritesStream();

    userFavoritesStream.listen((List<String> favorites) {
      if (mounted) {
        setState(() {
          isFavorite = favorites.contains(widget.appletDoc.id);
        });
      }
    });
  }

  Future<void> _showDeleteConfirmationDialog(BuildContext context) async {
    return showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: const Text('T\'es sûr de le supprimer ?'),
          content: const Text(
              'C\'est t\'as last chance là (en plus je sais même pas si ca marche et que ça supprime tout hihihi)'),
          actions: <Widget>[
            TextButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              child: const Text('Non non !'),
            ),
            TextButton(
              onPressed: () async {
                await CloudFireStoreService.appletsCollection
                    .doc(widget.appletDoc.id)
                    .delete();
                Navigator.of(context).pop();
              },
              child: const Text('Ouais'),
            ),
          ],
        );
      },
    );
  }

  void _toggleFavorite() async {
    final appletDoc =
        CloudFireStoreService.appletsCollection.doc(widget.appletDoc.id);

    if (isFavorite) {
      await CloudFireStoreService.removeAppletFromFavorites(
          widget.appletDoc.id);
      if (widget.appletData.favoritesCounter > 0) {
        widget.appletData.favoritesCounter -= 1;
      }
    } else {
      await CloudFireStoreService.addAppletToFavorites(widget.appletDoc.id);
      widget.appletData.favoritesCounter += 1;
    }

    await appletDoc.update(widget.appletData.toMap());
  }

  @override
  Widget build(BuildContext context) {
    final isCurrentUser = userUid == widget.appletData.userUid;
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        Row(
          children: [
            const SizedBox(width: 10),
            FaIcon(
              getServiceIcon(
                  widget.appletData.trigger.service,
                  widget.appletData.trigger.type,
                  widget.appletData.trigger.values.isNotEmpty ? widget.appletData.trigger.values[0] : ''),
              color: Colors.white60,
            ),
            const SizedBox(width: 15),
            FaIcon(
              getServiceIcon(
                  widget.appletData.action.first.service, null, null),
              color: Colors.white60,
            ),
            const SizedBox(width: 15),
            if (widget.appletData.action.first.platform != null)
              FaIcon(
                getServiceIcon(widget.appletData.action.first.platform!.service,
                    null, null),
                color: Colors.white60,
              ),
          ],
        ),
        Row(
          children: [
            if (!isCurrentUser)
              IconButton(
                enableFeedback: true,
                icon: Icon(
                  Symbols.favorite,
                  color: Colors.white70,
                  fill: isFavorite ? 1 : 0,
                ),
                onPressed: () async {
                  final appletDoc = CloudFireStoreService.appletsCollection
                      .doc(widget.appletDoc.id);

                  if (isFavorite) {
                    await CloudFireStoreService.removeAppletFromFavorites(
                        widget.appletDoc.id);
                    if (widget.appletData.favoritesCounter > 0) {
                      widget.appletData.favoritesCounter -= 1;
                    }
                  } else {
                    await CloudFireStoreService.addAppletToFavorites(
                        widget.appletDoc.id);
                    widget.appletData.favoritesCounter += 1;
                  }

                  await appletDoc.update(widget.appletData.toMap());
                },
              ),
            if (isCurrentUser)
              IconButton(
                enableFeedback: true,
                icon: const FaIcon(FontAwesomeIcons.trashCan,
                    color: Colors.white70),
                onPressed: () async {
                  await _showDeleteConfirmationDialog(context);
                },
              ),
          ],
        ),
      ],
    );
  }
}

class FooterLine extends StatelessWidget {
  const FooterLine({
    super.key,
    required this.appletData,
    required this.marketPlace,
  });

  final Applet appletData;
  final bool marketPlace;

  String _formatDate(DateTime date) =>
      DateFormat.MMMMd('fr').addPattern('à').add_Hm().format(date);

  @override
  Widget build(BuildContext context) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        if (!marketPlace && appletData.runTime.isNotEmpty)
          Text('Dernière exécution le ${_formatDate(appletData.runTime.last.toDate())}',
              style: Theme.of(context)
                  .textTheme
                  .labelSmall!
                  .copyWith(color: Colors.white38)),
        if (marketPlace)
          Row(
            children: <Widget>[
              const SizedBox(width: 5),
              const Icon(
                Symbols.person_2,
                color: Colors.white54,
                size: 16,
                fill: 1,
              ),
              const SizedBox(width: 5),
              Text(
                appletData.favoritesCounter.toString(),
                style: Theme.of(context)
                    .textTheme
                    .labelMedium!
                    .copyWith(color: Colors.white54),
              ),
            ],
          ),
        RichText(
          text: TextSpan(
            children: [
              TextSpan(
                text: appletData.oneShot ? 'Une seule fois' : '',
                style: Theme.of(context).textTheme.bodySmall!.copyWith(
                    fontWeight: FontWeight.bold, color: Colors.white54),
              ),
            ],
          ),
        ),
      ],
    );
  }
}
