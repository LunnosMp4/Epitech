/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Character.hpp
*/

#pragma once

#include "ZappyGUI.h"

namespace Zappy
{

    class Character
    {
        public:
            Character(Vector3 position) : position(position) {};
            Character(Vector3 position, int id, int orientation, int level, std::string team) : position(position), id(id), orientation(orientation), level(level), team(team) {};
            ~Character() {
            };
            bool isValid() const { return position.x != 0 || position.z != 0; };

            void setResources(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame);
            std::string getResources() const;
            std::map<int, std::string> getResourcesMap() const;

            Model model;
            ModelAnimation *modelAnimations = NULL;
            unsigned int animsCount = 0;
            unsigned int animIndex = 0;
            unsigned int animCurrentFrame = 0;
    
            mutable Vector3 position;
            mutable Vector3 newPosition;
            mutable Vector3 currentPosition;
            mutable bool isMoving = false;
            mutable bool isIncantating = false;
            mutable bool isEjected = false;

            double moveStartTime;
            double incantationStartTime;
            double ejectStartTime;
            float moveDuration;
            float incantationDuration;
            float ejectDuration;

            int id;
            int orientation;
            int level;
            std::string team;
            mutable int animType = 2;

        private:
            struct Resources {
                int food = 0;
                int linemate = 0;
                int deraumere = 0;
                int sibur = 0;
                int mendiane = 0;
                int phiras = 0;
                int thystame = 0;
            } _resources;
    };
}