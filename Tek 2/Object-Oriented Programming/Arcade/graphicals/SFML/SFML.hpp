/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-loic.tisseyre [SSH: 192.168.1.41]
** File description:
** SFML.hpp
*/

#include "../IGraphical.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class SFMLError : public std::runtime_error {
    public:
        SFMLError(const std::string& message) : std::runtime_error(message) {}
};

class SFML : public IGraphical {
    public:
        SFML();
        ~SFML() override;

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
        sf::Color getColor(Color color) const;

    private:
        sf::RenderWindow *_window;
        sf::Event _event;
        Input _input;
};

extern "C" IGraphical *entryPoint()
{
    return new SFML();
}
