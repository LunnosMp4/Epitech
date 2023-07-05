/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** Cylinder.cpp
*/

#include "Limited_Cylinder.hpp"

using namespace Raytracer;

std::optional<std::pair<Math::Point3D, Material>> Cylinder::hits(const Ray& ray) const {
    Math::Vector3D oc = ray.origin - center;
    Math::Vector3D directionNoY = Math::Vector3D(ray.direction.x, 0, ray.direction.z);

    double a = directionNoY.dot(directionNoY);
    double b = 2 * oc.dot(directionNoY);
    double c = oc.dot(oc) - radius * radius;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return std::nullopt;

    double t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    double t2 = (-b + std::sqrt(discriminant)) / (2 * a);

    if (t1 >= 0 || t2 >= 0) {
        double t = t1 < t2 ? t1 : t2;
        Math::Point3D point = ray.origin + (ray.direction * t);

        if (point.y >= center.y && point.y <= center.y + height) {
            return std::make_pair(point, material);
        }
    }

    return std::nullopt;
}

Math::Vector3D Cylinder::getNormal(const Math::Point3D& point) const {
    Math::Vector3D normal = Math::Vector3D(point.x - center.x, 0, point.z - center.z);
    return normal.normalized();
}

Color Cylinder::getColor() const {
    return material.color;
}
