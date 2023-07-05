/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Tile.hpp
*/

#pragma once

#include "ZappyGUI.h"

namespace Zappy {
    class Tile {
        public:
            Tile(Vector3 pos) : position(pos) {}
            ~Tile() = default;

            void setResources(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame);
            std::string getResources() const;
            std::map<int, std::string> getResourcesMap() const;

            void drawResources(std::map<std::string, Model> models) const;

            bool isValid() const { return position.x != 0 || position.z != 0; };
            Vector3 position;

            struct Resources {
                int food = 0;
                int linemate = 0;
                int deraumere = 0;
                int sibur = 0;
                int mendiane = 0;
                int phiras = 0;
                int thystame = 0;
            } _resources;

        private:
            mutable float _lastUpdate = 0;
    };
}