/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Pause.cpp
*/

#define GLSL_VERSION   330
#include "Pause.hpp"

using namespace Zappy;

Pause::Pause() {}

void Pause::update() {
    if (raylib->isKeyPressed(KEY_ESCAPE))
        _isPaused = !_isPaused;
    if (!_isPaused)
        return;
}

void Pause::draw() {
    raylib->drawRectangle(0, 0, raylib->getScreenWidth(), raylib->getScreenHeight(), Fade(BLACK, 0.2f));
    raylib->drawRectangleRounded((Rectangle) {Cast(float, raylib->getScreenWidth() / 2 - 100), Cast(float, raylib->getScreenHeight() / 2 - 100), 200, 200}, 0.05, 4, Fade(BLACK, 0.5));
    raylib->drawText("PAUSE", raylib->getScreenWidth() / 2 - 35, raylib->getScreenHeight() / 2 - 80, 20, WHITE);

    if (GuiButton((Rectangle) {Cast(float, raylib->getScreenWidth() / 2 - 80), Cast(float, raylib->getScreenHeight() / 2 - 25), 160, 40}, "Resume")) {
        _isPaused = false;
    }
    if (GuiButton((Rectangle) {Cast(float, raylib->getScreenWidth() / 2 - 80), Cast(float, raylib->getScreenHeight() / 2 + 25), 160, 40}, "Quit")) {
        exit(0);
    }
    _frequency = GuiSlider((Rectangle) {Cast(float, 70), Cast(float, 10), 160, 40}, "Frequency", TextFormat("%0.2f", _frequency), _frequency, 2.0f, 100.0f);
}