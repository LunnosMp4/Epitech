/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** ScriptComponent.cpp
*/

#pragma once

#include <functional>
#include "../Systems/Component/Component.hpp"

namespace Cereal {
    class Script : public ComponentBase {
        public:
            std::function<void()> scriptFunction;

            Script() = default; 
            Script(const std::function<void()>& function) : scriptFunction(function) {}
        };
}
