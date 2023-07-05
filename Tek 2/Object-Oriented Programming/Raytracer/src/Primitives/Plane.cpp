/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** Plane.cpp
*/

#include "Plane.hpp"

using namespace Raytracer;

std::optional<std::pair<Math::Point3D, Material>> Plane::hits(const Ray& ray) const {
    double ray_dir_axis;
    double ray_origin_axis;
    double position_axis;

    if (axis == "X") {
        ray_dir_axis = ray.direction.x;
        ray_origin_axis = ray.origin.x;
        position_axis = position.x;
    } else if (axis == "Y") {
        ray_dir_axis = ray.direction.y;
        ray_origin_axis = ray.origin.y;
        position_axis = position.y;
    } else if (axis == "Z") {
        ray_dir_axis = ray.direction.z;
        ray_origin_axis = ray.origin.z;
        position_axis = position.z;
    } else
        return std::nullopt;

    double t = (position_axis - ray_origin_axis) / ray_dir_axis;
    if (t < 0)
        return std::nullopt;

    Math::Point3D hit_point = ray.origin + (ray.direction * t);

    if (axis == "X") {
        if (hit_point.y >= position.y && hit_point.y <= position.y + 10 &&
            hit_point.z >= position.z && hit_point.z <= position.z + 10) {
            return std::make_pair(ray.origin + (ray.direction * t), material);
        }
    } else if (axis == "Y") {
        if (hit_point.x >= position.x && hit_point.x <= position.x + 10 &&
            hit_point.z >= position.z && hit_point.z <= position.z + 10) {
            return std::make_pair(ray.origin + (ray.direction * t), material);
        }
    } else if (axis == "Z") {
        if (hit_point.x >= position.x && hit_point.x <= position.x + 10 &&
            hit_point.y >= position.y && hit_point.y <= position.y + 10) {
            return std::make_pair(ray.origin + (ray.direction * t), material);
        }
    }

    return std::nullopt;
}

Math::Vector3D Plane::getNormal(const Math::Point3D& point) const {
    (void)point;
    if (axis == "X")
        return Math::Vector3D(1, 0, 0);
    else if (axis == "Y")
        return Math::Vector3D(0, 1, 0);
    else if (axis == "Z")
        return Math::Vector3D(0, 0, 1);
    else
        return Math::Vector3D(0, 0, 0);
}

Color Plane::getColor() const {
    return material.color;
}