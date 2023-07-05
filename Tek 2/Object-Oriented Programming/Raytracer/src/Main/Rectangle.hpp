/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-loic.tisseyre
** File description:
** Rectangle.hpp
*/

#pragma once

#include "Math.hpp"

namespace Raytracer {
    class Rectangle3D {
        public:
            Math::Point3D origin;
            Math::Vector3D bottom_side;
            Math::Vector3D left_side;

            Rectangle3D() = default;
            Rectangle3D(const Math::Point3D& origin, const Math::Vector3D& bottom_side, const Math::Vector3D& left_side): origin(origin), bottom_side(bottom_side), left_side(left_side) {}

            Math::Point3D pointAt(double u, double v) const {
                Math::Vector3D u_offset = bottom_side * u;
                Math::Vector3D v_offset = left_side * v;
                return origin + u_offset + v_offset;
            }
    };
}
