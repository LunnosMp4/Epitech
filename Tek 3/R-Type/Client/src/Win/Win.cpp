/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** WIn.cpp
*/

#include "Win.hpp"

using namespace Cereal;

Win::Win() {
    gameWinScene = CreateScene("GameWinScene");
    setupEntities();
}

void Win::run() {
    if (IsGamepadConnected(0)) {
        GetEntityByName("SubTitle").getComponent<Cereal::Text>()->text = "Press         to restart";
        GetEntityByName("StartButton").getComponent<Render>()->enabled = true;
    } else {
        GetEntityByName("SubTitle").getComponent<Cereal::Text>()->text = "Press Enter to restart";
        GetEntityByName("StartButton").getComponent<Render>()->enabled = false;
    }
    handleInputs();
}
