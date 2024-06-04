/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InitMenu.cpp
*/

#include "Menu.hpp"

using namespace Cereal;

void Menu::setupEntities() {
    CreateEntity(menuScene)
        .addComponent<MusicAmbiant>(MusicAmbiant(MENU, true, 1, 0.5f))
        .addComponent<Render>(Render(true));

    /* Background */
    CreateEntity(menuScene, "BackgroundNebula")
            .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 1.0f))
            .addComponent<Sprite>(Sprite(BACKGROUND_NEBULA_BLUE, 0.01f, true))
            .addComponent<Render>(Render(true));

    CreateEntity(menuScene, "BackgroundStars1")
            .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 0.45f))
            .addComponent<Sprite>(Sprite(BACKGROUND_STARS1, 0.025f, true))
            .addComponent<Render>(Render(true));
    
    CreateEntity(menuScene, "BackgroundStars2")
            .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 0.45f))
            .addComponent<Sprite>(Sprite(BACKGROUND_STARS2, 0.04f, true))
            .addComponent<Render>(Render(true));

    CreateEntity(menuScene, "StartButton")
            .addComponent<Cereal::Transform>(Cereal::Transform({85, 77, 0}, {0, 0, 0}, 1.0f))
            .addComponent<Sprite>(Sprite(START_BUTTON, 0.0f, false))
            .addComponent<Render>(Render(false));

    CreateText(menuScene, "MainTitle", "N-Ty.pe", {20, 20}, 50, NASALIZA, WHITE);
    CreateText(menuScene, "SubTitle", "Press Enter to start", {20, 80}, 20, NASALIZA, WHITE);

    SetCurrentScene(menuScene);
}
