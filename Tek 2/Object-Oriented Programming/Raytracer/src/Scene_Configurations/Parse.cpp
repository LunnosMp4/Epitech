/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** Config.cpp
*/

#include "Raytracer.hpp"

void parseCamera(const libconfig::Setting &cameraSetting, Scene &scene) {
    /* Resolution */
    const libconfig::Setting &resolutionSetting = cameraSetting["resolution"];
    resolutionSetting.lookupValue("width", scene.camera.resolution.x);
    resolutionSetting.lookupValue("height", scene.camera.resolution.y);
    // DEBUG
    // std::cout << "Resolution: " << scene.camera.resolution.x << ", " << scene.camera.resolution.y << std::endl;

    /* Position */
    const libconfig::Setting &positionSetting = cameraSetting["position"];
    positionSetting.lookupValue("x", scene.camera.position.x);
    positionSetting.lookupValue("y", scene.camera.position.y);
    positionSetting.lookupValue("z", scene.camera.position.z);
    // DEBUG
    // std::cout << "Position: " << scene.camera.position.x << ", " << scene.camera.position.y << ", " << scene.camera.position.z << std::endl;

    /* Rotation */
    const libconfig::Setting &rotationSetting = cameraSetting["rotation"];
    rotationSetting.lookupValue("x", scene.camera.rotation.x);
    rotationSetting.lookupValue("y", scene.camera.rotation.y);
    rotationSetting.lookupValue("z", scene.camera.rotation.z);
    // DEBUG
    // std::cout << "Rotation: " << scene.camera.rotation.x << ", " << scene.camera.rotation.y << ", " << scene.camera.rotation.z << std::endl;

    /* Field of view */
    cameraSetting.lookupValue("fieldOfView", scene.camera.fov);
    // DEBUG
    // std::cout << "Field of view: " << scene.camera.fov << "\n\n" << std::endl;

    /* Anti-aliasing */
    cameraSetting.lookupValue("antialiasing", scene.camera.antiAliasing);
    // DEBUG
    // std::cout << "Anti-aliasing: " << scene.camera.antiAliasing << "\n\n" << std::endl;

    cameraSetting.lookupValue("postProcessing", scene.camera.postProcessing);
}

void parseSphere(const libconfig::Setting &sphereSetting, Scene &scene) {
    Sphere sphere;

    /* Center */
    const libconfig::Setting& centerSetting = sphereSetting["center"];
    centerSetting.lookupValue("x", sphere.center.x);
    centerSetting.lookupValue("y", sphere.center.y);
    centerSetting.lookupValue("z", sphere.center.z);
    // DEBUG
    // std::cout << "Center: " << sphere.center.x << ", " << sphere.center.y << ", " << sphere.center.z << std::endl;

    /* Radius */
    sphereSetting.lookupValue("radius", sphere.radius);
    // DEBUG
    // std::cout << "Radius: " << sphere.radius << std::endl;

    /* Rotation */
    const libconfig::Setting &rotationSetting = sphereSetting["rotation"];
    rotationSetting.lookupValue("x", sphere.rotation.x);
    rotationSetting.lookupValue("y", sphere.rotation.y);
    rotationSetting.lookupValue("z", sphere.rotation.z);
    // DEBUG
    // std::cout << "Rotation: " << sphere.rotation.x << ", " << sphere.rotation.y << ", " << sphere.rotation.z << "\n\n" << std::endl;

    /* Color */
    const libconfig::Setting& colorSetting = sphereSetting["color"];
    colorSetting.lookupValue("r", sphere.material.color.r);
    colorSetting.lookupValue("g", sphere.material.color.g);
    colorSetting.lookupValue("b", sphere.material.color.b);
    // DEBUG
    // std::cout << "Color: " << sphere.color.r << ", " << sphere.color.g << ", " << sphere.color.b << "\n\n" << std::endl;

    /* Material */
    const libconfig::Setting& materialSetting = sphereSetting["material"];
    materialSetting.lookupValue("transparency", sphere.material.transparency);
    materialSetting.lookupValue("reflection", sphere.material.reflection);
    materialSetting.lookupValue("ior", sphere.material.ior);

    /* Push sphere to scene */
    scene.spheres.push_back(sphere);
}

