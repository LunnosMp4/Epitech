/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Draw.cpp
*/

#include "DrawSystem.hpp"

namespace Cereal {
    void DrawSystem::drawText(const std::string& text, int posX, int posY, int fontSize, Color color, std::optional<std::string> fontPath)
    {
        if (fontPath.has_value())
            Raylib::DrawTextEx(ResourceManager::getInstance().getFont(fontPath.value()), text.c_str(), {static_cast<float>(posX), static_cast<float>(posY)}, fontSize, 0, color);
        else
            Raylib::DrawText(text.c_str(), posX, posY, fontSize, color);
    }
}