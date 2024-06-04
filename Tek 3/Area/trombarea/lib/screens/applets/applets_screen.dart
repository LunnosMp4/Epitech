import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:trombarea/models/applet/applet_model.dart';
import 'package:trombarea/responsive.dart';
import 'package:trombarea/services/cloud_firestore_service.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:trombarea/widgets/applet_card_widget.dart';
import 'package:trombarea/services/firebase_auth_service.dart';
import 'package:intl/date_symbol_data_local.dart';
import 'package:flip_card/flip_card.dart';
import 'package:trombarea/widgets/web_title_widget.dart';

class AppletsScreen extends StatefulWidget {
  const AppletsScreen({
    super.key,
  });

  @override
  State<AppletsScreen> createState() => _AppletsScreenState();
}

class _AppletsScreenState extends State<AppletsScreen> {
  late Stream<QuerySnapshot<Map<String, dynamic>>?> appletsStream;
  late Stream<List<String>> userFavoritesStream;

  @override
  void initState() {
    super.initState();
    initializeDateFormatting();
    appletsStream = CloudFireStoreService.appletsCollection.snapshots();
    userFavoritesStream = CloudFireStoreService.getUserFavoritesStream();
  }

  @override
  Widget build(BuildContext context) {
    final isMobile = Responsive.isMobile(context);

    if (isMobile) {
      return mobileLayout();
    } else {
      return desktopLayout();
    }
  }

  Container mobileLayout() {
    return Container(
      color: Colors.white,
      child: Center(
        child: SafeArea(
          child: Scaffold(
            body: SingleChildScrollView(
              child: StreamBuilder<QuerySnapshot<Map<String, dynamic>>?>(
                stream: appletsStream,
                builder: (context, appletsSnapshot) {
                  if (appletsSnapshot.hasError) {
                    return Center(
                      child: Text('Error: ${appletsSnapshot.error}'),
                    );
                  }

                  if (!appletsSnapshot.hasData) {
                    return const Center(
                      child: CircularProgressIndicator(),
                    );
                  }

                  final appletsDocs = appletsSnapshot.data!.docs;

                  return StreamBuilder<List<String>>(
                      stream: userFavoritesStream,
                      builder: (context, favoritesSnapshot) {
                        if (favoritesSnapshot.hasError) {
                          return Center(
                            child: Text('Error: ${favoritesSnapshot.error}'),
                          );
                        }

                        final userFavorites = favoritesSnapshot.data ?? [];

                        final filteredApplets = appletsDocs
                            .where((doc) =>
                                doc.data()['userUid'] == getCurrentUserUid() ||
                                userFavorites.contains(doc.id))
                            .toList();

                        if (filteredApplets.isEmpty) {
                          return Center(
                            child: Text(
                              "Vous n'avez pas d'applets",
                              style: TextStyle(
                                fontWeight: FontWeight.bold,
                                fontSize: Theme.of(context)
                                    .textTheme
                                    .bodyLarge!
                                    .fontSize,
                              ),
                            ),
                          );
                        } else {
                          return Wrap(
                            children:
                                List.generate(filteredApplets.length, (index) {
                              final appletData =
                                  Applet.fromMap(filteredApplets[index].data());
                              return FlipCard(
                                  side: appletData.active
                                      ? CardSide.FRONT
                                      : CardSide.BACK,
                                  onFlipDone: (status) {
                                    if (status == true) {
                                      CloudFireStoreService.appletsCollection
                                          .doc(filteredApplets[index].id)
                                          .update({'active': false});
                                    } else {
                                      CloudFireStoreService.appletsCollection
                                          .doc(filteredApplets[index].id)
                                          .update({'active': true});
                                    }
                                  },
                                  direction: FlipDirection.HORIZONTAL,
                                  front: AppletCard(
                                    appletData: appletData,
                                    appletDoc: filteredApplets[index],
                                  )
                                      .animate()
                                      .slideY(begin: 0.4, duration: 400.ms)
                                      .fadeIn()
                                  // .animate(onPlay: (controller) => controller.repeat())
                                  // .shimmer(
                                  //   duration: 1000.ms,
                                  //   delay: 2000.ms,
                                  //   color: Colors.grey.shade300.withOpacity(0.3),
                                  // )
                                  ,
                                  back: AppletCard(
                                    appletData: appletData,
                                    appletDoc: filteredApplets[index],
                                  ));
                            }),
                          );
                        }
                      });
                },
              ),
            ),
          ),
        ),
      ),
    );
  }

