/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** Light.hpp
*/

#include "Math.hpp"

namespace Raytracer {
    class Light {
        public:
            Math::Point3D position;
            double ambient;
            double diffuse;

            Light(const Math::Point3D& position, double ambient= 0.2, double diffuse= 1) : position(position), ambient(ambient), diffuse(diffuse) {};
    };
}
