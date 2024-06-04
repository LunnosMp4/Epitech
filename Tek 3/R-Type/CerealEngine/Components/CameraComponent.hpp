/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** CameraComponent.hpp
*/

#pragma once

namespace Raylib {
    #include <raylib.h>
}
using namespace Raylib;

#include "../Systems/Component/Component.hpp"

namespace Cereal {
    class Camera : public ComponentBase {
        public:
            Camera3D camera;

            Camera(Vector3 position = { 0.0f, 0.0f, 15.0f }, Vector3 target = { 0.0f, 0.0f, 0.0f },
                   Vector3 up = { 0.0f, 1.0f, 0.0f }, float fovy = 45.0f, int projection = CAMERA_PERSPECTIVE) {
                camera.position = position;
                camera.target = target;
                camera.up = up;
                camera.fovy = fovy;
                camera.projection = projection;
            }

            ~Camera() = default;

    };
}
