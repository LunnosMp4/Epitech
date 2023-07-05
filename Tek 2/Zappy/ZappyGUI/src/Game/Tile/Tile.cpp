/*
** EPITECH PROJECT, 2022
** ZappyGUI
** File description:
** TIle.cpp
*/

#include "Tile.hpp"

using namespace Zappy;

void Tile::setResources(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame) {
    _resources.food = food;
    _resources.linemate = linemate;
    _resources.deraumere = deraumere;
    _resources.sibur = sibur;
    _resources.mendiane = mendiane;
    _resources.phiras = phiras;
    _resources.thystame = thystame;
}

std::string Tile::getResources() const {
    std::string resources = std::to_string(_resources.food) + " " + std::to_string(_resources.linemate) + " " + std::to_string(_resources.deraumere) + " " + std::to_string(_resources.sibur) + " " + std::to_string(_resources.mendiane) + " " + std::to_string(_resources.phiras) + " " + std::to_string(_resources.thystame);
    return resources;
}

std::map<int, std::string> Tile::getResourcesMap() const {
    std::map<int, std::string> resources;
    resources[0] = std::to_string(_resources.food);
    resources[1] = std::to_string(_resources.linemate);
    resources[2] = std::to_string(_resources.deraumere);
    resources[3] = std::to_string(_resources.sibur);
    resources[4] = std::to_string(_resources.mendiane);
    resources[5] = std::to_string(_resources.phiras);
    resources[6] = std::to_string(_resources.thystame);
    return resources;
}

void Tile::drawResources(std::map<std::string, Model> models) const {
    std::vector<std::string> resources;
    for (int i = 0; i < _resources.food; i++)
        resources.push_back("food");
    for (int i = 0; i < _resources.linemate; i++)
        resources.push_back("linemate");
    for (int i = 0; i < _resources.deraumere; i++)
        resources.push_back("deraumere");
    for (int i = 0; i < _resources.sibur; i++)
        resources.push_back("sibur");
    for (int i = 0; i < _resources.mendiane; i++)
        resources.push_back("mendiane");
    for (int i = 0; i < _resources.phiras; i++)
        resources.push_back("phiras");
    for (int i = 0; i < _resources.thystame; i++)
        resources.push_back("thystame");

    std::mt19937 g(6);
    std::shuffle(resources.begin(), resources.end(), g);

    float spacing = 0.4f;
    float size = 0.4f;
    float rotationSpeed = 0.01f;
    static float rotationAngle = 0.0f;

    for (int i = 0; Cast(std::size_t, i) < resources.size(); i++) {
        Model model = models[resources[i]];
        Vector3 position = Vector3{this->position.x, 1.4f, this->position.z};
        if (resources[i] == "food") {
            size = 0.05f;
            position.y = 1.2f;
            float angleFood = (float)rand() / RAND_MAX * 360;
            model.transform = MatrixRotateXYZ(Vector3{0, angleFood, 0});
        } else {
            size = 0.4f;
            rotationAngle += rotationSpeed * GetFrameTime();
            if (rotationAngle > 360)
                rotationAngle = 0;
            model.transform = MatrixRotateXYZ(Vector3{0, rotationAngle, 0});
        }

        position.x += (float)rand() / RAND_MAX * spacing - spacing / 2;
        position.z += (float)rand() / RAND_MAX * spacing - spacing / 2;
        DrawModel(model, position, size, WHITE);
    }
}