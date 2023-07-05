/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** PostProcessor.hpp
*/

#pragma once

#include "Raytracer.hpp"

namespace Raytracer {
    class PostProcessor {
        public:
            PostProcessor() {}

            virtual std::vector<Color> applyPostProcess(std::vector<Color> color) = 0;
    };

    class Noise : public PostProcessor {
        public:
            Noise() {}

            std::vector<Color> applyPostProcess(std::vector<Color> color) override {
                std::default_random_engine generator;
                std::uniform_real_distribution<double> distribution(-0.5, 0.5);
                std::vector<Color> new_colors;


                for (const auto& c : color) {
                    Color new_color(c.r + distribution(generator), c.g + distribution(generator), c.b + distribution(generator));
                    new_colors.push_back(new_color);
                }

                return new_colors;
            }
    };

    class BlackAndWhite : public PostProcessor {
        public:
            BlackAndWhite() {}

            std::vector<Color> applyPostProcess(std::vector<Color> color) override {
                std::default_random_engine generator;
                std::uniform_real_distribution<double> distribution(-0.5, 0.5);
                std::vector<Color> new_colors;


                for (const auto& c : color) {
                    double gray = 0.299 * c.r + 0.587 * c.g + 0.114 * c.b;
                    Color new_color(gray, gray, gray);
                    new_colors.push_back(new_color);
                }

                return new_colors;
            }
    };

    class Sepia : public PostProcessor {
        public:
            Sepia() {}

            std::vector<Color> applyPostProcess(std::vector<Color> color) override {
                std::vector<Color> new_colors;

                for (const auto& c : color) {
                    int r = static_cast<int>(0.393 * c.r + 0.769 * c.g + 0.189 * c.b);
                    int g = static_cast<int>(0.349 * c.r + 0.686 * c.g + 0.168 * c.b);
                    int b = static_cast<int>(0.272 * c.r + 0.534 * c.g + 0.131 * c.b);

                    new_colors.push_back(Color(r, g, b));
                }

                return new_colors;
            }
    };

    class Blur : public PostProcessor {
        public:
            Blur(int radius) : m_radius(radius) {}

            std::vector<Color> applyPostProcess(std::vector<Color> color) override {
                const int width = sqrt(color.size());
                std::vector<Color> new_colors(color.size());

                for (int y = 0; y < width; ++y) {
                    for (int x = 0; x < width; ++x) {
                        Color accum_color(0, 0, 0);
                        int count = 0;

                        for (int dy = -m_radius; dy <= m_radius; ++dy) {
                            for (int dx = -m_radius; dx <= m_radius; ++dx) {
                                int nx = x + dx;
                                int ny = y + dy;

                                if (nx >= 0 && nx < width && ny >= 0 && ny < width) {
                                    int index = ny * width + nx;
                                    accum_color += color[index];
                                    count++;
                                }
                            }
                        }

                        new_colors[y * width + x] = accum_color / count;
                    }
                }

                return new_colors;
            }

        private:
            int m_radius;
    };


    class DecoratorPostProcessor {
        public:
            DecoratorPostProcessor(std::string pp_effect, std::vector<Color> color) : _pp_effect(pp_effect), _color(color) {}
            std::vector<Color> applyPostProcess() {
                if (_pp_effect == "Noise") {
                    Noise noise;
                    return noise.applyPostProcess(_color);
                }
                if (_pp_effect == "BlackAndWhite") {
                    BlackAndWhite black_and_white;
                    return black_and_white.applyPostProcess(_color);
                }
                if (_pp_effect == "Sepia") {
                    Sepia sepia;
                    return sepia.applyPostProcess(_color);
                }
                if (_pp_effect == "Blur") {
                    Blur blur(10);
                    return blur.applyPostProcess(_color);
                }
                return _color;
            }

        protected:
            std::string _pp_effect;
            std::vector<Color> _color;
    };
}
