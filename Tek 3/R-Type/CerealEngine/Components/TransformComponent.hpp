/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** TransformComponent.hpp
*/

#pragma once

namespace Raylib {
    #include <raylib.h>
}
using namespace Raylib;

#include "../Systems/Component/Component.hpp"

namespace Cereal {
    class Transform : public ComponentBase {
        public:
            Vector3 position;
            Vector3 rotation;
            float scale;

            Transform(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0}, float scale = 1): position(position), rotation(rotation), scale(scale) {};
    };
}
