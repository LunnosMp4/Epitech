/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-loic.tisseyre [SSH: 192.168.1.41]
** File description:
** nCurses.hpp
*/

#pragma	once

#include "../IGraphical.hpp"
#include <ncurses.h>

class nCursesError : public std::runtime_error {
    public:
        nCursesError(const std::string& message) : std::runtime_error(message) {}
};

class nCurses : public IGraphical {
    public:
        nCurses();
        ~nCurses() override;

        void createWindow(unsigned int width, unsigned int height, const std::string &title) override;
        void destroyWindow() override;
        void clear() const override;
        void refresh() const override;
        void display() const override;

        void drawRectangle(Vector2f position, Vector2f size, Color color) const override;
        void drawCircle(Vector2f position, float radius, Color color) const override;
        void drawText(Vector2f position, const std::string &text, unsigned int size, Color color) const override;
        void drawSprite(Vector2f position, const std::string &path) const override;

        bool isOpen() const override;
        Input getInput() override;

    private:
        WINDOW *_window;
        unsigned int _width;
        unsigned int _height;
        std::string _title;
};

extern "C" IGraphical *entryPoint()
{
    return new nCurses();
}
