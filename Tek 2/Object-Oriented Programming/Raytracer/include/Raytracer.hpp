/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** Raytracer.hpp
*/

#pragma once

/* Libs */
#include <vector>
#include <iostream>
#include <string>
#include <random>
#include <memory>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <thread>
#include <atomic>
#include <libconfig.h++>

/* Primitives */
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Limited_Cylinder.hpp"
#include "Limited_Cone.hpp"
#include "Mobius_Strip.hpp"
#include "Torus.hpp"
#include "Tanglecube.hpp"

/* Main */
#include "Rectangle.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include "Math.hpp"
#include "Utils.hpp"

#define MAX_DEPTH 40

/* Not a form, but the dimension of the screen */
typedef struct Rectangle {
    Math::Point3D origin;
    Math::Vector3D bottom_side;
    Math::Vector3D left_side;
    Material material;
} Rectangle;

typedef struct Sphere {
    Math::Point3D center;
    double radius;
    Math::Vector3D rotation;
    Material material;
} Sphere;

typedef struct Plane {
    Math::Point3D origin;
    std::string axis;
    Math::Vector3D rotation;
    Material material;
} Plane;

typedef struct Cylinder {
    Math::Point3D center;
    double radius;
    double height;
    Math::Vector3D rotation;
    Material material;
} Cylinder;

typedef struct Cone {
    Math::Point3D center;
    double radius;
    double height;
    Math::Vector3D rotation;
    Material material;
} Cone;

typedef struct MobiusStrip {
    Math::Point3D center;
    double radius;
    double width;
    Math::Vector3D rotation;
    Material material;
} MobiusStrip;

typedef struct Camera {
    Vector2f resolution;
    Math::Point3D position;
    Math::Vector3D rotation;
    float fov;
    float antiAliasing;
    std::string postProcessing;
} Camera;

typedef struct PointLight {
    Math::Point3D position;
} PointLight;

typedef struct Light {
    float ambient;
    float diffuse;
    bool isAmbiant;

    std::vector<PointLight> pointLights;
} Light;

typedef struct Scene {
    std::vector<Sphere> spheres;
    std::vector<Plane> planes;
    std::vector<Rectangle> rectangles;
    std::vector<Cylinder> cylinders;
    std::vector<Cone> cones;
    std::vector<MobiusStrip> mobiusStrips;
    Camera camera;
    Light light;
} Scene;

Scene parseFile(std::string filename);
Color computeLighting(Raytracer::Ray r, std::vector<std::shared_ptr<Raytracer::Primitive>> primitives, Raytracer::Light light, int depth, bool isAmbiant);
void progress_bar(std::atomic<double>& progress, int image_width, int image_height, std::chrono::steady_clock::time_point start_time);