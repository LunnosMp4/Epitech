/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** LevelsManager.cpp
*/

#include "Game.hpp"

using namespace Cereal;

void Game::level1(double deltaTime) {
    if (GetItemQuantity(*GetEntityByName("Player").getComponent<Inventory>(), "Kills") == 10 && !bossSpawned) {
        createMiniBoss(1, Cereal::Stats(150, 50, 0.05f));
        bossSpawned = true;
    }

    if (GetItemQuantity(*GetEntityByName("Player").getComponent<Inventory>(), "Kills") == 11) {
        bossSpawned = false;
        currentLevel = 2;
    }

    if (enemySpawnTimer >= 4.0) {
        if (enemyCount < 10)
            createEnemy(Cereal::Stats(30, 10, 0.05f));
        enemySpawnTimer = 0.0;
    }

    Cereal::RenderText("Level 1", Raylib::GetScreenWidth() / 2 - 50, 30, 20, WHITE);
}

void Game::level2(double deltaTime) {
    if (GetItemQuantity(*GetEntityByName("Player").getComponent<Inventory>(), "Kills") == 26 && !bossSpawned) {
        createMiniBoss(2, Cereal::Stats(250, 70, 0.05f));
        bossSpawned = true;
    }
    if (GetItemQuantity(*GetEntityByName("Player").getComponent<Inventory>(), "Kills") == 27) {
        bossSpawned = false;
        currentLevel = 3;
    }

    if (enemySpawnTimer >= 3.0) {
        if (enemyCount < 26)
            createEnemy(Cereal::Stats(40, 20, 0.05f));
        enemySpawnTimer = 0.0;
    }

    Cereal::RenderText("Level 2", Raylib::GetScreenWidth() / 2 - 50, 30, 20, WHITE);
}

void Game::level3(double deltaTime) {
    if (GetItemQuantity(*GetEntityByName("Player").getComponent<Inventory>(), "Kills") == 47 && !bossSpawned) {
        createMiniBoss(1, Cereal::Stats(250, 70, 0.05f), 6);
        createMiniBoss(2, Cereal::Stats(250, 70, 0.05f), -6);
        bossSpawned = true;
    }
    if (GetItemQuantity(*GetEntityByName("Player").getComponent<Inventory>(), "Kills") == 49) {
        bossSpawned = false;
        currentLevel = 4;
    }

    if (enemySpawnTimer >= 2.5) {
        if (enemyCount < 47)
            createEnemy(Cereal::Stats(60, 20, 0.05f));
        enemySpawnTimer = 0.0;
    }

    Cereal::RenderText("Level 3", Raylib::GetScreenWidth() / 2 - 50, 30, 20, WHITE);
}

void Game::bossLevel(double deltaTime) {
    if (!finalBossSpawned) {
        finalBossSpawned = true;
        createBigBoss(Cereal::Stats(500, 100, 0.07f));
    }

    if (GetItemQuantity(*GetEntityByName("Player").getComponent<Inventory>(), "Kills") == 50) {
        finalBossSpawned = false;
        for (auto& entity : GetEntitiesInCurrentScene()) {
            if (entity.name == "Player") {
                entity.getComponent<Stats>()->health = 100;
                entity.getComponent<Inventory>()->items.clear();
                AddItem(*entity.getComponent<Inventory>(), "Missile", 3);
                GetEntityByName("Score").getComponent<Cereal::Text>()->text = "Score: 0";
                GetEntityByName("Life").getComponent<Cereal::Text>()->text = "Life: 100";
                GetEntityByName("Camera").getComponent<Cereal::Camera>()->camera.position.y = -40.0f;
                entity.getComponent<Cereal::Transform>()->position = {0, 0, 0};
                continue;
            }

            if (entity.tag == "Elementary" || entity.name == "Camera" || entity.name == "Light")
                continue;

            DestroyEntity(entity);
        }
        SetCurrentScene("GameWinScene");
    }
}
