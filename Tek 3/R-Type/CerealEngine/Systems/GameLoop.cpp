/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** GameLoop.cpp
*/

#include "GameLoop.hpp"
#include <chrono>

using namespace Cereal;

bool GameLoop::WindowShouldClose() {
    return Raylib::WindowShouldClose() || !isRunning;
}

void GameLoop::render(bool debug) {
    renderSystem.updateComponents(debug);
}

void GameLoop::audio() {
    audioSystem.updateComponents();
}

void GameLoop::update() {
    physicsSystem.updateComponents();
}

void GameLoop::stop() {
    isRunning = false;
}
