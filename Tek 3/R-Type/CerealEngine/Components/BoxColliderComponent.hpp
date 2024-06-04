/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** BoxColliderComponent.hpp
*/

#pragma once

#include "../Systems/Component/Component.hpp"
namespace Raylib {
    #include <raylib.h>
}
using namespace Raylib;
#include <iostream>

namespace Cereal {
    class BoxCollider : public ComponentBase {
        public:
            BoundingBox box;

            BoxCollider() = default;

            BoxCollider(const BoundingBox& box) : box(box) {};

            BoxCollider(const Model model) {
                box = Raylib::GetMeshBoundingBox(model.meshes[0]);
            }

            BoxCollider(const Vector3& position, const Vector3& size) {
                box = {
                    Vector3{position.x - size.x / 2, position.y - size.y / 2, position.z - size.z / 2},
                    Vector3{position.x + size.x / 2, position.y + size.y / 2, position.z + size.z / 2}
                };
            }
    };
}
