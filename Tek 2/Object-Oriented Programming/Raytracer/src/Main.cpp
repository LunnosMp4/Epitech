/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-loic.tisseyre
** File description:
** Main.cpp
*/

#include "Raytracer.hpp"
#include "PrimitiveFactory.hpp"
#include "PostProcessor.hpp"

double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

void write_color(Color pixel_color) {
    std::cout << static_cast<int>(pixel_color.r) << ' ' << static_cast<int>(pixel_color.g) << ' ' << static_cast<int>(pixel_color.b) << ' ' << std::endl;
}

std::vector<std::shared_ptr<Raytracer::Primitive>> add_primitives_from_scene(Scene scene) {
    std::vector<std::shared_ptr<Raytracer::Primitive>> primitives;
    Raytracer::PrimitiveFactory factory;

    for (auto sphere : scene.spheres)
        primitives.push_back(factory.createSphere(sphere.center, sphere.radius, sphere.rotation, sphere.material));
    for (auto plane : scene.planes)
        primitives.push_back(factory.createPlane(plane.origin, plane.axis, plane.rotation, plane.material));
    for (auto cylinder : scene.cylinders)
        primitives.push_back(factory.createCylinder(cylinder.center, cylinder.radius, cylinder.height, cylinder.rotation, cylinder.material));
    for (auto cone : scene.cones)
        primitives.push_back(factory.createCone(cone.center, cone.radius, cone.height, cone.rotation, cone.material));
    for (auto mobius_strip : scene.mobiusStrips)
        primitives.push_back(factory.createMobiusStrip(mobius_strip.center, mobius_strip.radius, mobius_strip.width, mobius_strip.rotation, mobius_strip.material));
    return primitives;
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./raytracer <scene_file>" << std::endl;
        return 84;
    }

    Scene scene = parseFile(av[1]);
    Raytracer::Camera cam(scene.camera.position, Raytracer::Rectangle3D(Math::Point3D(-0.5, -0.5, 1), Math::Vector3D(1, 0, 0), Math::Vector3D(0, 1, 0)));
    Raytracer::Light light(scene.light.pointLights[0].position, scene.light.ambient, scene.light.diffuse);

    std::vector<std::shared_ptr<Raytracer::Primitive>> primitives;
    primitives = add_primitives_from_scene(scene);

    const int image_width = scene.camera.resolution.x;
    const int image_height = scene.camera.resolution.y;

    int samples_per_pixel = scene.camera.antiAliasing;
    std::cout << "P3" << ' ' << image_width << ' ' << image_height << ' ' << 255 << ' ' << std::endl;

    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    std::atomic<double> progress{0.0};
    std::thread progress_thread(progress_bar, std::ref(progress), image_width, image_height, start_time);
    std::vector<Color> colors;

    for (int y = 0; y < image_height; ++y) {
        for (int x = 0; x < image_width; ++x) {
            Color pixel_color(0, 0, 0);

            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = (x + random_double()) / (image_width - 1);
                double v = (y + random_double()) / (image_height - 1);

                Raytracer::Ray r = cam.ray(u, v);
                pixel_color += computeLighting(r, primitives, light, 30, scene.light.isAmbiant);
            }

            colors.push_back(pixel_color / samples_per_pixel);

            double progress_value = static_cast<double>(y * image_width + x + 1) / (image_width * image_height);
            progress.store(progress_value);
        }
    }

    progress_thread.join();

    Raytracer::DecoratorPostProcessor decorator(scene.camera.postProcessing, colors);
    colors = decorator.applyPostProcess();

    for (int i = 0; i < image_width * image_height; ++i)
        write_color(colors[i]);

    return 0;
}