import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:trombarea/models/applet/action_model.dart' as applet_action;
import 'package:trombarea/models/applet/trigger_model.dart' as applet_trigger;
import 'package:trombarea/models/applet/applet_model.dart';
import 'package:trombarea/models/service_info_model.dart';
import 'package:trombarea/responsive.dart';
import 'package:trombarea/services/cloud_firestore_service.dart';
import 'package:trombarea/services/firebase_auth_service.dart';
import 'package:trombarea/services/getservice_service.dart';
import 'package:trombarea/widgets/block_card_widget.dart';
import 'package:trombarea/widgets/large_button_widget.dart';
import 'package:trombarea/widgets/service_card_widget.dart';
import 'package:trombarea/constants.dart';
import 'package:trombarea/widgets/web_title_widget.dart';

class CreateAppletScreen extends StatefulWidget {
  const CreateAppletScreen({
    Key? key,
  }) : super(key: key);

  @override
  _CreateAppletScreenState createState() => _CreateAppletScreenState();
}

class _CreateAppletScreenState extends State<CreateAppletScreen> {
  TextEditingController titleController = TextEditingController();
  String? selectedTriggerService;
  String? selectedActionService;
  String? selectedPlatformService;
  String selectedTriggerType = '';
  String selectedActionType = '';
  String selectedPlatformType = '';
  List<dynamic> tempSelectedTriggerValues = [];
  List<dynamic> tempSelectedActionValues = [];
  List<dynamic> tempSelectedPlatformValues = [];
  List<dynamic> selectedTriggerValues = [];
  List<dynamic> selectedActionValues = [];
  List<dynamic> selectedPlatformValues = [];
  bool isOneShot = false;
  bool isPublic = true;
  bool needPlatform = false;

  void showServiceSelectionDialog(
      BuildContext context, bool isTrigger, bool isPlatform) {
    showDialog(
      context: context,
      builder: (context) {
        return Dialog(
          child: SingleChildScrollView(
            child: Padding(
              padding: const EdgeInsets.all(20),
              child: Column(
                mainAxisSize: MainAxisSize.min,
                mainAxisAlignment: MainAxisAlignment.center,
                children: <Widget>[
                  Text('Services',
                      style: Theme.of(context)
                          .textTheme
                          .titleLarge!
                          .copyWith(letterSpacing: 1.5)),
                  const SizedBox(height: 15),
                  Wrap(
                    spacing: 12,
                    runSpacing: 12,
                    children: getServiceCards(context, isTrigger, isPlatform),
                  ),
                  const SizedBox(height: 20),
                  TextButton(
                    onPressed: () {
                      Navigator.pop(context);
                    },
                    child: const Text('Annuler'),
                  ),
                ],
              ),
            ),
          ),
        );
      },
    );
  }

  List<ServiceCard> getServiceCards(
      BuildContext context, bool isTrigger, isPlatform) {
    final List<ServiceInfo> services = isTrigger
        ? triggerServices
        : isPlatform
            ? actionServices
                .where((serviceInfo) => serviceInfo.isPlatform)
                .toList()
            : actionServices;

    return services.map((service) {
      return ServiceCard(
        name: service.name,
        title: service.title,
        callback: () {
          Navigator.pop(context);
          showTypesSelectionDialog(context, service, isTrigger, isPlatform);
        },
      );
    }).toList();
  }

