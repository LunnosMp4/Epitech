import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:fluttertoast/fluttertoast.dart';
import 'cloud_firestore_service.dart';

void registerForAuthStateChanges() {
  FirebaseAuth.instance.authStateChanges().listen((User? user) {
    if (user == null) {
      Fluttertoast.showToast(
          msg: "Utilisateur déconnecté",
          toastLength: Toast.LENGTH_SHORT,
          gravity: ToastGravity.BOTTOM,
          timeInSecForIosWeb: 1,
          webPosition: "center"
      );
    } else {
      Fluttertoast.showToast(
          msg: "Utilisateur connecté",
          toastLength: Toast.LENGTH_SHORT,
          gravity: ToastGravity.BOTTOM,
          timeInSecForIosWeb: 1,
          webPosition: "center"
      );
    }
  });
}

User? getCurrentUser() {
  return FirebaseAuth.instance.currentUser;
}

String? getCurrentUserEmail() {
  return FirebaseAuth.instance.currentUser?.email;
}

String? getCurrentUserUid() {
  return FirebaseAuth.instance.currentUser?.uid;
}

String? getCurrentUserName() {
  return FirebaseAuth.instance.currentUser?.displayName;
}

String? getCurrentUserPhotoUrl() {
  return FirebaseAuth.instance.currentUser?.photoURL;
}

bool? getCurrentUserEmailVerificationStatus() {
  return FirebaseAuth.instance.currentUser?.emailVerified;
}

Future<void> signUpByEmail(String email, String password, VoidCallback onSignedUp) async {
  try {
    UserCredential userCredential = await FirebaseAuth.instance
        .createUserWithEmailAndPassword(email: email, password: password);
    if (userCredential.user != null) {
      CloudFireStoreService.createUserDocument();
      onSignedUp();
    }
  } on FirebaseAuthException catch (e) {
    weakPassword(e.code);
    emailAlreadyInUse(e.code);
    unknownError(e.code);
  }
}

Future<void> signInByEmail(String email, String password, VoidCallback onSignedIn) async {
  try {
    UserCredential userCredential = await FirebaseAuth.instance
        .signInWithEmailAndPassword(email: email, password: password);
    if (userCredential.user != null) {
      onSignedIn();
    }
  } on FirebaseAuthException catch (e) {
    wrongPassword(e.code);
    userNotFound(e.code);
    unknownError(e.code);
  }
}

Future<void> signOut(VoidCallback onSignOut) async {
  if (FirebaseAuth.instance.currentUser == null) {
    onSignOut();
  }
  await FirebaseAuth.instance.signOut();
  onSignOut();
}

Future<bool> deleteUser() async {
  try {
    await FirebaseAuth.instance.currentUser!.delete();
    return true;
  } on FirebaseAuthException catch (e) {
    requiresRecentLogin(e.code);
    unknownError(e.code);
    return false;
  }
}

Future<void> sendPasswordResetEmail(String email) async {
  try {
    await FirebaseAuth.instance.sendPasswordResetEmail(email: email);
    print('Password reset email sent.');
  } catch (error) {
    print(error);
  }
}

Future<bool> updateEmail(String email) async {
  try {
    await FirebaseAuth.instance.currentUser!.updateEmail(email);
    return true;
  } on FirebaseAuthException catch (e) {
    emailAlreadyInUse(e.code);
    requiresRecentLogin(e.code);
    unknownError(e.code);
    return false;
  }
}

Future<bool> updatePassword(String password) async {
  try {
    await FirebaseAuth.instance.currentUser!.updatePassword(password);
    return true;
  } on FirebaseAuthException catch (e) {
    emailAlreadyInUse(e.code);
    weakPassword(e.code);
    requiresRecentLogin(e.code);
    unknownError(e.code);
    return false;
  }
}

void weakPassword(String code) {
  if (code == 'weak-password') {
    Fluttertoast.showToast(
        msg: "The password provided is too weak.",
        toastLength: Toast.LENGTH_SHORT,
        gravity: ToastGravity.CENTER,
        timeInSecForIosWeb: 1,
        webPosition: "center",
        backgroundColor: Colors.redAccent,
        textColor: Colors.white,
        fontSize: 16.0
    );
  }
}

void emailAlreadyInUse(String code) {
  if (code == 'email-already-in-use') {
    Fluttertoast.showToast(
        msg: "The account already exists for that email.",
        toastLength: Toast.LENGTH_SHORT,
        gravity: ToastGravity.CENTER,
        timeInSecForIosWeb: 1,
        webPosition: "center",
        backgroundColor: Colors.redAccent,
        textColor: Colors.white,
        fontSize: 16.0
    );
  }
}

void requiresRecentLogin(String code) {
  if (code == 'requires-recent-login') {
    Fluttertoast.showToast(
        msg: "The user must reauthenticate before this operation can be executed.",
        toastLength: Toast.LENGTH_SHORT,
        gravity: ToastGravity.CENTER,
        timeInSecForIosWeb: 1,
        webPosition: "center",
        backgroundColor: Colors.redAccent,
        textColor: Colors.white,
        fontSize: 16.0
    );
  }
}

void wrongPassword(String code) {
  if (code == 'wrong-password') {
    Fluttertoast.showToast(
        msg: "Wrong password provided for that user.",
        toastLength: Toast.LENGTH_SHORT,
        gravity: ToastGravity.CENTER,
        timeInSecForIosWeb: 1,
        webPosition: "center",
        backgroundColor: Colors.redAccent,
        textColor: Colors.white,
        fontSize: 16.0
    );
  }
}

void userNotFound(String code) {
  if (code == 'user-not-found') {
    Fluttertoast.showToast(
        msg: "No user found for that email.",
        toastLength: Toast.LENGTH_SHORT,
        gravity: ToastGravity.CENTER,
        timeInSecForIosWeb: 1,
        webPosition: "center",
        backgroundColor: Colors.redAccent,
        textColor: Colors.white,
        fontSize: 16.0
    );
  }
}

void unknownError(String code) {
  if (code == 'unknown') {
    Fluttertoast.showToast(
        msg: "An unknown error occurred.",
        toastLength: Toast.LENGTH_SHORT,
        gravity: ToastGravity.CENTER,
        timeInSecForIosWeb: 1,
        webPosition: "center",
        backgroundColor: Colors.redAccent,
        textColor: Colors.white,
        fontSize: 16.0
    );
  }
}
