/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** nCurse.cpp
*/

#include "nCurses.hpp"

int enumToColor(Color color) {
    switch (color) {
        case Color::RED:
            return 1;
        case Color::GREEN:
            return 2;
        case Color::YELLOW:
            return 3;
        case Color::BLUE:
            return 4;
        case Color::MAGENTA:
            return 5;
        case Color::CYAN:
            return 6;
        case Color::WHITE:
            return 7;
        default:
            return 0;
    }
}

nCurses::nCurses() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

nCurses::~nCurses() {
    curs_set(1);
}

void nCurses::createWindow(unsigned int width, unsigned int height, const std::string &title) {
    _width = width;
    _height = height;
    _title = title;
    _window = newwin(height, width, 0, 0);
    try {
        if (_window == nullptr)
            throw nCursesError("newwin failed");
    } catch (const nCursesError &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    box(_window, 0, 0);
    mvwprintw(_window, 0, 1, "%s", title.c_str());
    wrefresh(_window);
}

void nCurses::destroyWindow() {
    delwin(_window);
    endwin();
}

void nCurses::clear() const {
    werase(_window);
    box(_window, 0, 0);
    mvwprintw(_window, 0, 1, "%s", _title.c_str());
}

void nCurses::refresh() const {
    wrefresh(_window);
}

void nCurses::display() const {
    wrefresh(_window);
}

void nCurses::drawRectangle(Vector2f position, Vector2f size, Color color) const {
    if (color == Color::BLACK)
        return;
    position.x /= 10;
    position.y /= 20;
    size.x /= 10;
    size.y /= 20;
    wattron(_window, COLOR_PAIR(enumToColor(color)));
    mvwprintw(_window, position.y, position.x, "/");
    for (int i = 0; i < size.x - 2; i++)
        mvwprintw(_window, position.y, position.x + i + 1, "-");
    mvwprintw(_window, position.y, position.x + size.x - 1, "\\");

    for (int i = 0; i < size.y - 2; i++) {
        mvwprintw(_window, position.y + i + 1, position.x, "|");
        for (int j = 0; j < size.x - 2; j++)
            mvwprintw(_window, position.y + i + 1, position.x + j + 1, " ");
        mvwprintw(_window, position.y + i + 1, position.x + size.x - 1, "|");
    }

    mvwprintw(_window, position.y + size.y - 1, position.x, "\\");
    for (int i = 0; i < size.x - 2; i++)
        mvwprintw(_window, position.y + size.y - 1, position.x + i + 1, "-");
    mvwprintw(_window, position.y + size.y - 1, position.x + size.x - 1, "/");

    wattroff(_window, COLOR_PAIR(enumToColor(color)));
}

void nCurses::drawCircle(Vector2f position, float radius, Color color) const {
    position.x /= 10;
    position.y /= 10;
    radius /= 10;
    wattron(_window, COLOR_PAIR(enumToColor(color)));
    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius; j++) {
            if (i * i + j * j <= radius * radius) {
                mvwprintw(_window, position.y + i, position.x + j, "a");
                mvwprintw(_window, position.y - i, position.x + j, "a");
                mvwprintw(_window, position.y + i, position.x - j, "a");
                mvwprintw(_window, position.y - i, position.x - j, "a");
            }
        }
    }
    wattroff(_window, COLOR_PAIR(enumToColor(color)));
}

void nCurses::drawText(Vector2f position, const std::string &text, unsigned int size, Color color) const {
    (void) size;

    position.x /= 10;
    position.y /= 20;
    wattron(_window, COLOR_PAIR(enumToColor(color)));
    mvwprintw(_window, position.y, position.x, "%s", text.c_str());
    wattroff(_window, COLOR_PAIR(enumToColor(color)));
}

void nCurses::drawSprite(Vector2f position, const std::string &path) const {
    (void) path;

    position.x /= 10;
    position.y /= 10;
    wattron(_window, COLOR_PAIR(7));
    mvwprintw(_window, position.y, position.x, "x");
    wattroff(_window, COLOR_PAIR(7));
}

bool nCurses::isOpen() const {
    if (_window == nullptr)
        return false;
    return true;
}

Input nCurses::getInput() {
    int ch = getch();
    switch (ch) {
        case KEY_UP:
            return Input::UP;
        case KEY_DOWN:
            return Input::DOWN;
        case KEY_LEFT:
            return Input::LEFT;
        case KEY_RIGHT:
            return Input::RIGHT;
        case 10:
            return Input::ENTER;
        case 27:
            return Input::ESCAPE;
        case 32:
            return Input::SPACE;
        case 'z':
        case 'Z':
            return Input::Z;
        case 'q':
        case 'Q':
            return Input::Q;
        case 's':
        case 'S':
            return Input::S;
        case 'd':
        case 'D':
            return Input::D;
        case 'a':
        case 'A':
            return Input::A;
        case 'e':
        case 'E':
            return Input::E;
        case KEY_BACKSPACE:
            return Input::BACKSPACE;
        default:
            return Input::NONE;
    }
}
