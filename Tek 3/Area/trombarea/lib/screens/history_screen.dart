import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:trombarea/models/applet/applet_model.dart';
import 'package:trombarea/responsive.dart';
import 'package:trombarea/services/cloud_firestore_service.dart';
import 'package:trombarea/widgets/history_card_widget.dart';
import 'package:trombarea/widgets/web_title_widget.dart';

class HistoryScreen extends StatefulWidget {
  const HistoryScreen({super.key});

  @override
  State<HistoryScreen> createState() => _HistoryScreenState();
}

class _HistoryScreenState extends State<HistoryScreen> {
  @override
  Widget build(BuildContext context) {
    final isMobile = Responsive.isMobile(context);

    if (isMobile) {
      return mobileLayout();
    } else {
      return desktopLayout();
    }
  }

  Scaffold mobileLayout() {
    return Scaffold(
        body: StreamBuilder<QuerySnapshot>(
          stream: CloudFireStoreService.appletsCollection.snapshots(),
          builder: (context, snapshot) {
            if (!snapshot.hasData) {
              return const Center(child: CircularProgressIndicator());
            }

            final applets = snapshot.data!.docs.map((doc) {
              final data = doc.data() as Map<String, dynamic>;
              return Applet.fromMap(data);
            }).toList();

            // Créez une liste de Timestamp contenant tous les timestamps de runTime de tous les applets
            final allTimestamps = <Timestamp>[];

            for (var applet in applets) {
              allTimestamps.addAll(applet.runTime);
            }

            // Triez la liste de tous les timestamps par ordre décroissant
            allTimestamps.sort((a, b) {
              return b.toDate().compareTo(a.toDate());
            });

            return ListView.builder(
              itemCount: allTimestamps.length,
              itemBuilder: (context, index) {
                final timestamp = allTimestamps[index];

                // Vous pouvez obtenir les informations de l'applet associé à ce timestamp
                final applet = applets.firstWhere((applet) {
                  return applet.runTime.contains(timestamp);
                });

                return HistoryCard(applet: applet, timestamp: timestamp);
              },
            );
          },
        ));
  }

  Scaffold desktopLayout() {
    return Scaffold(
      body: Stack(
        children: [
          Opacity(
            opacity: 0.05, // Adjust the opacity value as needed (0.0 to 1.0)
            child: Container(
              decoration: const BoxDecoration(
                image: DecorationImage(
                  image: AssetImage(
                      '../../assets/topography.png'), // Replace with your image path
                  repeat: ImageRepeat.repeat,
                ),
              ),
            ),
          ),
          Center(
            child: SizedBox(
              width: 800,
              child: Column(
                children: [
                  const WebTitle(title: 'Historique'),
                  StreamBuilder<QuerySnapshot>(
                    stream:
                        CloudFireStoreService.appletsCollection.snapshots(),
                    builder: (context, snapshot) {
                      if (!snapshot.hasData) {
                        return const Center(
                            child: CircularProgressIndicator());
                      }

                      final applets = snapshot.data!.docs.map((doc) {
                        final data = doc.data() as Map<String, dynamic>;
                        return Applet.fromMap(data);
                      }).toList();

                      // Créez une liste de Timestamp contenant tous les timestamps de runTime de tous les applets
                      final allTimestamps = <Timestamp>[];

                      for (var applet in applets) {
                        allTimestamps.addAll(applet.runTime);
                      }

                      // Triez la liste de tous les timestamps par ordre décroissant
                      allTimestamps.sort((a, b) {
                        return b.toDate().compareTo(a.toDate());
                      });

                      return ListView.builder(
                        itemCount: allTimestamps.length,
                        itemBuilder: (context, index) {
                          final timestamp = allTimestamps[index];

                          // Vous pouvez obtenir les informations de l'applet associé à ce timestamp
                          final applet = applets.firstWhere((applet) {
                            return applet.runTime.contains(timestamp);
                          });

                          return HistoryCard(
                              applet: applet, timestamp: timestamp);
                        },
                      );
                    },
                  )
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}