void parsePlane(const libconfig::Setting &planeSetting, Scene &scene) {
    Plane plane;

    /* Origin */
    const libconfig::Setting &originSetting = planeSetting["origin"];
    originSetting.lookupValue("x", plane.origin.x);
    originSetting.lookupValue("y", plane.origin.y);
    originSetting.lookupValue("z", plane.origin.z);
    // DEBUG
    // std::cout << "Origin: " << plane.origin.x << ", " << plane.origin.y << ", " << plane.origin.z << std::endl;

    /* Axis */
    planeSetting.lookupValue("axis", plane.axis);
    // DEBUG
    // std::cout << "Axis: " << plane.axis << std::endl;

    /* Rotation */
    const libconfig::Setting &rotationSetting = planeSetting["rotation"];
    rotationSetting.lookupValue("x", plane.rotation.x);
    rotationSetting.lookupValue("y", plane.rotation.y);
    rotationSetting.lookupValue("z", plane.rotation.z);
    // DEBUG
    // std::cout << "Rotation: " << plane.rotation.x << ", " << plane.rotation.y << ", " << plane.rotation.z << "\n\n" << std::endl;

    /* Color */
    const libconfig::Setting &colorSetting = planeSetting["color"];
    colorSetting.lookupValue("r", plane.material.color.r);
    colorSetting.lookupValue("g", plane.material.color.g);
    colorSetting.lookupValue("b", plane.material.color.b);
    // DEBUG
    // std::cout << "Color: " << plane.color.r << ", " << plane.color.g << ", " << plane.color.b << "\n\n" << std::endl;

    /* Material */
    const libconfig::Setting& materialSetting = planeSetting["material"];
    materialSetting.lookupValue("transparency", plane.material.transparency);
    materialSetting.lookupValue("reflection", plane.material.reflection);
    materialSetting.lookupValue("ior", plane.material.ior);
    // DEBUG
    // std::cout << "Transparency: " << plane.material.transparency << std::endl;
    // std::cout << "Reflection: " << plane.material.reflection << std::endl;
    // std::cout << "ior: " << plane.material.ior << "\n\n" << std::endl;

    /* Push plane to scene */
    scene.planes.push_back(plane);
}

void parseCylinder(const libconfig::Setting &cylinderSetting, Scene &scene) {
    Cylinder cylinder;

    /* Center */
    const libconfig::Setting& centerSetting = cylinderSetting["center"];
    centerSetting.lookupValue("x", cylinder.center.x);
    centerSetting.lookupValue("y", cylinder.center.y);
    centerSetting.lookupValue("z", cylinder.center.z);
    // DEBUG
    // std::cout << "Center: " << cylinder.center.x << ", " << cylinder.center.y << ", " << cylinder.center.z << std::endl;

    /* Radius */
    cylinderSetting.lookupValue("radius", cylinder.radius);
    // DEBUG
    // std::cout << "Radius: " << cylinder.radius << std::endl;

    /* Height */
    cylinderSetting.lookupValue("height", cylinder.height);
    // DEBUG
    // std::cout << "Height: " << cylinder.height << std::endl;

    /* Rotation */
    const libconfig::Setting &rotationSetting = cylinderSetting["rotation"];
    rotationSetting.lookupValue("x", cylinder.rotation.x);
    rotationSetting.lookupValue("y", cylinder.rotation.y);
    rotationSetting.lookupValue("z", cylinder.rotation.z);
    // DEBUG
    // std::cout << "Rotation: " << cylinder.rotation.x << ", " << cylinder.rotation.y << ", " << cylinder.rotation.z << "\n\n" << std::endl;

    /* Color */
    const libconfig::Setting& colorSetting = cylinderSetting["color"];
    colorSetting.lookupValue("r", cylinder.material.color.r);
    colorSetting.lookupValue("g", cylinder.material.color.g);
    colorSetting.lookupValue("b", cylinder.material.color.b);
    // DEBUG
    // std::cout << "Color: " << cylinder.color.r << ", " << cylinder.color.g << ", " << cylinder.color.b << "\n\n" << std::endl;

    /* Material */
    const libconfig::Setting& materialSetting = cylinderSetting["material"];
    materialSetting.lookupValue("transparency", cylinder.material.transparency);
    materialSetting.lookupValue("reflection", cylinder.material.reflection);
    materialSetting.lookupValue("ior", cylinder.material.ior);
    // DEBUG
    // std::cout << "Transparency: " << cylinder.material.transparency << std::endl;
    // std::cout << "Reflection: " << cylinder.material.reflection << std::endl;
    // std::cout << "ior: " << cylinder.material.ior << "\n\n" << std::endl;

    /* Push cylinder to scene */
    scene.cylinders.push_back(cylinder);
}

