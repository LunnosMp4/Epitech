/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** IPrimitives.hpp
*/

#pragma once

#include "Ray.hpp"

namespace Raytracer {
    class Primitive {
        public:
            Material material;
        
            Primitive() : material(Material(0, 0, 0, Color(0, 0, 0))) {}
            Primitive(const Material& material) : material(material) {}
            virtual std::optional<std::pair<Math::Point3D, Material>> hits(const Ray& ray) const = 0;
            virtual Math::Vector3D getNormal(const Math::Point3D& point) const = 0;
            virtual Color getColor() const = 0;
    };
}
