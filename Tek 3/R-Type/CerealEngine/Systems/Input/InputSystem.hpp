/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InputSystem.hpp
*/

#pragma once

#include "InputManager.hpp"
#include "../Entity/EntityManager.hpp"
#include "../../Components/TransformComponent.hpp"
#include "../../Components/StatsComponent.hpp"
#include "Key.hpp"
#include <unordered_map>
#include <functional>

using ActionFunction = std::function<void(Cereal::Transform&, Cereal::Stats&)>;

namespace Cereal {
    class InputSystem {
        private:
            InputManager inputManager;
            EntityManager& entityManager;

            // @brief Key configuration by default
            void configureKeys();

        public:
            InputSystem(EntityManager& entityManager) : entityManager(entityManager) {
                configureKeys();
            }

            // @brief Get current action down
            // @return actionName The name of the action
            std::string getActionDown();

            // @brief Get current action pressed
            // @return actionName The name of the action
            std::string getActionPressed();

            // @brief Get the key code pressed and the input type
            // @return std::pair<int, InputType> The key code and the input type
            std::pair<int, InputType> getKeyPressed();

            // @brief Remove a key mapping
            // @param actionName The name of the action
            // @param key The key to remove
            void removeKeyMapping(const std::string& actionName, const int& key);

            // @brief Remove all key mapping
            // @param actionName The name of the action
            void removeAllKeyMapping(const std::string& actionName);

            // @brief Map a key to an action
            // @param actionName The name of the action
            // @param key The key to map
            void mapKey(const std::string& actionName, const int& key, const InputType& inputType);
    };
}
