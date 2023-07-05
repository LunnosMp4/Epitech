/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-loic.tisseyre [SSH: 192.168.1.41]
** File description:
** Allegro.hpp
*/

#include "../IGraphical.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

class AllegroError : public std::runtime_error {
    public:
        AllegroError(const std::string& message) : std::runtime_error(message) {}
};

class Allegro : public IGraphical {
    public:
        Allegro();
        ~Allegro() override;

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
        ALLEGRO_COLOR getColor(Color color) const;


    private:
        ALLEGRO_DISPLAY *_window;
        ALLEGRO_EVENT_QUEUE *_event;
        ALLEGRO_FONT *_font;
        int _width;
        int _height;
        std::string _title;
        
        Input _input;
};

extern "C" IGraphical *entryPoint()
{
    return new Allegro();
}
