/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** EntityFactory.hpp
*/

#pragma once

namespace Raylib {
    #include <raylib.h>
}
using namespace Raylib;
#include "../Systems/Entity/EntityManager.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/ScriptComponent.hpp"
#include "../Components/RenderComponent.hpp"
#include "../Components/TextComponent.hpp"
#include "../Components/CameraComponent.hpp"
#include "../Components/LightComponent.hpp"
#include "../Components/BoxColliderComponent.hpp"

namespace Cereal {
    class EntityFactory {
        public:
            EntityManager& entityManager;

            EntityFactory(EntityManager& entityManager) : entityManager(entityManager) {};

            // @brief Create a button
            // @note Futur différence: Script, Tranform en 2d avec size au lieu de scale (à réfléchir), créer une animation visuel et auditive lors d'un event, Peut-être intégrer des onClick, onHover, etc...
            Entity createButton(const std::string sceneName, const std::string& name, const std::string& texturePath, const Vector3& position, const Vector3& rotation, const float& scale);

            // @brief Create a text
            Entity createText(const std::string sceneName, const std::string name, const std::string& text, const Vector2& position, const int& fontSize, const std::string& fontPath, const Color& color);

            // @brief Create a camera
            Entity createCamera(const std::string sceneName, const Vector3& position, const Vector3& target, const Vector3& up, const float& fovy, const int& projection);

            // @brief Create a light
            Entity createLight(const std::string sceneName, const Vector3& position, const Color& color);
    
            // @brief Create a global camera on all scenes
            void createGlobalCamera(const Vector3& position, const Vector3& target, const Vector3& up, const float& fovy, const int& projection);
    };
}