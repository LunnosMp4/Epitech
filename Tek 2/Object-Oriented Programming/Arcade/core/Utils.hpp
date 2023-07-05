/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-loic.tisseyre [SSH: 192.168.1.41]
** File description:
** Utils.hpp
*/

#pragma once
#include <vector>
#include <string>

#define WIDTH               1152
#define HEIGHT              864
#define Y_MIDDLE HEIGHT     / 2 - 50
#define X_MIDDLE WIDTH      / 2 - 100
#define BACKGROUND_PATH     "graphicals/background.jpg"
#define TITLE               "Arcade"

struct Vector2i {
    int x;
    int y;

    Vector2i(int x, int y) : x(x), y(y) {};
    Vector2i() : x(0), y(0) {};

    bool operator==(const Vector2i &other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Vector2i &other) const {
        return (x != other.x || y != other.y);
    }
};

struct Vector2f {
    float x;
    float y;

    Vector2f(float x, float y) : x(x), y(y) {};
    Vector2f() : x(0), y(0) {};

    bool operator==(const Vector2f &other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Vector2f &other) const {
        return (x != other.x || y != other.y);
    }
};

enum Color {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    TRANSPARENT
};

enum Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE,
    ESCAPE,
    ENTER,
    Z,
    Q,
    S,
    D,
    A,
    E,
    BACKSPACE,
    NONE
};

struct LibList {
    std::vector<std::string> games = {
        "lib/arcade_snake.so",
        "lib/arcade_pacman.so",
        "lib/arcade_nibbler.so",
        "lib/arcade_qix.so",
        "lib/arcade_centipede.so",
        "lib/arcade_solarfox.so"
    };

    std::vector<std::string> graphics = {
        "lib/arcade_ncurses.so",
        "lib/arcade_sdl2.so",
        "lib/arcade_ndk++.so",
        "lib/arcade_aalib.so",
        "lib/arcade_libcaca.so",
        "lib/arcade_allegro5.so",
        "lib/arcade_xlib.so",
        "lib/arcade_gtk+.so",
        "lib/arcade_sfml.so",
        "lib/arcade_irrlicht.so",
        "lib/arcade_opengl.so",
        "lib/arcade_vulkan.so",
        "lib/arcade_qt5.so"
    };
};