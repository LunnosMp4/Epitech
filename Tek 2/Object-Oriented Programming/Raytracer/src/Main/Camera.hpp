/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-loic.tisseyre
** File description:
** Camera.hpp
*/

#pragma once

#include "Rectangle.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"

namespace Raytracer {
    class Camera {
        public:
            Camera() : origin(0, 0, 0), screen(Rectangle3D(Math::Point3D(-0.5, -0.5, 1), Math::Vector3D(1, 0, 0), Math::Vector3D(0, 1, 0))) {}
            Camera(const Math::Point3D& origin, const Rectangle3D& screen) : origin(origin), screen(screen) {}

            Ray ray(double u, double v) const {
                Math::Point3D screen_point = screen.pointAt(u, v);
                Math::Vector3D direction = screen_point - origin;
                return Ray(origin, direction);
            }

        private:
            Math::Point3D origin;
            Rectangle3D screen;
    };
}