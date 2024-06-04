/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InitOver.cpp
*/

#include "Over.hpp"

using namespace Cereal;

void Over::setupEntities() {
    CreateEntity(gameOverScene)
        .addComponent<MusicAmbiant>(MusicAmbiant(THE_END, true, 1, 0.5f))
        .addComponent<Render>(Render(true));

    CreateEntity(gameOverScene, "BackgroundNebula")
        .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 1.0f))
        .addComponent<Sprite>(Sprite(BACKGROUND_NEBULA_RED, 0.01f, true))
        .addComponent<Render>(Render(true));

    CreateEntity(gameOverScene, "BackgroundStars1")
        .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 0.45f))
        .addComponent<Sprite>(Sprite(BACKGROUND_STARS1, 0.025f, true))
        .addComponent<Render>(Render(true));
    
    CreateEntity(gameOverScene, "BackgroundStars2")
        .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 0.45f))
        .addComponent<Sprite>(Sprite(BACKGROUND_STARS2, 0.04f, true))
        .addComponent<Render>(Render(true));

    CreateEntity(gameOverScene, "StartButton")
        .addComponent<Cereal::Transform>(Cereal::Transform({85, 77, 0}, {0, 0, 0}, 1.0f))
        .addComponent<Sprite>(Sprite(START_BUTTON, 0.0f, false))
        .addComponent<Render>(Render(false));

    CreateText(gameOverScene, "MainTitle", "You die", {20, 20}, 50, NASALIZA, WHITE);
    CreateText(gameOverScene, "SubTitle", "Press Enter to restart", {20, 80}, 20, NASALIZA, WHITE);
}
