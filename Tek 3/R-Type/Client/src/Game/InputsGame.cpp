/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InputsMenu.cpp
*/

#include "Game.hpp"

using namespace Cereal;

void Game::handleInputs() {
    const std::string actionDown = GetActionDown();

    auto player = GetEntityByName("Player");
    auto playerTransform = player.getComponent<Cereal::Transform>();
    auto playerStats = player.getComponent<Stats>();

    if (actionDown == "MoveRight") {
        playerTransform->position.x += playerStats->velocity;
    } else if (actionDown == "MoveLeft") {
        playerTransform->position.x -= playerStats->velocity;
    } else if (actionDown == "MoveUp") {
        playerTransform->position.z += playerStats->velocity;
    } else if (actionDown == "MoveDown") {
        playerTransform->position.z -= playerStats->velocity;
    }

    
}

void Game::handleCollision() {
}
