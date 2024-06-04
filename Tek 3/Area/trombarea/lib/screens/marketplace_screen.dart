import 'package:flutter/material.dart';
import 'package:material_symbols_icons/symbols.dart';
import 'package:trombarea/models/applet/applet_model.dart';
import 'package:trombarea/responsive.dart';
import 'package:trombarea/services/cloud_firestore_service.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:trombarea/widgets/applet_card_widget.dart';
import 'package:intl/date_symbol_data_local.dart';
import 'package:trombarea/widgets/web_title_widget.dart';

class MarketplaceScreen extends StatefulWidget {
  const MarketplaceScreen({
    super.key,
  });

  @override
  State<MarketplaceScreen> createState() => _MarketplaceScreenState();
}

class _MarketplaceScreenState extends State<MarketplaceScreen> {
  late Stream<QuerySnapshot<Map<String, dynamic>>> appletsStream;
  List<QueryDocumentSnapshot<Map<String, dynamic>>> filteredApplets = [];
  bool isFilteredAppletsInitialized = false;
  final TextEditingController searchController = TextEditingController();

  @override
  void initState() {
    super.initState();
    initializeDateFormatting();
    appletsStream = CloudFireStoreService.appletsCollection.snapshots();
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
      child: SafeArea(
        child: Scaffold(
          body: SingleChildScrollView(
            child: Column(
              children: [
                StreamBuilder<QuerySnapshot<Map<String, dynamic>>>(
                  stream: appletsStream,
                  builder: (context, appletsSnapshot) {
                    if (appletsSnapshot.hasError) {
                      return Center(
                        child: Text(
                            'Error: ${appletsSnapshot.error}, ${appletsSnapshot.error}'),
                      );
                    }

                    if (!appletsSnapshot.hasData) {
                      return const Center(
                        child: CircularProgressIndicator(),
                      );
                    }

                    final appletsDocs = appletsSnapshot.data!.docs
                        .where((doc) =>
                            doc.data()['oneShot'] == false &&
                            doc.data()['public'] == true)
                        .toList();
                    if (searchController.text.isEmpty) {
                      filteredApplets = appletsDocs;
                    }

                    return Column(
                      children: [
                        // SearchBar
                        Padding(
                            padding: const EdgeInsets.all(20.0),
                            child: TextField(
                              style: const TextStyle(
                                  color: Colors.black54,
                                  letterSpacing: 1.5,
                                  fontWeight: FontWeight.w700),
                              controller: searchController,
                              decoration: InputDecoration(
                                hintText: 'Rechercher un applet',
                                hintStyle: const TextStyle(
                                    color: Colors.black38, letterSpacing: 1.5),
                                prefixIcon: const Icon(Icons.search,
                                    color: Colors.black38),
                                suffixIcon: searchController.text.isNotEmpty
                                    ? IconButton(
                                        icon: const Icon(Symbols.clear),
                                        onPressed: () {
                                          // Efface le texte et réinitialise les applets filtrés
                                          if (mounted) {
                                            setState(() {
                                              searchController.clear();
                                              filteredApplets = appletsDocs;
                                              FocusScope.of(context).unfocus();
                                            });
                                          }
                                        },
                                      )
                                    : null,
                                filled: true,
                                fillColor:
                                    const Color.fromARGB(150, 226, 232, 247),
                                border: OutlineInputBorder(
                                  borderSide: BorderSide.none,
                                  borderRadius: BorderRadius.circular(16),
                                ),
                              ),
                              onChanged: (searchText) {
                                if (mounted) {
                                  setState(() {
                                    filteredApplets = appletsDocs.where((doc) {
                                      final appletData =
                                          Applet.fromMap(doc.data());
                                      return appletData.title
                                              .toLowerCase()
                                              .contains(
                                                  searchText.toLowerCase()) ||
                                          appletData.userName
                                              .toLowerCase()
                                              .contains(
                                                  searchText.toLowerCase());
                                    }).toList();
                                  });
                                }
                              },
                            )), // SearchBar
                        Wrap(
                          children:
                              List.generate(filteredApplets.length, (index) {
                            final Applet appletData =
                                Applet.fromMap(filteredApplets[index].data());
                            return AppletCard(
                              appletData: appletData,
                              appletDoc: filteredApplets[index],
                              marketPlace: true,
                            );
                          }),
                        ),
                      ],
                    );
                  },
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }

  Container desktopLayout() {
    return Container(
      color: Colors.white,
      child: SafeArea(
        child: Scaffold(
          body: Stack(
            children: [
              Opacity(
                opacity: 0.05,
                child: Container(
                  decoration: const BoxDecoration(
                    image: DecorationImage(
                      image: AssetImage('../../assets/topography.png'),
                      repeat: ImageRepeat.repeat,
                    ),
                  ),
                ),
              ),
              Center(
                child: Column(
                  children: [
                    const WebTitle(title: 'Marketplace'),
                    StreamBuilder<QuerySnapshot<Map<String, dynamic>>>(
                      stream: appletsStream,
                      builder: (context, appletsSnapshot) {
                        if (appletsSnapshot.hasError) {
                          return Center(
                            child: Text(
                                'Error: ${appletsSnapshot.error}, ${appletsSnapshot.error}'),
                          );
                        }

                        if (!appletsSnapshot.hasData) {
                          return const Center(
                            child: CircularProgressIndicator(),
                          );
                        }

                        final appletsDocs = appletsSnapshot.data!.docs
                            .where((doc) =>
                                doc.data()['oneShot'] == false &&
                                doc.data()['public'] == true)
                            .toList();
                        if (searchController.text.isEmpty) {
                          filteredApplets = appletsDocs;
                        }

                        return Column(
                          children: [
                            // SearchBar
                            Container(
                                padding: const EdgeInsets.all(20.0),
                                width: 1000,
                                child: TextField(
                                  style: Theme.of(context)
                                      .textTheme
                                      .titleLarge!
                                      .copyWith(
                                          color: Colors.black54,
                                          letterSpacing: 1.5,
                                          fontWeight: FontWeight.w700),
                                  controller: searchController,
                                  decoration: InputDecoration(
                                    contentPadding: const EdgeInsets.all(25),
                                    hintText: 'Rechercher un applet',
                                    hintStyle: Theme.of(context)
                                        .textTheme
                                        .titleLarge!
                                        .copyWith(
                                            color: Colors.black38,
                                            letterSpacing: 1.5),
                                    prefixIcon: Container(
                                      margin: const EdgeInsets.all(16),
                                      child: const Icon(Icons.search,
                                          color: Colors.black38, size: 32),
                                    ),
                                    suffixIcon: searchController.text.isNotEmpty
                                        ? Container(
                                            margin: const EdgeInsets.all(8),
                                            child: IconButton(
                                              icon: const Icon(Symbols.clear,
                                                  color: Colors.black38,
                                                  size: 32),
                                              onPressed: () {
                                                // Efface le texte et réinitialise les applets filtrés
                                                if (mounted) {
                                                  setState(() {
                                                    searchController.clear();
                                                    filteredApplets =
                                                        appletsDocs;
                                                    FocusScope.of(context)
                                                        .unfocus();
                                                  });
                                                }
                                              },
                                            ),
                                          )
                                        : null,
                                    filled: true,
                                    fillColor: const Color.fromARGB(
                                        150, 226, 232, 247),
                                    border: OutlineInputBorder(
                                      borderSide: BorderSide.none,
                                      borderRadius: BorderRadius.circular(16),
                                    ),
                                  ),
                                  onChanged: (searchText) {
                                    if (mounted) {
                                      setState(() {
                                        filteredApplets =
                                            appletsDocs.where((doc) {
                                          final appletData =
                                              Applet.fromMap(doc.data());
                                          return appletData.title
                                                  .toLowerCase()
                                                  .contains(searchText
                                                      .toLowerCase()) ||
                                              appletData.userName
                                                  .toLowerCase()
                                                  .contains(
                                                      searchText.toLowerCase());
                                        }).toList();
                                      });
                                    }
                                  },
                                )), // SearchBar
                            const SizedBox(height: 20),
                            Wrap(
                              children: List.generate(filteredApplets.length,
                                  (index) {
                                final Applet appletData = Applet.fromMap(
                                    filteredApplets[index].data());
                                return AppletCard(
                                  appletData: appletData,
                                  appletDoc: filteredApplets[index],
                                  marketPlace: true,
                                );
                              }),
                            ),
                          ],
                        );
                      },
                    ),
                  ],
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
