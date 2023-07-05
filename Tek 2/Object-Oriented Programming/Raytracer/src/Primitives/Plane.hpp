/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** Plane.hpp
*/

#pragma once

#include "IPrimitive.hpp"

namespace Raytracer {
    class Plane : public Primitive {
        public:
            Math::Point3D position;
            std::string axis;
            Math::Vector3D rotation;
            Material material;

            Plane(const Math::Point3D& position, const std::string& axis, const Math::Vector3D& rotation, const Material& material)
                : position(position), axis(axis), rotation(rotation), material(material) {};

            std::optional<std::pair<Math::Point3D, Material>> hits(const Ray& ray) const;

            Math::Vector3D getNormal(const Math::Point3D& point) const;

            Color getColor() const;
    };
}