void parseCone(const libconfig::Setting &coneSetting, Scene &scene) {
    Cone cone;

    /* Center */
    const libconfig::Setting &centerSetting = coneSetting["center"];
    centerSetting.lookupValue("x", cone.center.x);
    centerSetting.lookupValue("y", cone.center.y);
    centerSetting.lookupValue("z", cone.center.z);
    // DEBUG
    // std::cout << "Center: " << cone.center.x << ", " << cone.center.y << ", " << cone.center.z << std::endl;

    /* Radius */
    coneSetting.lookupValue("radius", cone.radius);
    // DEBUG
    // std::cout << "Radius: " << cone.radius << std::endl;

    /* Height */
    coneSetting.lookupValue("height", cone.height);
    // DEBUG
    // std::cout << "Height: " << cone.height << std::endl;

    /* Rotation */
    const libconfig::Setting &rotationSetting = coneSetting["rotation"];
    rotationSetting.lookupValue("x", cone.rotation.x);
    rotationSetting.lookupValue("y", cone.rotation.y);
    rotationSetting.lookupValue("z", cone.rotation.z);
    // DEBUG
    // std::cout << "Rotation: " << cone.rotation.x << ", " << cone.rotation.y << ", " << cone.rotation.z << "\n\n" << std::endl;

    /* Color */
    const libconfig::Setting &colorSetting = coneSetting["color"];
    colorSetting.lookupValue("r", cone.material.color.r);
    colorSetting.lookupValue("g", cone.material.color.g);
    colorSetting.lookupValue("b", cone.material.color.b);
    // DEBUG
    // std::cout << "Color: " << cone.color.r << ", " << cone.color.g << ", " << cone.color.b << "\n\n" << std::endl;

    /* Material */
    const libconfig::Setting& materialSetting = coneSetting["material"];
    materialSetting.lookupValue("transparency", cone.material.transparency);
    materialSetting.lookupValue("reflection", cone.material.reflection);
    materialSetting.lookupValue("ior", cone.material.ior);
    // DEBUG
    // std::cout << "Transparency: " << cone.material.transparency << std::endl;
    // std::cout << "Reflection: " << cone.material.reflection << std::endl;
    // std::cout << "ior: " << cone.material.ior << "\n\n" << std::endl;

    /* Push cone to scene */
    scene.cones.push_back(cone);
}

void parseMobiusStrip(const libconfig::Setting &mobiusStripSetting, Scene &scene) {
    MobiusStrip mobiusStrip;

    /* Center */
    const libconfig::Setting &centerSetting = mobiusStripSetting["center"];
    centerSetting.lookupValue("x", mobiusStrip.center.x);
    centerSetting.lookupValue("y", mobiusStrip.center.y);
    centerSetting.lookupValue("z", mobiusStrip.center.z);
    // DEBUG
    // std::cout << "Center: " << mobiusStrip.center.x << ", " << mobiusStrip.center.y << ", " << mobiusStrip.center.z << std::endl;

    /* Radius */
    mobiusStripSetting.lookupValue("radius", mobiusStrip.radius);
    // DEBUG
    // std::cout << "Radius: " << mobiusStrip.radius << std::endl;

    /* Width */
    mobiusStripSetting.lookupValue("width", mobiusStrip.width);
    // DEBUG
    // std::cout << "Width: " << mobiusStrip.width << std::endl;

    /* Rotation */
    const libconfig::Setting &rotationSetting = mobiusStripSetting["rotation"];
    rotationSetting.lookupValue("x", mobiusStrip.rotation.x);
    rotationSetting.lookupValue("y", mobiusStrip.rotation.y);
    rotationSetting.lookupValue("z", mobiusStrip.rotation.z);
    // DEBUG
    // std::cout << "Rotation: " << mobiusStrip.rotation.x << ", " << mobiusStrip.rotation.y << ", " << mobiusStrip.rotation.z << "\n\n" << std::endl;

    /* Color */
    const libconfig::Setting &colorSetting = mobiusStripSetting["color"];
    colorSetting.lookupValue("r", mobiusStrip.material.color.r);
    colorSetting.lookupValue("g", mobiusStrip.material.color.g);
    colorSetting.lookupValue("b", mobiusStrip.material.color.b);
    // DEBUG
    // std::cout << "Color: " << mobiusStrip.color.r << ", " << mobiusStrip.color.g << ", " << mobiusStrip.color.b << "\n\n" << std::endl;

    /* Material */
    const libconfig::Setting& materialSetting = mobiusStripSetting["material"];
    materialSetting.lookupValue("transparency", mobiusStrip.material.transparency);
    materialSetting.lookupValue("reflection", mobiusStrip.material.reflection);
    materialSetting.lookupValue("ior", mobiusStrip.material.ior);
    // DEBUG
    // std::cout << "Transparency: " << mobiusStrip.material.transparency << std::endl;
    // std::cout << "Reflection: " << mobiusStrip.material.reflection << std::endl;
    // std::cout << "ior: " << mobiusStrip.material.ior << "\n\n" << std::endl;

    /* Push Mobius strip to scene */
    scene.mobiusStrips.push_back(mobiusStrip);
}

