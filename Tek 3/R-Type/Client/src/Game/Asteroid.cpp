/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Enemy.cpp
*/

#include "Game.hpp"

using namespace Cereal;

void Game::createAsteroid() {
    asteroidCount++;
    std::string asteroidString = "Asteroid" + std::to_string(asteroidCount);
    std::vector<std::string> asteroidModels = {ASTEROID1, ASTEROID2, ASTEROID3, ASTEROID4, ASTEROID5};
    const int randomModel = rand() % asteroidModels.size();
    const float randomZ = (rand() % 20) - 10;

    CreateEntity(gameScene, asteroidString)
        .addComponent<Cereal::Transform>(Cereal::Transform({70, 0, randomZ}, {0, 0, 0}, 0.006f))
        .addComponent<Model3D>(Model3D(asteroidModels[randomModel], {1, 1, 1}, 180))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{5, 5, 5})
        .addComponent<Render>(Render(true));

    AddLightShaderToModel(*GetEntityByName(asteroidString).getComponent<Model3D>(), *GetLightComponentInScene(gameScene));

    std::function<void()> asteroidScript = [asteroidString]() {
        auto asteroid = GetEntityByName(asteroidString);
        auto asteroidModel = asteroid.getComponent<Model3D>();
        auto asteroidTransform = asteroid.getComponent<Cereal::Transform>();

        if (asteroidTransform->position.x <= -70)
            DestroyEntity(asteroid);

        asteroidTransform->position.x -= 0.05f;

        float randomSpeed = (rand() % 60) + 60;
        randomSpeed /= 100;
        asteroidModel->rotationAngle += randomSpeed;

        if (CheckCollision(asteroid, GetEntityByName("Player"))) {
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
            SetCurrentScene("GameOverScene");
        }
    };

    GetEntityByNameInScene(asteroidString, gameScene).addComponent<Script>(Script(asteroidScript));
}


void Game::createBgAsteroid() {
    bgAsteroidCount++;
    std::string asteroidString = "BgAsteroid" + std::to_string(bgAsteroidCount);
    std::vector<std::string> asteroidModels = {ASTEROID1, ASTEROID2, ASTEROID3, ASTEROID4, ASTEROID5};
    const int randomModel = rand() % asteroidModels.size();
    
    const float randomZ = (rand() % 120) - 60;
    const float randomY = (rand() % 35) + 100;

    CreateEntity(gameScene, asteroidString)
        .addComponent<Cereal::Transform>(Cereal::Transform({150, randomY, randomZ}, {0, 0, 0}, 0.004f))
        .addComponent<Model3D>(Model3D(asteroidModels[randomModel], {1, 1, 1}, 180))
        .addComponent<Render>(Render(true));

    AddLightShaderToModel(*GetEntityByName(asteroidString).getComponent<Model3D>(), *GetLightComponentInScene(gameScene));

    std::function<void()> asteroidScript = [asteroidString]() {
        auto asteroid = GetEntityByName(asteroidString);
        auto asteroidModel = asteroid.getComponent<Model3D>();
        auto asteroidTransform = asteroid.getComponent<Cereal::Transform>();

        if (asteroidTransform->position.x <= -150)
            DestroyEntity(asteroid);

        float randomSpeed = (rand() % 15) + 15;
        randomSpeed /= 100;
        asteroidTransform->position.x -= randomSpeed;
        float randomRotation = (rand() % 200) + 100;
        randomRotation /= 100;
        asteroidModel->rotationAngle += randomRotation;
    };

    GetEntityByNameInScene(asteroidString, gameScene).addComponent<Script>(Script(asteroidScript));
}