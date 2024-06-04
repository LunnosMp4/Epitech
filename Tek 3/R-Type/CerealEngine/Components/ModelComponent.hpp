/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** ModelComponent.hpp
*/

#pragma once

#include "../Systems/Resource/ResourceManager.hpp"
#include "../Systems/Component/Component.hpp"

namespace Cereal {
    class Model3D : public ComponentBase {
        public:
            Model model;
            Vector3 rotationAxis;
            float rotationAngle;

            Model3D(const std::string& modelPath = "", Vector3 rotationAxis = {0, 0, 0}, float rotationAngle = 0) : rotationAxis(rotationAxis), rotationAngle(rotationAngle) {
                if (!modelPath.empty()) {
                    model = ResourceManager::getInstance().getModel(modelPath);
                }
            }
    };
}
