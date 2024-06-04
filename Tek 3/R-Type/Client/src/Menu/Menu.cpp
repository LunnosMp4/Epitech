/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

using namespace Cereal;

Menu::Menu() {
    menuScene = CreateScene("MenuScene");
    setupEntities();
}

void Menu::run() {
    if (IsGamepadConnected(0)) {
        GetEntityByName("SubTitle").getComponent<Cereal::Text>()->text = "Press         to start";
        GetEntityByName("StartButton").getComponent<Render>()->enabled = true;
    } else {
        GetEntityByName("SubTitle").getComponent<Cereal::Text>()->text = "Press Enter to start";
        GetEntityByName("StartButton").getComponent<Render>()->enabled = false;
    }
    handleInputs();
}