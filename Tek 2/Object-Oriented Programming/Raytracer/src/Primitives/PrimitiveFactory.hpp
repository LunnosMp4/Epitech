/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** PrimitiveFactory.hpp
*/

#pragma once

#include "Raytracer.hpp"

namespace Raytracer {

    class PrimitiveFactory {
    public:
        static std::shared_ptr<Primitive> createSphere(const Math::Point3D& pos, double radius, const Math::Vector3D& rotation, const Material& material) {
            return std::make_shared<Sphere>(pos, radius, rotation, material);
        }
        static std::shared_ptr<Primitive> createPlane(const Math::Point3D& pos, const std::string axis, const Math::Vector3D& rotation, const Material& material) {
            return std::make_shared<Plane>(pos, axis, rotation, material);
        }
        static std::shared_ptr<Primitive> createCylinder(const Math::Point3D& pos, double radius, double height, const Math::Vector3D& rotation, const Material& material) {
            return std::make_shared<Cylinder>(pos, radius, height, rotation, material);
        }
        static std::shared_ptr<Primitive> createCone(const Math::Point3D& pos, double radius, double height, const Math::Vector3D& rotation, const Material& material) {
            return std::make_shared<Cone>(pos, radius, height, rotation, material);
        }
        static std::shared_ptr<Primitive> createMobiusStrip(const Math::Point3D& pos, double radius, double width, const Math::Vector3D& rotation, const Material& material) {
            return std::make_shared<MobiusStrip>(pos, radius, width, rotation, material);
        }
    };

}
