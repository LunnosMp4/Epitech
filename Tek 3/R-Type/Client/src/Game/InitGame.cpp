/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InitMenu.cpp
*/

#include "Game.hpp"

using namespace Cereal;

void Game::setupEntities() {
    CreateLight(gameScene, {0, -10, 300}, WHITE);

    CreateEntity(gameScene)
            .addComponent<MusicAmbiant>(MusicAmbiant(GAME, true, 1, 0.5f))
            .addComponent<SoundAmbiant>(SoundAmbiant(INTERFACE, true, 0.4f))
            .addComponent<Render>(Render(true))
            .addTagToEntity("Elementary");

    /* Background */
    CreateEntity(gameScene, "BackgroundNebula")
            .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 1.0f))
            .addComponent<Sprite>(Sprite(BACKGROUND_NEBULA, 0.01f, true))
            .addComponent<Render>(Render(true))
            .addTagToEntity("Elementary");

    CreateEntity(gameScene, "BackgroundStars1")
            .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 0.45f))
            .addComponent<Sprite>(Sprite(BACKGROUND_STARS1, 0.025f, true))
            .addComponent<Render>(Render(true))
            .addTagToEntity("Elementary");
    
    CreateEntity(gameScene, "BackgroundStars2")
            .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 0.45f))
            .addComponent<Sprite>(Sprite(BACKGROUND_STARS2, 0.04f, true))
            .addComponent<Render>(Render(true))
            .addTagToEntity("Elementary");

    /* Player */
    CreateEntity(gameScene, "Player")
            .addComponent<Cereal::Transform>(Cereal::Transform({0, 0, 0}, {0, 0, 0}, 0.01f))
            .addComponent<Stats>(Stats(100000, 20, 0.1f))
            .addComponent<Model3D>(Model3D(SHIP, {1, 1, 0}, 180))
            .addComponent<Render>(Render(false))
            .addComponent<Inventory>(Inventory())
            .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{9, 5, 6})
            .addComponent<SoundAmbiant>(SoundAmbiant(EXPLOSION, false, 1.0f)).addTag<SoundAmbiant>("SoundExplosion")
            .addTagToEntity("Elementary");

    CreateEntity(gameScene, "Score")
            .addComponent<Cereal::Text>(Cereal::Text("Score: 0", {(float)Raylib::GetScreenWidth() / 2 - 50, 10}, 20, NASALIZA, WHITE))
            .addComponent<Cereal::Render>(Cereal::Render(true))
            .addTagToEntity("Elementary");

    CreateEntity(gameScene, "Life")
            .addComponent<Cereal::Text>(Cereal::Text("Life: 100", {10, (float)GetScreenHeight() - 90}, 20, NASALIZA, WHITE))
            .addComponent<Cereal::Render>(Cereal::Render(true))
            .addTagToEntity("Elementary");

    CreateEntity(gameScene, "Missile")
            .addComponent<Cereal::Text>(Cereal::Text("Missile: 3", {10, (float)GetScreenHeight() - 60}, 20, NASALIZA, WHITE))
            .addComponent<Cereal::Render>(Cereal::Render(true))
            .addTagToEntity("Elementary");

    CreateEntity(gameScene, "Notice")
            .addComponent<Cereal::Text>(Cereal::Text("Press Space to shoot", {10, (float)GetScreenHeight() - 30}, 20, NASALIZA, WHITE))
            .addComponent<Cereal::Render>(Cereal::Render(true))
            .addTagToEntity("Elementary");

    CreateEntity(gameScene, "NoticeIcon")
            .addComponent<Cereal::Transform>(Cereal::Transform({80, (float)GetScreenHeight() - 35, 0}, {0, 0, 0}, 0.8f))
            .addComponent<Sprite>(Sprite(A_BUTTON, 0.0f, false))
            .addComponent<Render>(Render(false))
            .addTagToEntity("Elementary");

    createFriend();

    AddLightToAllModelsInScene(GetLightComponentInScene(gameScene), gameScene);
    AddItem(*GetEntityByNameInScene("Player", gameScene).getComponent<Inventory>(), "Missile", 3);
}
