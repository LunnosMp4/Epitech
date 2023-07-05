/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** SFML.cpp
*/

#include "SFML.hpp"

SFML::SFML() {
    _window = new sf::RenderWindow();
    try {
        if (_window == nullptr)
            throw SFMLError("SFML window creation failed");
    } catch (const SFMLError &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    _window->clear(sf::Color::White);
}

SFML::~SFML() {
    delete _window;
}

void SFML::createWindow(unsigned int width, unsigned int height, const std::string &title) {
    _window->create(sf::VideoMode(width, height), title);
}

void SFML::destroyWindow() {
    _window->close();
}

void SFML::clear() const {
    _window->clear();
}

void SFML::refresh() const {
    _window->display();
}

void SFML::display() const {
    _window->display();
}

void SFML::drawRectangle(Vector2f position, Vector2f size, Color color) const {
    sf::RectangleShape rectangle(sf::Vector2f(size.x, size.y));

    rectangle.setPosition(position.x, position.y);
    rectangle.setFillColor(getColor(color));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(1);
    _window->draw(rectangle);
}

void SFML::drawCircle(Vector2f position, float radius, Color color) const {
    sf::CircleShape circle(radius);

    circle.setFillColor(getColor(color));
    circle.setPosition(position.x, position.y);
    circle.setRadius(radius);
    _window->draw(circle);
}

void SFML::drawText(Vector2f position, const std::string &text, unsigned int size, Color color) const {
    sf::Font font;
    sf::Text textDisplay;

    try {
        if (!font.loadFromFile("./graphicals/SUBWT___.ttf"))
            throw SFMLError("SFML: Font not found");
    } catch (const SFMLError &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    textDisplay.setFont(font);
    textDisplay.setString(text);
    textDisplay.setCharacterSize(size);
    textDisplay.setFillColor(getColor(color));
    textDisplay.setPosition(position.x, position.y);
    _window->draw(textDisplay);
}

void SFML::drawSprite(Vector2f position, const std::string &path) const {
    sf::Texture texture;
    sf::Sprite sprite;

    try {
        if (!texture.loadFromFile(path))
            throw SFMLError("SFML: Texture not found");
    } catch (const SFMLError &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    sprite.setTexture(texture);
    sprite.setPosition(position.x, position.y);
    _window->draw(sprite);
}

bool SFML::isOpen() const {
    return _window->isOpen();
}

Input SFML::getInput() {
    _input = Input::NONE;
    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            exit(0);
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Escape)
                _input = Input::ESCAPE;
            else if (_event.key.code == sf::Keyboard::Up) {
                _input = Input::UP;
            } else if (_event.key.code == sf::Keyboard::Down) {
                _input = Input::DOWN;
            } else if (_event.key.code == sf::Keyboard::Left) {
                _input = Input::LEFT;
            } else if (_event.key.code == sf::Keyboard::Right) {
                _input = Input::RIGHT;
            } else if (_event.key.code == sf::Keyboard::Return) {
                _input = Input::ENTER;
            } else if (_event.key.code == sf::Keyboard::Space) {
                _input = Input::SPACE;
            } else if (_event.key.code == sf::Keyboard::Z) {
                _input = Input::Z;
            } else if (_event.key.code == sf::Keyboard::Q) {
                _input = Input::Q;
            } else if (_event.key.code == sf::Keyboard::S) {
                _input = Input::S;
            } else if (_event.key.code == sf::Keyboard::D) {
                _input = Input::D;
            } else if (_event.key.code == sf::Keyboard::A) {
                _input = Input::A;
            } else if (_event.key.code == sf::Keyboard::E) {
                _input = Input::E;
            } else if (_event.key.code == sf::Keyboard::Backspace) {
                _input = Input::BACKSPACE;
            }
        }
    }
    return _input;
}

sf::Color SFML::getColor(Color color) const {
    if (color == Color::BLACK) return sf::Color::Black;
    if (color == Color::WHITE) return sf::Color::White;
    if (color == Color::RED) return sf::Color::Red;
    if (color == Color::GREEN) return sf::Color::Green;
    if (color == Color::BLUE) return sf::Color::Blue;
    if (color == Color::YELLOW) return sf::Color::Yellow;
    if (color == Color::MAGENTA) return sf::Color::Magenta;
    if (color == Color::CYAN) return sf::Color::Cyan;
    if (color == Color::TRANSPARENT) return sf::Color::Transparent;
    return sf::Color::Black;
}
