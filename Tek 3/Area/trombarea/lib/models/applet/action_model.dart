class Platform {
  String service;
  String type;
  List<dynamic> values;

  Platform({
    required this.service,
    required this.type,
    required this.values,
  });

  factory Platform.fromMap(Map<String, dynamic> map) {
    return Platform(
      service: map['service'],
      type: map['type'],
      values: map['values'],
    );
  }

  Map<String, dynamic> toMap() {
    return {
      'service': service,
      'type': type,
      'values': values,
    };
  }
}

class Action {
  String service;
  Platform? platform;
  String type;
  List<dynamic> values;

  Action({
    required this.service,
    this.platform,
    required this.type,
    required this.values,
  });

  factory Action.fromMap(Map<String, dynamic> actionMap) {
    final Map<String, dynamic>? platformMap = actionMap['platform'] as Map<String, dynamic>?;
    return Action(
      service: actionMap['service'],
      platform: platformMap != null ? Platform.fromMap(platformMap) : null,
      type: actionMap['type'],
      values: actionMap['values'],
    );
  }

  Map<String, dynamic> toMap() {
    return {
      'service': service,
      'platform': platform?.toMap(),
      'type': type,
      'values': values,
    };
  }
}
