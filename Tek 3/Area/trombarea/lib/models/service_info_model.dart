class ServiceInfo {
  final String name;
  final String title;
  final bool isPlatform;
  final List<String> types;
  final List<String> typesTitle;
  final List<List<dynamic>> values;

  ServiceInfo(this.name, this.title, this.isPlatform, this.types, this.typesTitle, this.values);
}
