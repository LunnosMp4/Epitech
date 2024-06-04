/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Planets.cpp
*/

#include "Game.hpp"

using namespace Cereal;

void Game::createPlanets() {
    planetCount++;
    const std::string planetString = "Planet" + std::to_string(planetCount);

    const float randomZ = (rand() % 20) - 10;
    const float randomY = (rand() % 15) + 15;

    CreateEntity(gameScene, planetString)
        .addComponent<Cereal::Transform>(Cereal::Transform({70, randomY, randomZ}, {0, 0, 0}, 0.005f))
        .addComponent<Stats>(Stats(50, 10, 0.05f))
        .addComponent<Model3D>(Model3D(PLANET, {0, 0, 1}, 180))
        .addComponent<Render>(Render(true));

    AddLightShaderToModel(*GetEntityByName(planetString).getComponent<Model3D>(), *GetLightComponentInScene(gameScene));

    std::function<void()> planetScript = [planetString]() {
        auto planet = GetEntityByName(planetString);
        auto planetModel = planet.getComponent<Model3D>();
        auto planetTransform = planet.getComponent<Cereal::Transform>();

        if (planetTransform->position.x <= -70)
            DestroyEntity(planet);

        planetTransform->position.x -= 0.05f;
        float randomSpeed = (rand() % 20) + 20;
        randomSpeed /= 100;
        planetModel->rotationAngle += randomSpeed;
    };

    GetEntityByNameInScene(planetString, gameScene).addComponent<Script>(Script(planetScript));
}