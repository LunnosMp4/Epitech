/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InputManager.hpp
*/

#pragma once

namespace Raylib {
    #include <raylib.h>
}
using namespace Raylib;
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include "Key.hpp"

namespace Cereal {
    // @brief Struct to configure keys
    struct ConfigurableKey {
        struct KeyMapping {
            int keyCode;
            InputType inputType;
        };

        std::vector<KeyMapping> keyMappings;
        std::string action;
    };

    class InputManager {
        private:
            std::unordered_map<std::string, ConfigurableKey> keyMappings;
        public:

            // @brief Configure keys
            // @param action The name of the action to configure
            // @param keyCode The key code to configure
            // @param inputType The type of input (Keyboard_T, Gamepad_T, etc...)
            void setKeyMapping(const std::string& action, int keyCode, InputType inputType);

            // @brief Get the keyMapping
            // @return keyMappings The keyMapping
            const std::unordered_map<std::string, ConfigurableKey> &getKeyMapping() const;

            // @brief Check if an action is down
            // @param action The name of the action
            // @return True if the action is down, false otherwise
            bool isActionDown(const std::string& action) const;

            // @brief Check if an action is pressed
            // @param action The name of the action
            // @return True if the action is pressed, false otherwise
            bool isActionPressed(const std::string& action) const;

            // @brief Get the key code pressed and the input type
            // @return std::pair<int, InputType> The key code and the input type
            std::pair<int, InputType> getKeyPressed() const;

            // @brief remove a keyCode from an action
            // @param action The name of the action
            // @param keyCode The key code to remove
            void removeKeyMapping(const std::string &action, const int &keyCode);

            // @brief remove all keyCodes from an action
            // @param action The name of the action
            void removeAllKeyMapping(const std::string &action);

            // @brief clear all keyMappings
            void clearKeyMappings();
    };
}