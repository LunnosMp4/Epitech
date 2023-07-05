/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Egg.hpp
*/

#pragma once

#include "ZappyGUI.h"

namespace Zappy
{

    class Egg
    {
        public:
            Egg(Vector3 position, int id, int idParent) : position(position), id(id), idParent(idParent) {};
            ~Egg() = default;
            bool isValid() const { return position.x != 0 || position.z != 0; };

            mutable Vector3 position;
            int id;
            int idParent;
            Model model;
    };
}