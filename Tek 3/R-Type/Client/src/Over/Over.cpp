/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Over.cpp
*/

#include "Over.hpp"

using namespace Cereal;

Over::Over() {
    gameOverScene = CreateScene("GameOverScene");
    setupEntities();
}

void Over::run() {
    if (IsGamepadConnected(0)) {
        GetEntityByName("SubTitle").getComponent<Cereal::Text>()->text = "Press         to restart";
        GetEntityByName("StartButton").getComponent<Render>()->enabled = true;
    } else {
        GetEntityByName("SubTitle").getComponent<Cereal::Text>()->text = "Press Enter to restart";
        GetEntityByName("StartButton").getComponent<Render>()->enabled = false;
    }
    handleInputs();
}
