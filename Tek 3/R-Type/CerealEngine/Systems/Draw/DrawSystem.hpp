/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Draw.hpp
*/

#pragma once

#include "../Resource/ResourceManager.hpp"
#include <string>
#include <optional>

namespace Cereal {
    class DrawSystem {
        public:
            static void drawText(const std::string& text, int posX, int posY, int fontSize, Color color, std::optional<std::string> fontPath = std::nullopt);
    };
}