  void showTypesSelectionDialog(BuildContext context, ServiceInfo service,
      bool isTrigger, bool isPlatform) {
    showDialog(
      context: context,
      builder: (context) {
        return Dialog(
          child: Padding(
            padding: const EdgeInsets.all(25),
            child: Column(
              mainAxisSize: MainAxisSize.min,
              mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                Text(
                    'Choisissez ${isTrigger ? 'un trigger' : isPlatform ? 'une plateforme' : 'une action'}',
                    style: Theme.of(context)
                        .textTheme
                        .titleLarge!
                        .copyWith(letterSpacing: 1.5)),
                const SizedBox(height: 15),
                Column(
                  mainAxisSize: MainAxisSize.max,
                  children: getServiceTypeButtons(
                      context, service, isTrigger, isPlatform),
                ),
                const SizedBox(height: 20),
                TextButton(
                  onPressed: () {
                    Navigator.pop(context);
                  },
                  child: const Text('Annuler'),
                ),
              ],
            ),
          ),
        );
      },
    );
  }

  List<Widget> getServiceTypeButtons(BuildContext context, ServiceInfo service,
      bool isTrigger, bool isPlatform) {
    return service.typesTitle.asMap().entries.map((entry) {
      int index = entry.key;
      String typeTitle = entry.value;

      return Padding(
        padding: const EdgeInsets.all(8.0),
        child: ElevatedButton(
          onPressed: () {
            Navigator.pop(context);
            showValueSelectionDialog(
                context, service, index, isTrigger, isPlatform);
          },
          style: ButtonStyle(
              elevation: MaterialStateProperty.all(10),
              backgroundColor:
                  MaterialStateProperty.all(getServiceColor(service.name)),
              shape: MaterialStateProperty.all<RoundedRectangleBorder>(
                  RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(10)))),
          child: Text(typeTitle,
              style: Theme.of(context)
                  .textTheme
                  .labelLarge!
                  .copyWith(color: Colors.white70)),
        ),
      );
    }).toList();
  }

  void showValueSelectionDialog(BuildContext context, ServiceInfo service,
      int selectedTypeIndex, bool isTrigger, bool isPlatform) {
    showDialog(
      context: context,
      builder: (context) {
        return Dialog(
          child: Padding(
            padding: const EdgeInsets.all(25),
            child: Column(
              mainAxisSize: MainAxisSize.min,
              mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                Text('Sélectionnez les valeurs',
                    style: Theme.of(context)
                        .textTheme
                        .titleLarge!
                        .copyWith(letterSpacing: 1.5)),
                const SizedBox(height: 15),
                Column(
                  children: getValueSelectionWidgets(context, service,
                      selectedTypeIndex, isTrigger, isPlatform),
                ),
                const SizedBox(height: 15),
                Row(
                  children: [
                    TextButton(
                      onPressed: () {
                        Navigator.pop(context);
                      },
                      child: const Text('Annuler'),
                    ),
                    const SizedBox(height: 20),
                    TextButton(
                      onPressed: () {
                        if (mounted) {
                          setState(() {
                            if (isTrigger) {
                              selectedTriggerService = service.name;
                              selectedTriggerType =
                                  service.types[selectedTypeIndex];
                              selectedTriggerValues =
                                  List.from(tempSelectedTriggerValues);
                            } else if (isPlatform) {
                              selectedPlatformService = service.name;
                              selectedPlatformType =
                                  service.types[selectedTypeIndex];
                              selectedPlatformValues =
                                  List.from(tempSelectedPlatformValues);
                            } else {
                              selectedActionService = service.name;
                              selectedActionType =
                                  service.types[selectedTypeIndex];
                              selectedActionValues =
                                  List.from(tempSelectedActionValues);
                            }
                            Navigator.of(context).pop();
                            if (selectedActionType.startsWith('get')) {
                              selectedActionType =
                                  selectedActionType.substring(3).toLowerCase();
                              needPlatform = true;
                            }
                          });
                        }
                      },
                      child: const Text('Valider'),
                    ),
                  ],
                ),
              ],
            ),
          ),
        );
      },
    );
  }

  List<Widget> getValueSelectionWidgets(
      BuildContext context,
      ServiceInfo service,
      int selectedTypeIndex,
      bool isTrigger,
      bool isPlatform) {
    List<Widget> valueWidgets = [];
    if (isTrigger) {
      tempSelectedTriggerValues = List.from(service.values[selectedTypeIndex]);
    } else if (isPlatform) {
      tempSelectedPlatformValues = List.from(service.values[selectedTypeIndex]);
    } else {
      tempSelectedActionValues = List.from(service.values[selectedTypeIndex]);
    }

    for (var index = 0;
        index < service.values[selectedTypeIndex].length;
        index++) {
      var value = service.values[selectedTypeIndex][index];
      if (value is String) {
        final String labelValue = value;
        // Utilisez l'index pour accéder à la variable temporaire correspondante
        TextEditingController controller = TextEditingController(
            text: tempSelectedValue(isTrigger, isPlatform, index));
        valueWidgets.add(
          TextField(
            controller: controller,
            decoration: InputDecoration(labelText: labelValue),
            onChanged: (newValue) {
              // Mise à jour de la variable temporaire correspondante
              updateTempSelectedValue(isTrigger, isPlatform, index, newValue);
            },
          ),
        );
      } else if (value is List && value.isNotEmpty) {
        Set<dynamic> uniqueValues = Set<dynamic>.from(value);
        List<DropdownMenuItem<dynamic>> dropdownItems = uniqueValues
            .map((item) => DropdownMenuItem<dynamic>(
                  value: item,
                  child: FaIcon(
                      getServiceIcon(service.name,
                          service.types[selectedTypeIndex], item.toString()),
                      color: Colors.black54),
                ))
            .toList();
        dynamic selectedValue =
            tempSelectedValue(isTrigger, isPlatform, index)[0];

        valueWidgets.add(
          DropdownButton(
            items: dropdownItems,
            value: selectedValue,
            onChanged: (newValue) {
              // Mise à jour de la variable temporaire correspondante
              updateTempSelectedValue(isTrigger, isPlatform, index, newValue);
            },
          ),
        );
      } else if (value is int) {
        valueWidgets.add(
          TextField(
            controller: TextEditingController(text: value.toString()),
            keyboardType: TextInputType.number,
            decoration: InputDecoration(labelText: value.toString()),
          ),
        );
      } else {
        valueWidgets.add(const Text(
            'Aucune valeur à ajouter, vous pouvez valider ou annuler si vous aviez changé d\'avis'));
      }
    }

    return valueWidgets;
  }

  // Obtenez la variable temporaire correspondante en fonction du contexte
  dynamic tempSelectedValue(bool isTrigger, bool isPlatform, int index) {
    if (isTrigger) {
      return tempSelectedTriggerValues[index];
    } else if (isPlatform) {
      return tempSelectedPlatformValues[index];
    } else {
      return tempSelectedActionValues[index];
    }
  }

  // Mettez à jour la variable temporaire correspondante en fonction du contexte
  void updateTempSelectedValue(
      bool isTrigger, bool isPlatform, int index, dynamic newValue) {
    if (isTrigger) {
      tempSelectedTriggerValues[index] = newValue;
    } else if (isPlatform) {
      tempSelectedPlatformValues[index] = newValue;
    } else {
      tempSelectedActionValues[index] = newValue;
    }
  }

  @override
  Widget build(BuildContext context) {
    final isMobile = Responsive.isMobile(context);

    if (isMobile) {
      return mobileLayout(context);
    } else {
      return desktopLayout(context);
    }
  }

  SafeArea mobileLayout(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        body: Padding(
          padding: const EdgeInsets.all(8.0),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: <Widget>[
              const SizedBox(height: 15),
              TextFormField(
                controller: titleController,
                style: Theme.of(context).textTheme.titleLarge!.copyWith(
                    color: Colors.black87,
                    letterSpacing: 1.5,
                    fontWeight: FontWeight.w800),
                textAlign: TextAlign.center,
                decoration: InputDecoration(
                  hintText: 'Titre de l\'applet',
                  hintStyle:
                      const TextStyle(color: Colors.black26, letterSpacing: 5),
                  border: OutlineInputBorder(
                    borderSide: BorderSide.none,
                    borderRadius: BorderRadius.circular(16),
                  ),
                ),
              ),
              Column(
                children: [
                  const SizedBox(height: 15),
                  BlockCard(
                    callback: () {
                      showServiceSelectionDialog(context, true, false);
                    },
                    isTrigger: true,
                    serviceSelected: selectedTriggerService,
                  ),
                  const SizedBox(height: 10),
                  BlockCard(
                    callback: () {
                      showServiceSelectionDialog(context, false, false);
                    },
                    serviceSelected: selectedActionService,
                  ),
                  const SizedBox(height: 10),
                  if (needPlatform)
                    BlockCard(
                      callback: () {
                        showServiceSelectionDialog(context, false, true);
                      },
                      isPlatform: true,
                      serviceSelected: selectedPlatformService,
                    ),
                ],
              ),
              const SizedBox(height: 20),
              Padding(
                padding: const EdgeInsets.all(16),
                child: Column(
                  children: [
                    Row(
                      mainAxisAlignment: MainAxisAlignment.spaceBetween,
                      children: <Widget>[
                        const Text('Utilisation unique',
                            style: TextStyle(letterSpacing: 1.5)),
                        Switch(
                          value: isOneShot,
                          onChanged: isPublic
                              ? null
                              : (bool newValue) {
                                  if (mounted) {
                                    setState(() {
                                      isOneShot = newValue;
                                    });
                                  }
                                },
                        ),
                      ],
                    ),
                    const SizedBox(height: 15),
                    Row(
                      mainAxisAlignment: MainAxisAlignment.spaceBetween,
                      children: <Widget>[
                        const Text('Publié sur le Marketplace',
                            style: TextStyle(letterSpacing: 1.5)),
                        Switch(
                          value: isPublic,
                          onChanged: (bool newValue) {
                            if (mounted) {
                              setState(() {
                                isPublic = newValue;
                                if (isPublic) isOneShot = false;
                              });
                            }
                          },
                        ),
                      ],
                    ),
                  ],
                ),
              ),
              const Spacer(),
              LargeButton(
                text: 'Terminer',
                backgroundColor: Theme.of(context).primaryColor,
                onPressed: () async {
                  List<applet_action.Action> actions = [];
                  actions.add(applet_action.Action(
                    service: selectedActionService!,
                    type: selectedActionType,
                    values: selectedActionValues,
                  ));
                  if (needPlatform) {
                    actions.first.platform = applet_action.Platform(
                        service: selectedPlatformService!,
                        type: selectedPlatformType,
                        values: selectedTriggerValues);
                  }
                  final newApplet = Applet(
                    action: actions,
                    active: true,
                    title: titleController.text,
                    createTime: Timestamp.now(),
                    oneShot: isOneShot,
                    public: isPublic,
                    favoritesCounter: 1,
                    updateTime: Timestamp.now(),
                    runTime: List.empty(),
                    trigger: applet_trigger.Trigger(
                      service: selectedTriggerService!,
                      type: selectedTriggerType,
                      values: selectedTriggerValues,
                    ),
                    userUid: getCurrentUserUid()!,
                    userName: getCurrentUserEmail()!.split('@')[0],
                  );
                  await CloudFireStoreService.addApplet(newApplet);
                  titleController = TextEditingController();
                  selectedTriggerService;
                  selectedActionService;
                  selectedPlatformService;
                  selectedTriggerType = '';
                  selectedActionType = '';
                  selectedPlatformType = '';
                  tempSelectedTriggerValues = [];
                  tempSelectedActionValues = [];
                  tempSelectedPlatformValues = [];
                  selectedTriggerValues = [];
                  selectedActionValues = [];
                  selectedPlatformValues = [];
                  isOneShot = false;
                  isPublic = true;
                  needPlatform = false;
                },
              ),
            ],
          ),
        ),
      ),
    );
  }

  SafeArea desktopLayout(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        body: Stack(
          children: [
            // Background with opacity and image
            Opacity(
              opacity: 0.05, // Adjust the opacity value as needed (0.0 to 1.0)
              child: Container(
                decoration: const BoxDecoration(
                  image: DecorationImage(
                    image: AssetImage(
                        '../../assets/topography.png'), // Replace with your image path
                    repeat: ImageRepeat.repeat,
                  ),
                ),
              ),
            ),
            Center(
              child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: SizedBox(
                  width: 800,
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.center,
                    children: <Widget>[
                      const WebTitle(title: 'Créer un applet'),
                      const SizedBox(height: 15),
                      TextFormField(
                        controller: titleController,
                        style: Theme.of(context).textTheme.displaySmall!.copyWith(
                            color: Colors.black87,
                            letterSpacing: 1.5,
                            fontWeight: FontWeight.w800),
                        textAlign: TextAlign.center,
                        decoration: InputDecoration(
                          hintText: 'Titre de l\'applet',
                          hintStyle:
                              const TextStyle(color: Colors.black26, letterSpacing: 5),
                          border: OutlineInputBorder(
                            borderSide: BorderSide.none,
                            borderRadius: BorderRadius.circular(16),
                          ),
                        ),
                      ),
                      Column(
                        children: [
                          const SizedBox(height: 15),
                          BlockCard(
                            callback: () {
                              showServiceSelectionDialog(context, true, false);
                            },
                            isTrigger: true,
                            serviceSelected: selectedTriggerService,
                          ),
                          const SizedBox(height: 10),
                          BlockCard(
                            callback: () {
                              showServiceSelectionDialog(context, false, false);
                            },
                            serviceSelected: selectedActionService,
                          ),
                          const SizedBox(height: 10),
                          if (needPlatform)
                            BlockCard(
                              callback: () {
                                showServiceSelectionDialog(context, false, true);
                              },
                              isPlatform: true,
                              serviceSelected: selectedPlatformService,
                            ),
                        ],
                      ),
                      const SizedBox(height: 20),
                      Padding(
                        padding: const EdgeInsets.all(16),
                        child: Column(
                          children: [
                            Row(
                              mainAxisAlignment: MainAxisAlignment.spaceBetween,
                              children: <Widget>[
                                const Text('Utilisation unique',
                                    style: TextStyle(letterSpacing: 1.5)),
                                Switch(
                                  value: isOneShot,
                                  onChanged: isPublic
                                      ? null
                                      : (bool newValue) {
                                          if (mounted) {
                                            setState(() {
                                              isOneShot = newValue;
                                            });
                                          }
                                        },
                                ),
                              ],
                            ),
                            const SizedBox(height: 15),
                            Row(
                              mainAxisAlignment: MainAxisAlignment.spaceBetween,
                              children: <Widget>[
                                const Text('Publié sur le Marketplace',
                                    style: TextStyle(letterSpacing: 1.5)),
                                Switch(
                                  value: isPublic,
                                  onChanged: (bool newValue) {
                                    if (mounted) {
                                      setState(() {
                                        isPublic = newValue;
                                        if (isPublic) isOneShot = false;
                                      });
                                    }
                                  },
                                ),
                              ],
                            ),
                          ],
                        ),
                      ),
                      const Spacer(),
                      SizedBox(
                        height: 75,
                        child: LargeButton(
                          text: 'Terminer',
                          backgroundColor: Theme.of(context).primaryColor,
                          onPressed: () async {
                            List<applet_action.Action> actions = [];
                            actions.add(applet_action.Action(
                              service: selectedActionService!,
                              type: selectedActionType,
                              values: selectedActionValues,
                            ));
                            if (needPlatform) {
                              actions.first.platform = applet_action.Platform(
                                  service: selectedPlatformService!,
                                  type: selectedPlatformType,
                                  values: selectedTriggerValues);
                            }
                            final newApplet = Applet(
                              action: actions,
                              active: true,
                              title: titleController.text,
                              createTime: Timestamp.now(),
                              oneShot: isOneShot,
                              public: isPublic,
                              favoritesCounter: 1,
                              updateTime: Timestamp.now(),
                              runTime: List.empty(),
                              trigger: applet_trigger.Trigger(
                                service: selectedTriggerService!,
                                type: selectedTriggerType,
                                values: selectedTriggerValues,
                              ),
                              userUid: getCurrentUserUid()!,
                              userName: getCurrentUserEmail()!.split('@')[0],
                            );
                            await CloudFireStoreService.addApplet(newApplet);
                            titleController = TextEditingController();
                            selectedTriggerService;
                            selectedActionService;
                            selectedPlatformService;
                            selectedTriggerType = '';
                            selectedActionType = '';
                            selectedPlatformType = '';
                            tempSelectedTriggerValues = [];
                            tempSelectedActionValues = [];
                            tempSelectedPlatformValues = [];
                            selectedTriggerValues = [];
                            selectedActionValues = [];
                            selectedPlatformValues = [];
                            isOneShot = false;
                            isPublic = true;
                            needPlatform = false;
                          },
                        ),
                      ),
                    ],
                  ),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
