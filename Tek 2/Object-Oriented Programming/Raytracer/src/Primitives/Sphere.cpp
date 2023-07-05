/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

using namespace Raytracer;

std::optional<std::pair<Math::Point3D, Material>> Sphere::hits(const Ray& ray) const {
    Math::Vector3D oc = ray.origin - center;
    double a = ray.direction.dot(ray.direction);
    double b = 2 * oc.dot(ray.direction);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return std::nullopt;

    double t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    double t2 = (-b + std::sqrt(discriminant)) / (2 * a);

    if (t1 >= 0 || t2 >= 0) {
        double t = t1 < t2 ? t1 : t2;
        Math::Point3D point = ray.origin + (ray.direction * t);
        return std::make_pair(point, material);
    }

    return std::nullopt;
}

Math::Vector3D Sphere::getNormal(const Math::Point3D& point) const {
    return (point - center).normalized();
}

Color Sphere::getColor() const {
    return material.color;
}