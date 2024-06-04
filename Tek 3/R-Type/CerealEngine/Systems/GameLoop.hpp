/*

** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** GameLoop.hpp
*/

#pragma once

#include "Entity/EntityManager.hpp"
#include "Resource/ResourceManager.hpp"
#include "Render/RenderSystem.hpp"
#include "Input/InputSystem.hpp"
#include "Audio/AudioSystem.hpp"
#include "Physics/PhysicsSystem.hpp"
#include "Inventory/InventorySystem.hpp"
#include "Draw/DrawSystem.hpp"
#include "../EntityFactory/EntityFactory.hpp"

namespace Cereal {
    class GameLoop {
        private:
            bool isRunning = true;
            EntityManager& entityManager;
            RenderSystem& renderSystem;
            InputSystem& inputSystem;
            AudioSystem& audioSystem;
            PhysicsSystem& physicsSystem;
            InventorySystem& inventorySystem;
            DrawSystem& drawSystem;
            EntityFactory& entityFactory;

        public:
            GameLoop(EntityManager& entityManager, RenderSystem& renderSys, InputSystem& inputSys, AudioSystem& audioSys, PhysicsSystem& physicsSys, InventorySystem& inventorySys, DrawSystem& drawSys, EntityFactory& entityFactory) :
            entityManager(entityManager),
            renderSystem(renderSys),
            inputSystem(inputSys),
            audioSystem(audioSys),
            physicsSystem(physicsSys),
            inventorySystem(inventorySys),
            drawSystem(drawSys),
            entityFactory(entityFactory)
            {};

            // @brief Stop the game loop
            void stop();

            // @brief Check if the window should close
            // @return True if the window should close, false otherwise
            bool WindowShouldClose();

            // @brief Render the entities that have render components
            void render(bool debug = false);

            // @ brief Play the audio of the entities that have audio components
            void audio();

            // @brief Update the entities that have physics components
            void update();

            // @brief Get the entity manager
            // @return The entity manager
            EntityManager& getEntityManager() { return entityManager; };

            // @brief Get the input system
            // @return The input system
            InputSystem& getInputSystem() { return inputSystem; };

            // @brief Get the physics system
            // @return The physics system
            PhysicsSystem& getPhysicsSystem() { return physicsSystem; };

            // @brief Get the inventory system
            // @return The inventory system
            InventorySystem& getInventorySystem() { return inventorySystem; };

            // @brief Get the draw system
            // @return The draw system
            DrawSystem& getDrawSystem() { return drawSystem; };

            // @brief Get the render system
            // @return The render system
            RenderSystem& getRenderSystem() { return renderSystem; };

            // @brief Get the audio system
            // @return The audio system
            AudioSystem& getAudioSystem() { return audioSystem; };

            // @brief Get the entity factory
            // @return The entity factory
            EntityFactory& getEntityFactory() { return entityFactory; };
    };
};