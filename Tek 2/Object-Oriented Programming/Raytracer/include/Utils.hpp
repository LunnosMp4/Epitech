/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** Utils.hpp
*/

#pragma once

struct Vector2f {
    float x;
    float y;

    Vector2f(float x, float y) : x(x), y(y) {};
    Vector2f() : x(0), y(0) {};

    bool operator==(const Vector2f &other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Vector2f &other) const {
        return (x != other.x || y != other.y);
    }
};

struct Color {
    float r;
    float g;
    float b;

    Color(float r, float g, float b) : r(r), g(g), b(b) {};
    Color() : r(0), g(0), b(0) {};

    bool operator==(const Color &other) const {
        return (r == other.r && g == other.g && b == other.b);
    }

    bool operator!=(const Color &other) const {
        return (r != other.r || g != other.g || b != other.b);
    }

    Color operator*(const float scalar) const {
        return Color(r*scalar, g*scalar, b*scalar);
    }

    Color operator*(const Color& other) const {
        return Color(r*other.r, g*other.g, b*other.b);
    }

    Color operator/(const float scalar) const {
        return Color(r/scalar, g/scalar, b/scalar);
    }

    Color& operator+(const Color& other) {
        r += other.r;
        g += other.g;
        b += other.b;
        return *this;
    }

    Color& operator+=(const Color& other) {
        r += other.r;
        g += other.g;
        b += other.b;
        return *this;
    }
};

struct Material {
    double transparency = 0;
    double reflection = 0;
    double ior = 0;
    Color color = {0, 0, 0};

    Material() = default;
    Material(double transparency, double reflection, double ior, const Color& color)
        : transparency(transparency), reflection(reflection), ior(ior), color(color)
    {}
};

