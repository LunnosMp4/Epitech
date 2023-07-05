/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-loic.tisseyre
** File description:
** Raytracer.cpp
*/

#pragma once

#include "../Main/Math.hpp"
#include "Utils.hpp"
#include <string>
#include <utility>
#include <optional>

namespace Raytracer {
    class Ray {
        public:
            Math::Point3D origin;
            Math::Vector3D direction;

            Ray() = default;
            Ray(const Math::Point3D& origin, const Math::Vector3D& direction)
                : origin(origin), direction(direction) {}
            Ray(const Ray& other) = default;
            Ray(Ray&& other) noexcept = default;

            Ray& operator=(const Ray& other) = default;
            Ray& operator=(Ray&& other) noexcept = default;
    };
}
