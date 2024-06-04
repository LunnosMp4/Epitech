/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InputsMenu.cpp
*/

#include "Menu.hpp"

using namespace Cereal;

void Menu::handleInputs() {
    const std::string actionDown = GetActionDown();

    if (actionDown == "Enter") {
        SetCurrentScene("GameScene");
        return;
    }
}
