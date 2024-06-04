/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** TimerComponent.hpp
*/

#pragma once

#include "../Systems/Component/Component.hpp"
#include <chrono>

namespace Cereal {
    class Timer : public ComponentBase {
        public:
            std::chrono::high_resolution_clock::time_point time;

            Timer() : time(std::chrono::high_resolution_clock::now()) {}
    };
}
