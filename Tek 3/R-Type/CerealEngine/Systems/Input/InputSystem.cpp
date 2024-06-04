/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InputSystem.cpp
*/

#include "InputSystem.hpp"

using namespace Cereal;

std::string InputSystem::getActionDown() {
    for (auto& keyMapping : inputManager.getKeyMapping()) {
        if (inputManager.isActionDown(keyMapping.first)) {
            return keyMapping.first;
        }
    }
    return "";
}

std::string InputSystem::getActionPressed() {
    for (auto& keyMapping : inputManager.getKeyMapping()) {
        if (inputManager.isActionPressed(keyMapping.first)) {
            return keyMapping.first;
        }
    }
    return "";
}

std::pair<int, InputType> InputSystem::getKeyPressed() {
    std::pair<int, InputType> key;
    key = inputManager.getKeyPressed();
    return key;
}

void InputSystem::configureKeys() {
    inputManager.setKeyMapping("MoveRight", Cereal::KeyBoard::KeyRight, Cereal::InputType::Keyboard_T);
    inputManager.setKeyMapping("MoveRight", Cereal::GamePad::DPadRight, Cereal::InputType::Gamepad_T);
    inputManager.setKeyMapping("MoveRight", Cereal::KeyBoard::KeyD, Cereal::InputType::Keyboard_T);
    inputManager.setKeyMapping("MoveLeft", Cereal::KeyBoard::KeyLeft, Cereal::InputType::Keyboard_T);
    inputManager.setKeyMapping("MoveLeft", Cereal::GamePad::DPadLeft, Cereal::InputType::Gamepad_T);
    inputManager.setKeyMapping("MoveLeft", Cereal::KeyBoard::KeyA, Cereal::InputType::Keyboard_T);
    inputManager.setKeyMapping("MoveUp", Cereal::KeyBoard::KeyUp, Cereal::InputType::Keyboard_T);
    inputManager.setKeyMapping("MoveUp", Cereal::GamePad::DPadUp, Cereal::InputType::Gamepad_T);
    inputManager.setKeyMapping("MoveUp", Cereal::KeyBoard::KeyW, Cereal::InputType::Keyboard_T);
    inputManager.setKeyMapping("MoveDown", Cereal::KeyBoard::KeyDown, Cereal::InputType::Keyboard_T);
    inputManager.setKeyMapping("MoveDown", Cereal::GamePad::DPadDown, Cereal::InputType::Gamepad_T);
    inputManager.setKeyMapping("MoveDown", Cereal::KeyBoard::KeyS, Cereal::InputType::Keyboard_T);
    inputManager.setKeyMapping("RightClick", Cereal::Mouse::MouseRight, Cereal::InputType::Mouse_T);
    inputManager.setKeyMapping("LeftClick", Cereal::Mouse::MouseLeft, Cereal::InputType::Mouse_T);
    inputManager.setKeyMapping("MiddleClick", Cereal::Mouse::MouseMiddle, Cereal::InputType::Mouse_T);
}

void InputSystem::mapKey(const std::string& actionName, const int& key, const InputType& inputType) {
    inputManager.setKeyMapping(actionName, key, inputType);
}

void InputSystem::removeKeyMapping(const std::string& actionName, const int& key) {
    inputManager.removeKeyMapping(actionName, key);
}

void InputSystem::removeAllKeyMapping(const std::string& actionName) {
    inputManager.removeAllKeyMapping(actionName);
}
