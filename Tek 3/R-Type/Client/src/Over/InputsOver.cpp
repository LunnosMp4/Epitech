/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InputsOver.cpp
*/

#include "Over.hpp"

using namespace Cereal;

void Over::handleInputs() {
    const std::string actionDown = GetActionDown();

    if (actionDown == "Enter")
        SetCurrentScene("GameScene");
}
