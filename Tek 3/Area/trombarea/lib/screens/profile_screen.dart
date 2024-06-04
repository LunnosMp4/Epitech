import 'dart:ui';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:fluttertoast/fluttertoast.dart';
import 'package:trombarea/responsive.dart';
import 'package:trombarea/services/firebase_auth_service.dart';
import 'package:trombarea/services/google_auth_service.dart';
import 'package:trombarea/services/cloud_firestore_service.dart';
import 'package:trombarea/widgets/google_account_widget.dart';
import 'package:trombarea/widgets/profile_elevated_button_widget.dart';
import 'package:trombarea/widgets/web_title_widget.dart';
import 'package:flutter_dotenv/flutter_dotenv.dart';
import 'package:url_launcher/url_launcher.dart';
import 'dart:convert';
import 'dart:math';
import 'package:crypto/crypto.dart';
import 'package:flutter/services.dart';

class ProfileScreen extends StatefulWidget {
  const ProfileScreen({Key? key}) : super(key: key);

  @override
  _ProfileScreenState createState() => _ProfileScreenState();
}

class _ProfileScreenState extends State<ProfileScreen> {
  final GoogleAuthService _googleAuthService = GoogleAuthService();
  User? user = getCurrentUser();

  Future<void> _handleSignOut() async {
    if (user!.providerData[0].providerId == 'google.com') {
      await _googleAuthService.signOutGoogle();
    }
    signOut(() {
      Navigator.pop(context);
    });
  }

  Future<String?> _findUserId(String email) async {
    final collection = FirebaseFirestore.instance.collection('users');
    final querySnapshot = await collection.where('email', isEqualTo: email).get();

    if (querySnapshot.docs.isNotEmpty) {
      return querySnapshot.docs.first.id;
    }

    return null;
  }

  Future<bool> updateCollectionData(String collection, String username, String dataName, dynamic newValue) async {
    final FirebaseFirestore firestore = FirebaseFirestore.instance;
    final DocumentReference documentRef = firestore.collection(collection).doc(username);

    try {
      await documentRef.update({
        dataName: newValue
      });
      return true;
    } catch (error) {
      print("Erreur lors de la mise à jour du document: $error");
      return false;
    }
  }

  String _generateCodeVerifier2() {
    var random = Random.secure();
    var values = List<int>.generate(32, (i) => random.nextInt(256));
    return base64Url.encode(values);
  }

  Future<String> _generateCodeChallenge2(String codeVerifier) async {
    var bytes = utf8.encode(codeVerifier);
    var digest = sha256.convert(bytes);
    return base64Url.encode(digest.bytes);
  }

