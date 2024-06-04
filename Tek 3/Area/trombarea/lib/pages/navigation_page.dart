import 'package:flutter/material.dart';
import 'package:material_symbols_icons/symbols.dart';
import 'package:trombarea/screens/applets/applets_screen.dart';
import 'package:trombarea/screens/create_applet_screen.dart';
import 'package:trombarea/screens/history_screen.dart';
import 'package:trombarea/screens/marketplace_screen.dart';
import 'package:trombarea/screens/profile_screen.dart';
import 'package:trombarea/responsive.dart';

class NavigationPage extends StatefulWidget {
  const NavigationPage({Key? key});

  @override
  State<NavigationPage> createState() => _NavigationPageState();
}

class _NavigationPageState extends State<NavigationPage> {
  int currentPageIndex = 0;

  @override
  Widget build(BuildContext context) {
    final isMobile = Responsive.isMobile(context);

    if (isMobile) {
      return mobileLayout(context);
    } else {
      return desktopLayout();
    }
  }

  Scaffold desktopLayout() {
    return Scaffold(
      body: Row(
        children: [
          NavigationRail(
            selectedIndex: currentPageIndex,
            indicatorColor: Colors.transparent,
            groupAlignment: 0,
            selectedLabelTextStyle:
                const TextStyle(fontWeight: FontWeight.w700),
            destinations: <NavigationRailDestination>[
              NavigationRailDestination(
                  icon: const Icon(Symbols.view_comfy_alt_rounded),
                  selectedIcon: Icon(Symbols.view_cozy,
                      fill: 1, color: Theme.of(context).colorScheme.primary),
                  label: const Text('Applets'),
                  padding: const EdgeInsets.symmetric(vertical: 40)),
              NavigationRailDestination(
                  icon: const Icon(Symbols.shop),
                  selectedIcon: Icon(Symbols.shop_two,
                      fill: 1, color: Theme.of(context).colorScheme.primary),
                  label: const Text('Marketplace'),
                  padding: const EdgeInsets.symmetric(vertical: 40)),
              NavigationRailDestination(
                  icon: const Icon(Symbols.add_circle_outline, size: 34),
                  selectedIcon: Icon(Symbols.add_circle,
                      size: 34,
                      fill: 1,
                      color: Theme.of(context).colorScheme.primary),
                  label: const Text('Créer applet'),
                  padding: const EdgeInsets.symmetric(vertical: 40)),
              NavigationRailDestination(
                  icon: const Icon(Symbols.history),
                  selectedIcon: Icon(Symbols.history_toggle_off,
                      fill: 1, color: Theme.of(context).colorScheme.primary),
                  label: const Text('Historique'),
                  padding: const EdgeInsets.symmetric(vertical: 40)),
              NavigationRailDestination(
                  icon: const Icon(Symbols.person),
                  selectedIcon: Icon(Symbols.person_3,
                      fill: 1, color: Theme.of(context).colorScheme.primary),
                  label: const Text('Profile'),
                  padding: const EdgeInsets.symmetric(vertical: 40)),
            ],
            onDestinationSelected: (int index) {
              if (mounted) {
                setState(() {
                  currentPageIndex = index;
                });
              }
            },
          ),
          const VerticalDivider(
              thickness: 1,
              width: 1,
              indent: 20,
              endIndent: 20,
              color: Color.fromARGB(14, 0, 0, 0)),
          Expanded(
            child: IndexedStack(
              index: currentPageIndex,
              children: const <Widget>[
                AppletsScreen(),
                MarketplaceScreen(),
                CreateAppletScreen(),
                HistoryScreen(),
                ProfileScreen(),
              ],
            ),
          ),
        ],
      ),
    );
  }

  Scaffold mobileLayout(BuildContext context) {
    return Scaffold(
      bottomNavigationBar: NavigationBar(
        labelBehavior: NavigationDestinationLabelBehavior.onlyShowSelected,
        selectedIndex: currentPageIndex,
        indicatorColor: Theme.of(context).colorScheme.primary.withOpacity(0.1),
        elevation: 0,
        onDestinationSelected: (int index) {
          if (mounted) {
            setState(() {
              currentPageIndex = index;
            });
          }
        },
        destinations: <Widget>[
          const NavigationDestination(
            icon: Icon(Symbols.view_comfy_alt_rounded),
            selectedIcon: Icon(Symbols.view_cozy),
            label: 'Applets',
          ),
          const NavigationDestination(
            icon: Icon(Symbols.shop),
            selectedIcon: Icon(Symbols.shop_two),
            label: 'Marketplace',
          ),
          NavigationDestination(
            icon: const Icon(Symbols.add_circle_outline, size: 32),
            selectedIcon: Icon(Symbols.add_circle,
                size: 34,
                fill: 1,
                color: Theme.of(context).colorScheme.primary),
            label: 'Créer applet',
          ),
          const NavigationDestination(
            icon: Icon(Symbols.history),
            selectedIcon: Icon(Symbols.history_toggle_off),
            label: 'Historique',
          ),
          const NavigationDestination(
            icon: Icon(Symbols.person),
            selectedIcon: Icon(Symbols.person_3),
            label: 'Profile',
          ),
        ],
      ),
      body: IndexedStack(
        index: currentPageIndex,
        children: const <Widget>[
          AppletsScreen(),
          MarketplaceScreen(),
          CreateAppletScreen(),
          HistoryScreen(),
          ProfileScreen(),
        ],
      ),
    );
  }
}
