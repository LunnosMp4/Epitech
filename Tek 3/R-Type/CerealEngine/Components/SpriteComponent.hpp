/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** SpriteComponent.cpp
*/

#pragma once

#include "../Systems/Resource/ResourceManager.hpp"
#include "../Systems/Component/Component.hpp"

namespace Cereal {
    class Sprite : public ComponentBase {
        public:
            Texture2D image;
            float speed = 0.0f;
            bool isLooping = false;
            mutable float currentFrame = 0.0f;

            Sprite(const std::string& texturePath = "", float speed = 0.0f, bool isLooping = false) : speed(speed), isLooping(isLooping) {
                if (!texturePath.empty()) {
                    image = ResourceManager::getInstance().getTexture(texturePath);
                }
            }
    };
}
