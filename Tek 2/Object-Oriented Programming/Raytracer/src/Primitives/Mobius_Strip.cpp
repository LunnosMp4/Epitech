/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** Mobius_Strip.cpp
*/

#include "Mobius_Strip.hpp"
#include <cmath>

using namespace Raytracer;

std::optional<std::pair<Math::Point3D, Material>> MobiusStrip::hits(const Ray& ray) const {
    // Paramétrisation du ruban de Möbius
    auto mobius = [&](double u, double v) -> Math::Point3D {
        double halfWidth = width / 2.0;
        double x = (radius + halfWidth * v * cos(u / 2.0)) * cos(u);
        double y = (radius + halfWidth * v * cos(u / 2.0)) * sin(u);
        double z = halfWidth * v * sin(u / 2.0);
        return Math::Point3D(x, y, z) + Math::Vector3D(center.x, center.y, center.z);
    };

    // Trouver l'intersection
    for (double u = 0; u <= 2 * M_PI; u += 0.01) {
        for (double v = -1.0; v <= 1.0; v += 0.01) {
            Math::Point3D point = mobius(u, v);
            Math::Vector3D oc = ray.origin - point;
            double t = oc.dot(ray.direction);

            if (t > 0) {
                Math::Point3D projected = ray.origin + ray.direction * t;
                double distance = (projected - point).length();

                if (distance <= 0.01) {
                    return std::make_pair(projected, material);
                }
            }
        }
    }

    return std::nullopt;
}

Math::Vector3D MobiusStrip::getNormal(const Math::Point3D& point) const {
    Math::Vector3D shifted = point - center;
    double u = atan2(shifted.y, shifted.x);
    double halfWidth = width / 2.0;
    double x = -radius * sin(u) - halfWidth * sin(u / 2.0) * cos(u / 2.0);
    double y = radius * cos(u) - halfWidth * sin(u / 2.0) * cos(u / 2.0);
    double z = halfWidth * cos(u / 2.0);
    return Math::Vector3D(x, y, z).normalized();
}

Color MobiusStrip::getColor() const {
    return material.color;
}