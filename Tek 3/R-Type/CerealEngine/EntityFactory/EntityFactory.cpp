/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"

using namespace Cereal;

Entity EntityFactory::createButton(const std::string sceneName, const std::string& name, const std::string& texturePath, const Vector3& position, const Vector3& rotation, const float& scale) {

    Entity button = entityManager.createEntity(sceneName, name)
        .addComponent<Sprite>(Sprite(texturePath))
        .addComponent<Cereal::Transform>(Transform(position, rotation, scale))
        .addComponent<Render>(Render(true));

    return button;
}

Entity EntityFactory::createText(const std::string sceneName, const std::string name, const std::string& text, const Vector2& position, const int& fontSize, const std::string& fontPath, const Color& color) {

    Entity textEntity = entityManager.createEntity(sceneName, name)
        .addComponent<Cereal::Text>(Text(text, position, fontSize, fontPath, color))
        .addComponent<Render>(Render(true));

    return textEntity;
}

Entity EntityFactory::createCamera(const std::string sceneName, const Vector3& position, const Vector3& target, const Vector3& up, const float& fovy = 45.0f, const int& projection = CAMERA_PERSPECTIVE) {

    Entity camera = entityManager.createEntity(sceneName, "Camera")
        .addComponent<Cereal::Camera>(Camera(position, target, up, fovy, projection));

    return camera;
}

Entity EntityFactory::createLight(const std::string sceneName, const Vector3& position, const Color& color) {

    Entity light = entityManager.createEntity(sceneName, "Light")
        .addComponent<Cereal::LightComponent>(LightComponent(position, color))
        .addComponent<Render>(Render(true));

    return light;
}

void EntityFactory::createGlobalCamera(const Vector3& position, const Vector3& target, const Vector3& up, const float& fovy = 45.0f, const int& projection = CAMERA_PERSPECTIVE) {

    std::vector<std::string> scenes = entityManager.getScenes();
    for (auto& scene : scenes) {
        Entity camera = entityManager.createEntity(scene, "Camera")
            .addComponent<Cereal::Camera>(Camera(position, target, up, fovy, projection));
    }
}
