#pragma once

#include "../../CerealException.hpp"
#include "../Entity/EntityManager.hpp"
#include "../../Components/RenderComponent.hpp"
#include "../../Components/ScriptComponent.hpp"
#include "../../Components/SpriteComponent.hpp"
#include "../../Components/StatsComponent.hpp"
#include "../../Components/TransformComponent.hpp"
#include "../../Components/ModelComponent.hpp"
#include "../../Components/CameraComponent.hpp"
#include "../../Components/TextComponent.hpp"
#include "../../Components/BoxColliderComponent.hpp"
#include "../../Components/InventoryComponent.hpp"
#include "../../Components/LightComponent.hpp"

namespace Raylib {
    #include <raylib.h>
}
using namespace Raylib;

namespace Cereal {
    class RenderSystem {
        public:
            EntityManager& entityManager;

            RenderSystem(EntityManager& entityManager) : entityManager(entityManager) {};

            // @brief Draw a sprite
            // @param sprite The sprite to draw
            // @param transform The transform of the sprite
            void drawSprite(const Sprite* sprite, const Cereal::Transform* transform);

            // @brief Draw a 3D model
            // @param model The model to draw
            // @param transform The transform of the model
            void drawModel(const Model3D* model, const Cereal::Transform* transform);

            // @brief Draw a 2D text
            // @param text The text to draw
            void drawText(const Text* text);

            // @brief Draw debug
            // @param e entity to draw debug
            void drawDebug(Entity &e);

            // @brief Draw and Update Light
            // @param light The light to draw
            void drawLight(const LightComponent* light);

            // @brief Update all components
            void updateComponents(bool debug);
    };
}