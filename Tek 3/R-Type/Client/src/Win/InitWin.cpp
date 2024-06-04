/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InitWin.cpp
*/

#include "Win.hpp"

using namespace Cereal;

void Win::setupEntities() {
    CreateEntity(gameWinScene)
        .addComponent<MusicAmbiant>(MusicAmbiant(THE_END, true, 1, 0.5f))
        .addComponent<Render>(Render(true));

    CreateEntity(gameWinScene, "BackgroundNebula")
        .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 1.0f))
        .addComponent<Sprite>(Sprite(BACKGROUND_NEBULA_RED, 0.01f, true))
        .addComponent<Render>(Render(true));

    CreateEntity(gameWinScene, "BackgroundStars1")
        .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 0.45f))
        .addComponent<Sprite>(Sprite(BACKGROUND_STARS1, 0.025f, true))
        .addComponent<Render>(Render(true));
    
    CreateEntity(gameWinScene, "BackgroundStars2")
        .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 0.45f))
        .addComponent<Sprite>(Sprite(BACKGROUND_STARS2, 0.04f, true))
        .addComponent<Render>(Render(true));

    CreateEntity(gameWinScene, "StartButton")
        .addComponent<Cereal::Transform>(Cereal::Transform({85, 77, 0}, {0, 0, 0}, 1.0f))
        .addComponent<Sprite>(Sprite(START_BUTTON, 0.0f, false))
        .addComponent<Render>(Render(false));

    CreateText(gameWinScene, "MainTitle", "You Win !", {20, 20}, 50, NASALIZA, WHITE);
    CreateText(gameWinScene, "SubTitle", "Press Enter to restart !", {20, 80}, 20, NASALIZA, WHITE);
}