  Future<void> _twitterConnection() async {
    await dotenv.load(fileName: ".env");
    final String? clientId = dotenv.env['TWITTER_CLIENT_ID'];
    User? user = FirebaseAuth.instance.currentUser;
    String email;
    if (user != null) {
      email = user.email ?? "Aucun email n'est associé à cet utilisateur";
    } else {
      return;
    }

    _findUserId(email).then((userId) async {
      String codeVerifier = _generateCodeVerifier2();
      updateCollectionData('users', userId.toString(), 'twitterCodeVerifier', codeVerifier);
      String codeChallenge = await _generateCodeChallenge2(codeVerifier);
      final Uri authUrl = Uri.https('twitter.com', '/i/oauth2/authorize', {
        'response_type': 'code',
        'client_id': clientId,
        'redirect_uri': 'http://localhost:8080/twitter_callback',
        'scope': 'tweet.read users.read follows.read follows.write',
        'state': userId,
        'code_challenge': codeChallenge,
        'code_challenge_method': 'S256',
      });

      if (await canLaunchUrl(authUrl)) {
        await launchUrl(authUrl);
      } else {
        throw 'Could not launch $authUrl';
      }
    });
  }

void _spotifyConnection() async {
  await dotenv.load(fileName: "assets/.env");
  User? user = FirebaseAuth.instance.currentUser;
  String email;
  if (user != null) {
    email = user.email ?? "Aucun email n'est associé à cet utilisateur";
  } else {
    return;
  }
  _findUserId(email).then((userId) async {
  if (userId != null) {
    final String? clientId = dotenv.env['SPOTIFY_CLIENT_ID'];
    const String redirectUri = 'http://localhost:8080/spotify_callback';
    final Uri url = Uri.parse('https://accounts.spotify.com/authorize?${Uri(queryParameters: {
      'state': userId,
      'response_type': 'code',
      'client_id': clientId,
      'scope': 'user-read-recently-played playlist-modify-public playlist-modify-private',
      'redirect_uri': redirectUri,
      'show_dialog': 'true',
    }).query}');
    if (await canLaunchUrl(url)) {
      await launchUrl(url);
    } else {
      throw 'Could not launch $url';
    }
  } else {
    print('Aucun utilisateur trouvé avec cet email');
  }
});
}

  Future<void> _confirmDeleteAccount(BuildContext context) async {
    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: const Text('Confirmation'),
          content: const Text(
              'Voulez-vous vraiment supprimer votre compte ? Cette action est irréversible.'),
          actions: <Widget>[
            TextButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              child: const Text('Annuler'),
            ),
            TextButton(
              onPressed: () async {
                Navigator.of(context).pop();
                bool deleted = await deleteUser();
                if (deleted) {
                  // Le compte a été supprimé avec succès.
                  // Vous pouvez naviguer vers une page de confirmation ou effectuer d'autres actions.
                  Fluttertoast.showToast(
                    msg: "Votre compte a été supprimé avec succès.",
                    toastLength: Toast.LENGTH_SHORT,
                    gravity: ToastGravity.CENTER,
                  );
                }
              },
              child: const Text('Confirmer'),
            ),
          ],
        );
      },
    );
  }

  Future<void> _confirmResetPassword(BuildContext context) async {
    final TextEditingController passwordController = TextEditingController();

    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: const Text('Réinitialisation du mot de passe'),
          content: Column(
            mainAxisSize: MainAxisSize.min,
            children: <Widget>[
              const Text(
                  'Voulez-vous vraiment réinitialiser votre mot de passe ?'),
              const SizedBox(height: 10),
              TextField(
                controller: passwordController,
                obscureText: true, // Pour masquer le mot de passe
                decoration: const InputDecoration(
                  labelText: 'Nouveau mot de passe',
                ),
              ),
            ],
          ),
          actions: <Widget>[
            TextButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              child: const Text('Annuler'),
            ),
            TextButton(
              onPressed: () async {
                Navigator.of(context).pop();
                String newPassword = passwordController.text;
                bool updated = await updatePassword(newPassword);
                if (updated) {
                  Fluttertoast.showToast(
                    msg: "Votre mot de passe a été réinitialisé avec succès.",
                    toastLength: Toast.LENGTH_SHORT,
                    gravity: ToastGravity.CENTER,
                  );
                }
              },
              child: const Text('Confirmer'),
            ),
          ],
        );
      },
    );
  }

  Future<void> _confirmUpdateEmail(BuildContext context) async {
    final TextEditingController emailController = TextEditingController();

    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: const Text('Mise à jour de l\'adresse e-mail'),
          content: Column(
            mainAxisSize: MainAxisSize.min,
            children: <Widget>[
              const Text(
                  'Voulez-vous vraiment mettre à jour votre adresse e-mail ?'),
              const SizedBox(height: 10),
              TextField(
                controller: emailController,
                decoration: const InputDecoration(
                  labelText: 'Nouvelle adresse e-mail',
                ),
              ),
            ],
          ),
          actions: <Widget>[
            TextButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              child: const Text('Annuler'),
            ),
            TextButton(
              onPressed: () async {
                Navigator.of(context).pop();
                String newEmail = emailController.text;
                bool updated = await updateEmail(newEmail);
                if (updated) {
                  Fluttertoast.showToast(
                    msg: "Votre adresse e-mail a été mise à jour avec succès.",
                    toastLength: Toast.LENGTH_SHORT,
                    gravity: ToastGravity.CENTER,
                  );
                }
              },
              child: const Text('Confirmer'),
            ),
          ],
        );
      },
    );
  }

  Future<void> _showEditDialog(BuildContext context) async {
    if (await CloudFireStoreService.userDocumentExists() == false) {
      CloudFireStoreService.createUserDocument();
    }

    String discordWebhook = await CloudFireStoreService.getDiscordWebhook();
    String slackWebhook = await CloudFireStoreService.getSlackWebhook();
    String teamsWebhook = await CloudFireStoreService.getTeamsWebhook();
    String telegramWebhook = await CloudFireStoreService.getTelegramWebhook();
    GeoPoint location = await CloudFireStoreService.getLocation();

    TextEditingController latitudeController =
        TextEditingController(text: location.latitude.toString());
    TextEditingController longitudeController =
        TextEditingController(text: location.longitude.toString());

    String modifiedDiscordWebhook = discordWebhook;
    String modifiedSlackWebhook = slackWebhook;
    String modifiedTeamsWebhook = teamsWebhook;
    String modifiedTelegramWebhook = telegramWebhook;
    GeoPoint modifiedLocation = location;

    // ignore: use_build_context_synchronously
    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: const Text('Modifier les informations'),
          content: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              TextFormField(
                initialValue: discordWebhook,
                onChanged: (value) {
                  modifiedDiscordWebhook = value;
                },
                decoration: const InputDecoration(labelText: 'Discord Webhook'),
              ),
              TextFormField(
                initialValue: slackWebhook,
                onChanged: (value) {
                  modifiedSlackWebhook = value;
                },
                decoration: const InputDecoration(labelText: 'Slack Webhook'),
              ),
              TextFormField(
                initialValue: teamsWebhook,
                onChanged: (value) {
                  modifiedTeamsWebhook = value;
                },
                decoration: const InputDecoration(labelText: 'Teams Webhook'),
              ),
              TextFormField(
                initialValue: telegramWebhook,
                onChanged: (value) {
                  modifiedTelegramWebhook = value;
                },
                decoration:
                    const InputDecoration(labelText: 'Telegram Webhook'),
              ),
              Row(
                children: [
                  Expanded(
                    child: TextFormField(
                      controller: latitudeController,
                      onChanged: (value) {
                        modifiedLocation =
                            GeoPoint(double.parse(value), location.longitude);
                      },
                      decoration: const InputDecoration(labelText: 'Latitude'),
                    ),
                  ),
                  const SizedBox(width: 16),
                  Expanded(
                    child: TextFormField(
                      controller: longitudeController,
                      onChanged: (value) {
                        modifiedLocation =
                            GeoPoint(location.latitude, double.parse(value));
                      },
                      decoration: const InputDecoration(labelText: 'Longitude'),
                    ),
                  ),
                ],
              ),
            ],
          ),
          actions: [
            TextButton(
              onPressed: () {
                modifiedDiscordWebhook = discordWebhook;
                modifiedSlackWebhook = slackWebhook;
                modifiedTeamsWebhook = teamsWebhook;
                modifiedTelegramWebhook = telegramWebhook;
                modifiedLocation = location;

                Navigator.pop(context);
              },
              child: const Text('Annuler'),
            ),
            TextButton(
              onPressed: () {
                CloudFireStoreService.setDiscordWebhook(modifiedDiscordWebhook);
                CloudFireStoreService.setSlackWebhook(modifiedSlackWebhook);
                CloudFireStoreService.setTeamsWebhook(modifiedTeamsWebhook);
                CloudFireStoreService.setTelegramWebhook(
                    modifiedTelegramWebhook);
                CloudFireStoreService.setLocation(modifiedLocation);

                Navigator.pop(context);
              },
              child: const Text('Enregistrer'),
            ),
          ],
        );
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    User? user = getCurrentUser();
    final isMobile = Responsive.isMobile(context);

    if (user == null) {
      return const Center(
        child: Text('Utilisateur non connecté'),
      );
    } else {
      if (isMobile) {
        return mobileLayout(user, context);
      } else {
        return desktopLayout(user, context);
      }
    }
  }

  SafeArea mobileLayout(User user, BuildContext context) {
    return SafeArea(
      child: Center(
        child: Container(
          padding: const EdgeInsets.all(16),
          decoration: const BoxDecoration(
            borderRadius: BorderRadius.all(Radius.circular(16)),
          ),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            mainAxisSize: MainAxisSize.min,
            children: [
              if (user.providerData[0].providerId == 'google.com')
                GoogleAccount(user: user, isMobile: true),
              const SizedBox(height: 16),
              Column(
                children: [
                  Text(
                    user.email ?? '',
                    style: Theme.of(context)
                        .textTheme
                        .titleLarge!
                        .copyWith(fontWeight: FontWeight.bold),
                  ),
                  const SizedBox(height: 80),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Expanded(
                        child: ProfileElevatedButton(
                          text: 'Login Twitter',
                          color: Colors.black87,
                          callback: () {
                            _twitterConnection();
                          },
                        ),
                      ),
                      const SizedBox(width: 16), // Espace entre les boutons
                      Expanded(
                        child: ProfileElevatedButton(
                          text: 'Login Spotify',
                          color: Colors.black87,
                          callback: () {
                            _spotifyConnection();
                          },
                        ),
                      ),
                    ],
                  ),
                  const SizedBox(height: 16),
                  ProfileElevatedButton(
                      text: 'Modifier Localisation et Webhooks',
                      color: Colors.black87,
                      callback: () {
                        _showEditDialog(context);
                      }),
                  if (user.providerData[0].providerId != 'google.com')
                    Column(
                      children: [
                        const SizedBox(height: 16),
                        ProfileElevatedButton(
                            text: 'Modifier mon adresse email',
                            color: Colors.black87,
                            callback: () {
                              _confirmUpdateEmail(context);
                            }),
                        const SizedBox(height: 16),
                        ProfileElevatedButton(
                            text: 'Modifier mon mot de passse',
                            color: Colors.black87,
                            callback: () {
                              _confirmResetPassword(context);
                            }),
                      ],
                    ),
                  const SizedBox(height: 16),
                  ProfileElevatedButton(
                      text: 'Supprimer mon compte',
                      color: Colors.red.shade900,
                      callback: () {
                        _confirmDeleteAccount(context);
                      }),
                  const SizedBox(height: 16),
                  ProfileElevatedButton(
                      text: 'Déconnexion',
                      color: Colors.black54,
                      callback: () {
                        _handleSignOut();
                      }),
                ],
              ),
            ],
          ),
        ),
      ),
    );
  }

  SafeArea desktopLayout(User user, BuildContext context) {
    return SafeArea(
      child: Stack(
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
            child: ClipRect(
              child: BackdropFilter(
                filter: ImageFilter.blur(sigmaX: 2, sigmaY: 2),
                child: Column(
                  children: [
                    const WebTitle(title: 'Mon Profile'),
                    Container(
                      width: 700,
                      padding: const EdgeInsets.all(10),
                      child: Column(
                        mainAxisAlignment: MainAxisAlignment.center,
                        mainAxisSize: MainAxisSize.min,
                        children: [
                          if (user.providerData[0].providerId == 'google.com')
                            GoogleAccount(user: user, isMobile: false),
                          Column(
                            children: [
                              Text(
                                user.email ?? '',
                                style: Theme.of(context)
                                    .textTheme
                                    .headlineMedium!
                                    .copyWith(fontWeight: FontWeight.bold),
                              ),
                              const SizedBox(height: 30),
                              Row(
                                mainAxisAlignment: MainAxisAlignment.center,
                                children: [
                                  Expanded(
                                    child: ProfileElevatedButton(
                                      text: 'Connection Twitter',
                                      color: Colors.black87,
                                      callback: () {
                                        _twitterConnection();
                                      },
                                      desktopVersion: true,
                                    ),
                                  ),
                                  const SizedBox(width: 30),
                                  Expanded(
                                    child: ProfileElevatedButton(
                                      text: 'Connection Spotify',
                                      color: Colors.black87,
                                      callback: () {
                                        _spotifyConnection();
                                      },
                                      desktopVersion: true,
                                    ),
                                  ),
                                ],
                              ),
                              const SizedBox(height: 30),
                              ProfileElevatedButton(
                                  text: 'Modifier Localisation et Webhooks',
                                  color: Colors.black87,
                                  callback: () {
                                    _showEditDialog(context);
                                  },
                                  desktopVersion: true),
                              if (user.providerData[0].providerId !=
                                  'google.com')
                                Column(
                                  children: [
                                    const SizedBox(height: 30),
                                    ProfileElevatedButton(
                                        text: 'Modifier mon adresse email',
                                        color: Colors.black87,
                                        callback: () {
                                          _confirmUpdateEmail(context);
                                        },
                                        desktopVersion: true),
                                    const SizedBox(height: 30),
                                    ProfileElevatedButton(
                                        text: 'Modifier mon mot de passse',
                                        color: Colors.black87,
                                        callback: () {
                                          _confirmResetPassword(context);
                                        },
                                        desktopVersion: true),
                                  ],
                                ),
                              const SizedBox(height: 30),
                              ProfileElevatedButton(
                                  text: 'Supprimer mon compte',
                                  color: Colors.red.shade900,
                                  callback: () {
                                    _confirmDeleteAccount(context);
                                  },
                                  desktopVersion: true),
                              const SizedBox(height: 30),
                              ProfileElevatedButton(
                                  text: 'Déconnexion',
                                  color: Colors.black54,
                                  callback: () {
                                    _handleSignOut();
                                  },
                                  desktopVersion: true),
                            ],
                          ),
                        ],
                      ),
                    ),
                  ],
                ),
              ),
            ),
          ),
        ],
      ),
    );
  }
}
