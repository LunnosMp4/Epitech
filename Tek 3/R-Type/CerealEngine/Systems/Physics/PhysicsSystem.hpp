/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** PhysicsSystem.hpp
*/

#pragma once

namespace Raylib {
    #include <raylib.h>
}
using namespace Raylib;

#include "../../CerealException.hpp"
#include "../../Components/BoxColliderComponent.hpp"
#include "../Entity/EntityManager.hpp"
#include "../Input/InputSystem.hpp"
#include "../../Components/CameraComponent.hpp"
#include "../../Components/ModelComponent.hpp"
#include "../../Components/TransformComponent.hpp"
#include "../../Components/RenderComponent.hpp"

namespace Cereal {
    class PhysicsSystem {
        public:
            EntityManager& entityManager;
            
            PhysicsSystem(EntityManager& entityManager) : entityManager(entityManager) {};

            // @brief Update all components
            void updateComponents();

            // @brief Check collisions between 2 entities
            // @param entityA The first entity
            // @param entityB The second entity
            // @return True if the entities are colliding, false otherwise
            bool checkCollision(Entity& entityA, Entity& entityB);

            // @brief Check if the mouse is hovering on an entity
            // @param entity The entity to check
            // @return True if the mouse is hovering on the entity, false otherwise
            bool checkHoverOnEntity(Entity& entity);

            // @brief Get the entity that the mouse is hovering on
            // @return The entity that the mouse is hovering on
            Entity getHoveredEntity();
    };
}
