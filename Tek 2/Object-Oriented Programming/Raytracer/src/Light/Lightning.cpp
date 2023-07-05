/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Lightning.cpp
*/

#include "Raytracer.hpp"

// @brief Ambient light / Directional light
Color computeLighting(Raytracer::Ray r, std::vector<std::shared_ptr<Raytracer::Primitive>> primitives, Raytracer::Light light, int depth, bool isAmbiant) {
    double ambient_strength = light.ambient;
    double diffuse_strength = light.diffuse;
    if (isAmbiant)
        ambient_strength = 0.5;
    double specular_strength = 0.5;
    double reflection_strength = 0;
    double transparency_strength = 0;
    double ior = 0;

    std::shared_ptr<Raytracer::Primitive> closestPrimitive = nullptr;
    double closestDistance = std::numeric_limits<double>::max();
    for (auto primitive : primitives) {
        auto hit = primitive->hits(r);
        if (hit.has_value()) {
            double distance = (hit.value().first - r.origin).length();
            if (distance < closestDistance) {
                closestDistance = distance;
                closestPrimitive = primitive;
            }
            transparency_strength = hit.value().second.transparency;
            reflection_strength = hit.value().second.reflection;
            ior = hit.value().second.ior;
        }
    }

    if (closestPrimitive == nullptr)
        return Color(0, 0, 0);

    Math::Point3D point = r.origin + (r.direction * closestDistance);
    Math::Vector3D normal = closestPrimitive->getNormal(point);
    Math::Vector3D toLight = (light.position - point).normalized();
    Math::Vector3D toCamera = (Math::Point3D(0, 0, 0) - point).normalized();
    Math::Vector3D halfway = (toLight + toCamera).normalized();
    double diffuse = std::max(0.0, normal.dot(toLight));
    double specular = std::pow(std::max(0.0, normal.dot(halfway)), 50);

    Color surfaceColor = closestPrimitive->getColor();
    Color lightColor(255, 255, 255);

    // Handle reflection
    if (reflection_strength > 0 && depth < MAX_DEPTH) {
        Math::Vector3D reflectionDir = r.direction - (normal * 2 * r.direction.dot(normal));
        Raytracer::Ray reflectionRay(point + reflectionDir * 0.001, reflectionDir);
        Color reflectionColor = computeLighting(reflectionRay, primitives, light, depth + 1, isAmbiant) * reflection_strength;
        return surfaceColor * (1 - transparency_strength) * (ambient_strength + diffuse_strength * diffuse + specular_strength * specular) + reflectionColor;
    }

    // Handle transparency
    if (transparency_strength > 0 && depth < MAX_DEPTH) {
        Raytracer::Ray transparencyRay(point + r.direction * 0.001, r.direction);
        Color transparencyColor = computeLighting(transparencyRay, primitives, light, depth + 1, isAmbiant) * transparency_strength;
        return surfaceColor * (1 - transparency_strength) * (ambient_strength + diffuse_strength * diffuse + specular_strength * specular) + transparencyColor;
    }

    // Handle refraction
    if (ior > 0 && transparency_strength > 0 && depth < MAX_DEPTH) {
        double cosi = std::max(-1.0, std::min(1.0, r.direction.dot(normal)));
        double etai = 1.0;
        double etat = ior;
        Math::Vector3D n = normal;
        if (cosi < 0) {
            cosi = -cosi;
        } else {
            std::swap(etai, etat);
            n = -normal;
        }
        double eta = etai / etat;
        double k = 1 - eta * eta * (1 - cosi * cosi);
        Math::Vector3D refractedDir = k < 0 ? Math::Vector3D(0, 0, 0) : (r.direction * eta + n * (eta * cosi - std::sqrt(k)));
        Raytracer::Ray refractedRay(point + refractedDir * 0.001, refractedDir);
        return computeLighting(refractedRay, primitives, light, depth + 1, isAmbiant) * ior;
    }
    if (isAmbiant)
        return surfaceColor * ambient_strength;

    Color result = surfaceColor * (ambient_strength + diffuse_strength * diffuse + specular_strength * specular);

    return result;
}