  Container desktopLayout() {
    return Container(
      color: Colors.white,
      child: Center(
        child: SafeArea(
          child: Scaffold(
            body: Stack(
              children: [
                Opacity(
                  opacity: 0.05,
                  child: Container(
                    decoration: const BoxDecoration(
                      image: DecorationImage(
                        image: AssetImage('../../../assets/topography.png'),
                        repeat: ImageRepeat.repeat,
                      ),
                    ),
                  ),
                ),
                Center(
                  child: Column(
                    children: [
                      const WebTitle(title: 'Mes Applets'),
                      SingleChildScrollView(
                        child: StreamBuilder<QuerySnapshot<Map<String, dynamic>>?>(
                          stream: appletsStream,
                          builder: (context, appletsSnapshot) {
                            if (appletsSnapshot.hasError) {
                              return Center(
                                child: Text('Error: ${appletsSnapshot.error}'),
                              );
                            }
                            if (!appletsSnapshot.hasData) {
                              return const Center(
                                child: CircularProgressIndicator(),
                              );
                            }
                      
                            final appletsDocs = appletsSnapshot.data!.docs;
                      
                            return StreamBuilder<List<String>>(
                                stream: userFavoritesStream,
                                builder: (context, favoritesSnapshot) {
                                  if (favoritesSnapshot.hasError) {
                                    return Center(
                                      child: Text(
                                          'Error: ${favoritesSnapshot.error}'),
                                    );
                                  }
                      
                                  final userFavorites =
                                      favoritesSnapshot.data ?? [];
                      
                                  final filteredApplets = appletsDocs
                                      .where((doc) =>
                                          doc.data()['userUid'] ==
                                              getCurrentUserUid() ||
                                          userFavorites.contains(doc.id))
                                      .toList();
                      
                                  if (filteredApplets.isEmpty) {
                                    return Center(
                                      child: Text(
                                        "Vous n'avez pas d'applets",
                                        style: TextStyle(
                                          fontWeight: FontWeight.bold,
                                          fontSize: Theme.of(context)
                                              .textTheme
                                              .bodyLarge!
                                              .fontSize,
                                        ),
                                      ),
                                    );
                                  } else {
                                    return Wrap(
                                      children: List.generate(
                                          filteredApplets.length, (index) {
                                        final appletData = Applet.fromMap(
                                            filteredApplets[index].data());
                                        return FlipCard(
                                            side: appletData.active
                                                ? CardSide.FRONT
                                                : CardSide.BACK,
                                            onFlipDone: (status) {
                                              if (status == true) {
                                                CloudFireStoreService
                                                    .appletsCollection
                                                    .doc(
                                                        filteredApplets[index].id)
                                                    .update({'active': false});
                                              } else {
                                                CloudFireStoreService
                                                    .appletsCollection
                                                    .doc(
                                                        filteredApplets[index].id)
                                                    .update({'active': true});
                                              }
                                            },
                                            direction: FlipDirection.HORIZONTAL,
                                            front: AppletCard(
                                              appletData: appletData,
                                              appletDoc: filteredApplets[index],
                                            )
                                                .animate()
                                                .slideY(
                                                    begin: 0.4, duration: 400.ms)
                                                .fadeIn()
                                            // .animate(onPlay: (controller) => controller.repeat())
                                            // .shimmer(
                                            //   duration: 1000.ms,
                                            //   delay: 2000.ms,
                                            //   color: Colors.grey.shade300.withOpacity(0.3),
                                            // )
                                            ,
                                            back: AppletCard(
                                              appletData: appletData,
                                              appletDoc: filteredApplets[index],
                                            ));
                                      }),
                                    );
                                  }
                                });
                          },
                        ),
                      ),
                    ],
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
