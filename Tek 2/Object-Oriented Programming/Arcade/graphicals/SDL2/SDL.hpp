/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-loic.tisseyre [SSH: 192.168.1.41]
** File description:
** SDL.hpp
*/

#include "../IGraphical.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class SDLError : public std::runtime_error {
    public:
        SDLError(const std::string& message) : std::runtime_error(message) {}
};

class SDL : public IGraphical {
    public:
        SDL();
        ~SDL() override;

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
        SDL_Color getColor(Color color) const;

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        unsigned int _width;
        unsigned int _height;
        std::string _title;
};

extern "C" IGraphical *entryPoint()
{
    return new SDL();
}
