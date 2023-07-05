/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** Cone.cpp
*/

#include "Limited_Cone.hpp"

using namespace Raytracer;

std::optional<std::pair<Math::Point3D, Material>> Cone::hits(const Ray& ray) const {
    Math::Vector3D oc = ray.origin - center;
    double k = radius / height;
    k = k * k;

    double a = ray.direction.dot(ray.direction) - (1 + k) * ray.direction.y * ray.direction.y;
    double b = 2 * (oc.dot(ray.direction) - (1 + k) * oc.y * ray.direction.y);
    double c = oc.dot(oc) - (1 + k) * oc.y * oc.y;

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

Math::Vector3D Cone::getNormal(const Math::Point3D& point) const {
    Math::Vector3D normal = Math::Vector3D(point.x - center.x, 0, point.z - center.z);
    double y_normal = std::sqrt(normal.x * normal.x + normal.z * normal.z) * (-height / radius);
    normal.y = y_normal;
    return normal.normalized();
}

Color Cone::getColor() const {
    return material.color;
}
