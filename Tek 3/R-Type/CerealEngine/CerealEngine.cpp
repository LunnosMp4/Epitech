/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** CerealEngine.cpp
*/

#include "CerealEngine.hpp"

using namespace Cereal;

Engine* Engine::instance = nullptr;

void Engine::InitGame(int width, int height, const std::string& title, int fps, bool fullscreen) {
    InitWindow(width, height, title.c_str());
    SetWindowPosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
    if (fullscreen)
        ToggleFullscreen();
    SetTargetFPS(fps);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitAudioDevice();
}

Engine::Engine(int width, int height, const std::string& title, int fps, bool fullscreen) :
    entityManager(),
    renderSystem(entityManager),
    inputSystem(entityManager),
    audioSystem(entityManager),
    physicsSystem(entityManager),
    entityFactory(entityManager),
    gameLoop(entityManager, renderSystem, inputSystem, audioSystem, physicsSystem, inventorySystem, drawSystem, entityFactory) {
    InitGame(width, height, title, fps, fullscreen);

    instance = this;
}

Engine::~Engine() {
    CloseAudioDevice();
    Raylib::CloseWindow();
}
