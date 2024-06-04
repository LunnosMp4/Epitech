/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** RenderComponent.cpp
*/

#pragma once

#include "../Systems/Component/Component.hpp"

namespace Cereal {
    class Render : public ComponentBase {
        public:
            bool enabled;

            Render(bool enabled = true): enabled(enabled) {}
    };
}
