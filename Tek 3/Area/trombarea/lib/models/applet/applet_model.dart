import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:trombarea/models/applet/action_model.dart' as applet_action;
import 'package:trombarea/models/applet/trigger_model.dart' as applet_trigger;

class Applet {
  Applet({
    required this.action,
    required this.active,
    required this.createTime,
    required this.favoritesCounter,
    required this.runTime,
    required this.oneShot,
    required this.public,
    required this.title,
    required this.trigger,
    required this.updateTime,
    required this.userUid,
    required this.userName,
  });

  List<applet_action.Action> action;
  bool active;
  Timestamp createTime;
  int favoritesCounter;
  List<Timestamp> runTime;
  bool oneShot;
  bool public;
  String title;
  applet_trigger.Trigger trigger;
  Timestamp updateTime;
  String userUid;
  String userName;

  Applet.fromMap(Map<String, dynamic> appletMap)
      : title = appletMap['title'],
        action = (appletMap['action'] as List<dynamic>)
            .map((actionData) => applet_action.Action.fromMap(actionData))
            .toList(),
        createTime = appletMap['createTime'],
        active = appletMap['active'],
        favoritesCounter = appletMap['favoritesCounter'],
        runTime = (appletMap['runTime'] as List<dynamic>)
            .map((timestampData) => Timestamp.fromDate(timestampData.toDate()))
            .toList(),
        oneShot = appletMap['oneShot'],
        public = appletMap['public'],
        trigger = applet_trigger.Trigger.fromMap(appletMap['trigger']),
        updateTime = appletMap['updateTime'],
        userUid = appletMap['userUid'],
        userName = appletMap['userName'];

  Map<String, dynamic> toMap() {
    return {
      'title': title,
      'action': action.map((a) => a.toMap()).toList(),
      'active': active,
      'createTime': createTime,
      'favoritesCounter': favoritesCounter,
      'oneShot': oneShot,
      'public': public,
      'runTime': runTime.map((t) => t.toDate()).toList(),
      'trigger': trigger.toMap(),
      'updateTime': updateTime,
      'userUid': userUid,
      'userName': userName,
    };
  }
}
