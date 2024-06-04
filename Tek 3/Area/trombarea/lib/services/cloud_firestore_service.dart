import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:trombarea/models/applet/applet_model.dart';
import 'package:trombarea/services/firebase_auth_service.dart';
import 'package:trombarea/models/user/user_model.dart' as user;

class CloudFireStoreService {
  static final FirebaseFirestore _firestore = FirebaseFirestore.instance;
  static final String? _userUid = getCurrentUserUid();

  static CollectionReference<Map<String, dynamic>> get appletsCollection =>
      _firestore.collection('applets');

  static CollectionReference<Map<String, dynamic>> get usersCollection =>
      _firestore.collection('users');

  static Future<void> createUserDocument() async {
    final userDoc = usersCollection.doc(_userUid);

    await userDoc.set({
      'favorites': <String>[],
      'discordWebhook': '',
      'slackWebhook': '',
      'teamsWebhook': '',
      'telegramWebhook': '',
      'location': const GeoPoint(0, 0),
    });
  }

  static Future<bool> userDocumentExists() async {
    final userDoc = usersCollection.doc(_userUid);

    final userDocSnapshot = await userDoc.get();

    return userDocSnapshot.exists;
  }

  static Stream<List<String>> getUserFavoritesStream() {
    return usersCollection.doc(_userUid).snapshots().map((userDoc) {
      final userFavorites = userDoc.data()?['favorites'] as List<dynamic>;
      if (userFavorites == null) {
        return <String>[];
      }
      return userFavorites.cast<String>();
    });
  }

  static Future<void> addAppletToFavorites(String appletId) async {
    final userDoc = usersCollection.doc(_userUid);

    // Récupérez la liste des favoris actuelle de l'utilisateur.
    final userFavorites = await userDoc.get().then((userDoc) {
      final data = userDoc.data();
      if (data != null) {
        final dynamic favorites = data['favorites'];
        if (favorites is List<dynamic>) {
          return favorites.whereType<String>().toList();
        }
      }
      return <String>[];
    });

    // Ajoutez l'ID de l'applet aux favoris s'il n'est pas déjà dans la liste.
    if (!userFavorites.contains(appletId)) {
      userFavorites.add(appletId);
      // Mettez à jour la liste des favoris de l'utilisateur.
      await userDoc.update({'favorites': userFavorites});
    }
  }

  static Future<void> removeAppletFromFavorites(String appletId) async {
    final userDoc = usersCollection.doc(_userUid);

    // Récupérez la liste des favoris actuelle de l'utilisateur.
    final userFavorites = await userDoc.get().then((userDoc) {
      final data = userDoc.data();
      if (data != null) {
        final dynamic favorites = data['favorites'];
        if (favorites is List<dynamic>) {
          return favorites.whereType<String>().toList();
        }
      }
      return <String>[];
    });

    // Supprimez l'ID de l'applet des favoris s'il est présent dans la liste.
    if (userFavorites.contains(appletId)) {
      userFavorites.remove(appletId);
      // Mettez à jour la liste des favoris de l'utilisateur.
      await userDoc.update({'favorites': userFavorites});
    }
  }

  static Future<String> getNewDocumentId() async {
    QuerySnapshot querySnapshot = await appletsCollection.get();
    int highestId = 0;

    for (var doc in querySnapshot.docs) {
      try {
        int currentId = int.parse(doc.id);
        if (currentId > highestId) {
          highestId = currentId;
        }
      } catch (e) {
        print("Error converting id: $e");
      }
    }

    return (highestId + 1).toString();
  }

  static Future<void> addApplet(Applet applet) async {
    final appletData = applet.toMap();
    final newDocumentId = await getNewDocumentId();
    final newAppletDoc = appletsCollection.doc(newDocumentId);

    await newAppletDoc.set(appletData);
  }

  static Future<String> getDiscordWebhook() async {
    final userDoc = usersCollection.doc(_userUid);

    final userWebhook = await userDoc.get().then((userDoc) {
      final user.User userData = user.User.fromMap(userDoc.data()!);

      final dynamic discordWebhook = userData.discordWebhook;
      if (discordWebhook is String) {
        return discordWebhook;
      }
      return '';
    });

    return userWebhook;
  }

  static Future<void> setDiscordWebhook(String webhook) async {
    final userDoc = usersCollection.doc(_userUid);

    await userDoc.update({'discordWebhook': webhook});
  }

  static Future<String> getSlackWebhook() async {
    final userDoc = usersCollection.doc(_userUid);

    final userWebhook = await userDoc.get().then((userDoc) {
      final user.User userData = user.User.fromMap(userDoc.data()!);
      final dynamic slackWebhook = userData.slackWebhook;
      if (slackWebhook is String) {
        return slackWebhook;
      }
      return '';
    });

    return userWebhook;
  }

  static Future<void> setSlackWebhook(String webhook) async {
    final userDoc = usersCollection.doc(_userUid);

    await userDoc.update({'slackWebhook': webhook});
  }

  static Future<String> getTeamsWebhook() async {
    final userDoc = usersCollection.doc(_userUid);

    final userWebhook = await userDoc.get().then((userDoc) {
      final user.User userData = user.User.fromMap(userDoc.data()!);
      final dynamic teamsWebhook = userData.teamsWebhook;
      if (teamsWebhook is String) {
        return teamsWebhook;
      }
      return '';
    });

    return userWebhook;
  }

  static Future<void> setTeamsWebhook(String webhook) async {
    final userDoc = usersCollection.doc(_userUid);

    await userDoc.update({'teamsWebhook': webhook});
  }

  static Future<String> getTelegramWebhook() async {
    final userDoc = usersCollection.doc(_userUid);

    final userWebhook = await userDoc.get().then((userDoc) {
      final user.User userData = user.User.fromMap(userDoc.data()!);
      final dynamic telegramWebhook = userData.telegramWebhook;
      if (telegramWebhook is String) {
        return telegramWebhook;
      }
      return '';
    });

    return userWebhook;
  }

  static Future<void> setTelegramWebhook(String webhook) async {
    final userDoc = usersCollection.doc(_userUid);

    await userDoc.update({'telegramWebhook': webhook});
  }

  static Future<GeoPoint> getLocation() async {
    final userDoc = usersCollection.doc(_userUid);

    final userLocation = await userDoc.get().then((userDoc) {
      final user.User userData = user.User.fromMap(userDoc.data()!);
      final dynamic location = userData.location;
      if (location is GeoPoint) {
        return location;
      }
      return const GeoPoint(0, 0);
    });

    return userLocation;
  }

  static Future<void> setLocation(GeoPoint location) async {
    final userDoc = usersCollection.doc(_userUid);

    await userDoc.update({'location': location});
  }
}
