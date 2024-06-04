class Trigger {
  String service;
  String type;
  List<dynamic> values;

  Trigger({
    required this.service,
    required this.type,
    required this.values,
  });

  factory Trigger.fromMap(Map<String, dynamic> triggerMap) {
    return Trigger(
      service: triggerMap['service'],
      type: triggerMap['type'],
      values: triggerMap['values'],
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