void parsePrimitives(const libconfig::Setting &primitiveSetting, Scene &scene) {
    const libconfig::Setting &spheresSetting = primitiveSetting["spheres"];
    const libconfig::Setting &planesSetting = primitiveSetting["planes"];
    const libconfig::Setting &cylindersSetting = primitiveSetting["cylinders"];
    const libconfig::Setting &conesSetting = primitiveSetting["cones"];
    const libconfig::Setting &mobiusStripsSetting = primitiveSetting["mobiusStrips"];

    for (int i = 0; i < spheresSetting.getLength(); i++)
        parseSphere(spheresSetting[i], scene);

    for (int i = 0; i < planesSetting.getLength(); i++)
        parsePlane(planesSetting[i], scene);

    for (int i = 0; i < cylindersSetting.getLength(); i++)
        parseCylinder(cylindersSetting[i], scene);

    for (int i = 0; i < conesSetting.getLength(); i++)
        parseCone(conesSetting[i], scene);

    for (int i = 0; i < mobiusStripsSetting.getLength(); i++)
        parseMobiusStrip(mobiusStripsSetting[i], scene);
}

void parsePointLight(const libconfig::Setting &pointSetting, Scene &scene) {
    PointLight pointLight;

    /* Position */
    const libconfig::Setting &positionSetting = pointSetting["position"];
    positionSetting.lookupValue("x", pointLight.position.x);
    positionSetting.lookupValue("y", pointLight.position.y);
    positionSetting.lookupValue("z", pointLight.position.z);
    // DEBUG
    // std::cout << "Position: " << pointLight.position.x << ", " << pointLight.position.y << ", " << pointLight.position.z << "\n\n" << std::endl;

    /* Push point light to scene */
    scene.light.pointLights.push_back(pointLight);
}

void parseLights(const libconfig::Setting &lightSetting, Scene &scene) {
    const libconfig::Setting &pointSetting = lightSetting["point"];

    /* Ambient */
    lightSetting.lookupValue("ambient", scene.light.ambient);
    // DEBUG
    // std::cout << "Ambient: " << scene.light.ambient << std::endl;

    /* Diffuse */
    lightSetting.lookupValue("diffuse", scene.light.diffuse);
    // DEBUG
    // std::cout << "Diffuse: " << scene.light.diffuse << std::endl;

    /* Is ambiant */
    lightSetting.lookupValue("isAmbiant", scene.light.isAmbiant);
    // DEBUG
    // std::cout << "Is ambiant: " << scene.light.isAmbiant << "\n\n" << std::endl;

    for (int i = 0; i < pointSetting.getLength(); i++)
        parsePointLight(pointSetting[i], scene);
}

Scene parseFile(std::string filename) {

    /* INIT */
    Scene scene;
    libconfig::Config cfg;

    try {
        cfg.readFile(filename.c_str());
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        exit(84);
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
        << " - " << pex.getError() << std::endl;
        exit(84);
    }
    const libconfig::Setting &root = cfg.getRoot();


    /* CAMERA */
    try {
        const libconfig::Setting &cameraSetting = root["camera"];
        parseCamera(cameraSetting, scene);
    } catch (std::exception &e) {
        std::cerr << "No 'camera' setting in configuration file." << std::endl;
        exit(84);
    }

    /* PRIMITIVES */
    try {
        const libconfig::Setting& primitivesSetting = root["primitives"];
        parsePrimitives(primitivesSetting, scene);
    } catch (std::exception &e) {
        std::cerr << "No 'primitives' setting in configuration file." << std::endl;
        exit(84);
    }

    /* LIGHTS */
    try {
        const libconfig::Setting& lightSetting = root["lights"];
        parseLights(lightSetting, scene);
    } catch (std::exception &e) {
        std::cerr << "No 'light' setting in configuration file." << std::endl;
        exit(84);
    }

    return scene;
}