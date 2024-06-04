/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InputsWin.cpp
*/

#include "Win.hpp"

using namespace Cereal;

void Win::handleInputs() {
    const std::string actionDown = GetActionDown();

    if (actionDown == "Enter")
        SetCurrentScene("GameScene");
}
