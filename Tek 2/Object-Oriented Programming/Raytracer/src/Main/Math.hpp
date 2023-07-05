/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-loic.tisseyre
** File description:
** Math.hpp
*/

#pragma once

#include <cmath>

namespace Math {
    class Vector3D {
        public:
            double x, y, z;

            Vector3D() : x(0), y(0), z(0) {}
            Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

            Vector3D(const Vector3D& other) = default;
            Vector3D(Vector3D&& other) noexcept = default;
            Vector3D& operator=(const Vector3D& other) = default;
            Vector3D& operator=(Vector3D&& other) noexcept = default;

            double length() const {
                return std::sqrt(x*x + y*y + z*z);
            }

            double dot(const Vector3D& other) const {
                return x*other.x + y*other.y + z*other.z;
            }

            Vector3D operator+(const Vector3D& other) const {
                return Vector3D(x + other.x, y + other.y, z + other.z);
            }
            Vector3D& operator+=(const Vector3D& other) {
                x += other.x;
                y += other.y;
                z += other.z;
                return *this;
            }

            Vector3D operator-(const Vector3D& other) const {
                return Vector3D(x - other.x, y - other.y, z - other.z);
            }
            Vector3D operator-() const {
                return Vector3D(-x, -y, -z);
            }
            Vector3D& operator-=(const Vector3D& other) {
                x -= other.x;
                y -= other.y;
                z -= other.z;
                return *this;
            }

            Vector3D operator*(const double scalar) const {
                return Vector3D(x*scalar, y*scalar, z*scalar);
            }

            Vector3D& operator*=(const double scalar) {
                x *= scalar;
                y *= scalar;
                z *= scalar;
                return *this;
            }

            Vector3D operator/(const double scalar) const {
                return Vector3D(x/scalar, y/scalar, z/scalar);
            }
            Vector3D& operator/=(const double scalar) {
                x /= scalar;
                y /= scalar;
                z /= scalar;
                return *this;
            }

            Vector3D normalized() const {
                double len = length();
                return Vector3D(x / len, y / len, z / len);
            }

            Vector3D cross(const Vector3D& other) const {
                return Vector3D(y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x);
            }

            Vector3D rotate(const Vector3D& axis, double angle) const {
                Vector3D v = *this;
                Vector3D k = axis.normalized();
                double cos_angle = std::cos(angle);
                double sin_angle = std::sin(angle);
                return v*cos_angle + k.cross(v)*sin_angle + k*(k.dot(v))*(1 - cos_angle);
            }
        };

    class Point3D {
        public:
            double x, y, z;

            Point3D() : x(0), y(0), z(0) {}
            Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

            Point3D(const Point3D& other) = default;
            Point3D(Point3D&& other) noexcept = default;
            Point3D& operator=(const Point3D& other) = default;
            Point3D& operator=(Point3D&& other) noexcept = default;

            Point3D operator+(const Vector3D& vector) const {
                return Point3D(x + vector.x, y + vector.y, z + vector.z);
            }
            Vector3D operator-(const Point3D& other) const {
                return Vector3D(x - other.x, y - other.y, z - other.z);
            }
        };
}
