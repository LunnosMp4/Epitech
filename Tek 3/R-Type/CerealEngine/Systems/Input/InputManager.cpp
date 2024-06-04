/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InputManager.cpp
*/

#include "InputManager.hpp"

using namespace Cereal;

void InputManager::setKeyMapping(const std::string &action, int keyCode, InputType inputType) {
    keyMappings[action].keyMappings.push_back({keyCode, inputType});
}

const std::unordered_map<std::string, ConfigurableKey> &InputManager::getKeyMapping() const {
    return keyMappings;
}

bool InputManager::isActionDown(const std::string &action) const {
    auto it = keyMappings.find(action);
    if (it != keyMappings.end()) {
        for (const auto &keyMapping : it->second.keyMappings) {
            if (keyMapping.inputType == InputType::Keyboard_T && IsKeyDown(keyMapping.keyCode))
                return true;

            if (keyMapping.inputType == InputType::Mouse_T && IsMouseButtonDown(keyMapping.keyCode))
                return true;

            if (IsGamepadAvailable(0)) {
                if (keyMapping.inputType == InputType::Gamepad_T && IsGamepadButtonDown(0, keyMapping.keyCode)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool InputManager::isActionPressed(const std::string &action) const {
    auto it = keyMappings.find(action);
    if (it != keyMappings.end()) {
        for (const auto &keyMapping : it->second.keyMappings) {
            if (keyMapping.inputType == InputType::Keyboard_T && IsKeyPressed(keyMapping.keyCode))
                return true;

            if (keyMapping.inputType == InputType::Mouse_T && IsMouseButtonPressed(keyMapping.keyCode))
                return true;

            if (IsGamepadAvailable(0)) {
                if (keyMapping.inputType == InputType::Gamepad_T && IsGamepadButtonPressed(0, keyMapping.keyCode)) {
                    return true;
                }
            }
        }
    }
    return false;
}

std::pair<int, InputType> InputManager::getKeyPressed() const {
    int key = Raylib::GetKeyPressed();

    if (key != 0) {
        return { key, InputType::Keyboard_T };
    }
    if (IsGamepadAvailable(0)) {
        int keyGamepad = Raylib::GetGamepadButtonPressed();

        if (keyGamepad != 0) {
            return { keyGamepad, InputType::Gamepad_T };
        }
    }
    return { 0, InputType::Unknown };
}

void InputManager::removeKeyMapping(const std::string &action, const int &keyCode) {
    auto it = keyMappings.find(action);
    if (it != keyMappings.end()) {
        for (auto &keyMapping : it->second.keyMappings) {
            if (keyMapping.keyCode == keyCode) {
                keyMapping.keyCode = 0;
                keyMapping.inputType = InputType::Unknown;
            }
        }
    }
}

void InputManager::removeAllKeyMapping(const std::string &action) {
    auto it = keyMappings.find(action);
    if (it != keyMappings.end()) {
        for (auto &keyMapping : it->second.keyMappings) {
            keyMapping.keyCode = 0;
            keyMapping.inputType = InputType::Unknown;
        }
    }
}

void InputManager::clearKeyMappings() {
    keyMappings.clear();
}