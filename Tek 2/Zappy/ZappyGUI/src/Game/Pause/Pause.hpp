/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Pause.hpp
*/

#pragma once

#include "ZappyGUI.h"
#include "Raylib.hpp"
#include "Network.hpp"

namespace Zappy {
    class Pause {
        public:
            Pause();
            void update();
            void draw();

            void setPause(bool isPaused) {_isPaused = isPaused;};
            bool getPause() {return _isPaused;};
            float getFrequency() {return _frequency;};
            void setFrequency(float frequency) {_frequency = frequency;};

        private:
            std::shared_ptr<Raylib> raylib;
            bool _isPaused = false;
            float _frequency = 2.0f;
    };
}