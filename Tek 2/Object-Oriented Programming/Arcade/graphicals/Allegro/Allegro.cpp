/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Allegro.cpp
*/

#include "Allegro.hpp"

Allegro::Allegro() {
    try {
        if (!al_init())
            throw AllegroError("Allegro initialization failed");
        if (!al_init_ttf_addon())
            throw AllegroError("Allegro ttf addon initialization failed");
        if (!al_init_image_addon())
            throw AllegroError("Allegro image addon initialization failed");
        if (!al_init_primitives_addon())
            throw AllegroError("Allegro primitives addon initialization failed");
        if (!al_install_keyboard())
            throw AllegroError("Allegro keyboard installation failed");
        _font = al_load_ttf_font("./graphicals/SUBWT___.ttf", 20, 0);
        if (!_font)
            throw AllegroError("Allegro font loading failed");
        _event = al_create_event_queue();
        if (!_event)
            throw AllegroError("Allegro event queue creation failed");
        al_register_event_source(_event, al_get_keyboard_event_source());
    } catch (const AllegroError &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

Allegro::~Allegro() {
    al_destroy_font(_font);
    al_destroy_event_queue(_event);
}

void Allegro::createWindow(unsigned int width, unsigned int height, const std::string &title) {
    _width = width;
    _height = height;
    _title = title;
    _window = al_create_display(width, height);
    try {
        if (_window == nullptr)
            throw AllegroError("Allegro window creation failed");
    } catch (const AllegroError &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    al_clear_to_color(al_map_rgb(255, 255, 255));
}

void Allegro::destroyWindow() {
    al_destroy_display(_window);
}

void Allegro::clear() const {
    al_clear_to_color(al_map_rgb(255, 255, 255));
}

void Allegro::refresh() const {
    al_flip_display();
}

void Allegro::display() const {
    al_flip_display();
}

void Allegro::drawRectangle(Vector2f position, Vector2f size, Color color) const {
    al_draw_filled_rectangle(position.x, position.y, position.x + size.x, position.y + size.y, getColor(color));
    al_draw_rectangle(position.x, position.y, position.x + size.x, position.y + size.y, al_map_rgb(0, 0, 0), 1);
}

void Allegro::drawCircle(Vector2f position, float radius, Color color) const {
    al_draw_filled_circle(position.x, position.y, radius, getColor(color));
}

void Allegro::drawText(Vector2f position, const std::string &text, unsigned int size, Color color) const {
    (void)(size);
    al_draw_text(_font, getColor(color), position.x, position.y, 0, text.c_str());
}

void Allegro::drawSprite(Vector2f position, const std::string &path) const {
    ALLEGRO_BITMAP *sprite = al_load_bitmap(path.c_str());

    al_draw_bitmap(sprite, position.x, position.y, 0);
    al_destroy_bitmap(sprite);
}

bool Allegro::isOpen() const {
    return _window != nullptr;
}

Input Allegro::getInput() {
    ALLEGRO_EVENT event;
    while (al_get_next_event(_event, &event)) {
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    return UP;
                case ALLEGRO_KEY_DOWN:
                    return DOWN;
                case ALLEGRO_KEY_LEFT:
                    return LEFT;
                case ALLEGRO_KEY_RIGHT:
                    return RIGHT;
                case ALLEGRO_KEY_ENTER:
                    return ENTER;
                case ALLEGRO_KEY_ESCAPE:
                    return ESCAPE;
                case ALLEGRO_KEY_SPACE:
                    return SPACE;
                case ALLEGRO_KEY_BACKSPACE:
                    return BACKSPACE;
                case ALLEGRO_KEY_A:
                    return A;
                case ALLEGRO_KEY_D:
                    return D;
                case ALLEGRO_KEY_E:
                    return E;
                    return Q;
                case ALLEGRO_KEY_S:
                    return S;
                case ALLEGRO_KEY_Z:
                    return Z;
                case ALLEGRO_KEY_Q:
                    return Q;
                default:
                    return NONE;
            }
        }
    }
    return NONE;
}

ALLEGRO_COLOR Allegro::getColor(Color color) const {
    switch (color) {
        case RED:
            return al_map_rgb(255, 0, 0);
        case GREEN:
            return al_map_rgb(0, 255, 0);
        case BLUE:
            return al_map_rgb(0, 0, 255);
        case YELLOW:
            return al_map_rgb(255, 255, 0);
        case MAGENTA:
            return al_map_rgb(255, 0, 255);
        case CYAN:
            return al_map_rgb(0, 255, 255);
        case WHITE:
            return al_map_rgb(255, 255, 255);
        case BLACK:
            return al_map_rgb(0, 0, 0);
        default:
            return al_map_rgb(255, 255, 255);
    }
}