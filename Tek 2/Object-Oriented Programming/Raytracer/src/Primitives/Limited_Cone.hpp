/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** Cone.hpp
*/

#pragma once

#include "IPrimitive.hpp"

namespace Raytracer {
    class Cone : public Primitive {
        public:
            Math::Point3D center;
            double radius;
            double height;
            Math::Vector3D rotation;
            Material material;

            Cone(const Math::Point3D& center, double radius, double height, const Math::Vector3D& rotation, const Material& material)
                : center(center), radius(radius), height(height), rotation(rotation), material(material) {}

            std::optional<std::pair<Math::Point3D, Material>> hits(const Ray& ray) const;

            Math::Vector3D getNormal(const Math::Point3D& point) const;

            Color getColor() const;
    };
}
