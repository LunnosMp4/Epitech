/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Character.cpp
*/

#include "Character.hpp"

using namespace Zappy;

void Character::setResources(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame) {
    _resources.food = food;
    _resources.linemate = linemate;
    _resources.deraumere = deraumere;
    _resources.sibur = sibur;
    _resources.mendiane = mendiane;
    _resources.phiras = phiras;
    _resources.thystame = thystame;
}

std::string Character::getResources() const {
    std::string resources = std::to_string(_resources.food) + " " + std::to_string(_resources.linemate) + " " + std::to_string(_resources.deraumere) + " " + std::to_string(_resources.sibur) + " " + std::to_string(_resources.mendiane) + " " + std::to_string(_resources.phiras) + " " + std::to_string(_resources.thystame);
    return resources;
}

std::map<int, std::string> Character::getResourcesMap() const {
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