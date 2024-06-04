/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** TextComponent.hpp
*/

#pragma once

namespace Raylib {
    #include <raylib.h>
}

using namespace Raylib;

#include "../Systems/Component/Component.hpp"
#include "../Systems/Resource/ResourceManager.hpp"

namespace Cereal {
    class Text : public ComponentBase {
        public:
            std::string text;
            Vector2 position;
            int fontSize;
            Font font;
            Color color;

            Text(std::string text = "", Vector2 position = {0, 0}, int fontSize = 0, std::string fontPath = "", Color color = WHITE) {
                this->text = text;
                this->position = position;
                this->fontSize = fontSize;
                this->color = color;
                if (!fontPath.empty()) {
                    font = ResourceManager::getInstance().getFont(fontPath);
                }
            }
    };
}
