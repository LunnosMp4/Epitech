/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** LightComponent.hpp
*/

#pragma once

#include "../Systems/Component/Component.hpp"
#include <filesystem>

#define RLIGHTS_IMPLEMENTATION
namespace Raylib {
    #include "../rlights.h"
}
#define GLSL_VERSION    330

namespace Cereal {
    class LightComponent : public ComponentBase {
    public:
        Raylib::Vector3 position;
        Raylib::Color color;
        Raylib::Shader shader;
        Raylib::Light light;

        LightComponent() = default;

        LightComponent(const Raylib::Vector3& position, const Raylib::Color& color) : position(position), color(color) {
            std::string vertexShaderPath = "./assets/shaders/glsl" + std::to_string(GLSL_VERSION) + "/lighting.vs";
            std::string fragmentShaderPath = "./assets/shaders/glsl" + std::to_string(GLSL_VERSION) + "/lighting.fs";
            this->shader = Raylib::LoadShader(vertexShaderPath.c_str(), fragmentShaderPath.c_str());
            this->shader.locs[Raylib::SHADER_LOC_VECTOR_VIEW] = Raylib::GetShaderLocation(this->shader, "viewPos");
            int ambientLoc = Raylib::GetShaderLocation(this->shader, "ambient");
            float ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
            Raylib::SetShaderValue(this->shader, ambientLoc, ambient, Raylib::SHADER_UNIFORM_VEC4);

            this->light = Raylib::CreateLight(Raylib::LIGHT_POINT, position, Raylib::Vector3{0, 0, 0}, color, this->shader);
        }
    };
}