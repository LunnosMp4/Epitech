/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Component.hpp
*/

#pragma once

#include <optional>
#include <string>

namespace Cereal {
    class ComponentBase {
        public:
            virtual ~ComponentBase() = default;
    };

    template <typename T>
    class Component : public ComponentBase {
        public:
            T data;
            std::optional<std::string> tag;
    };
}
