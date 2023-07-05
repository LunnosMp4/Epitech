/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** SDL.cpp
*/

#include "SDL.hpp"

SDL::SDL() {
    try {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
            throw SDLError("SDL_Init failed: " + std::string(SDL_GetError()));
        if (TTF_Init() != 0)
            throw SDLError("TTF_Init failed: " + std::string(TTF_GetError()));
        if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
            throw SDLError("IMG_Init failed: " + std::string(IMG_GetError()));
    } catch (const SDLError &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

SDL::~SDL() {
    SDL_Quit();
}

void SDL::createWindow(unsigned int width, unsigned int height, const std::string &title) {
    _width = width;
    _height = height;
    _title = title;
    _window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);
    if (_window == nullptr) {
        try {
            throw SDLError("SDL_CreateWindow failed: " + std::string(SDL_GetError()));
        } catch (const SDLError &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr)
        throw SDLError("SDL_CreateRenderer failed: " + std::string(SDL_GetError()));
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
}

void SDL::destroyWindow() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void SDL::clear() const {
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderClear(_renderer);
}

void SDL::refresh() const {
    SDL_RenderPresent(_renderer);
}

void SDL::display() const {
    SDL_RenderPresent(_renderer);
}

void SDL::drawRectangle(Vector2f position, Vector2f size, Color color) const {
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.x;
    rect.h = size.y;
    SDL_Color sdlColor = getColor(color);
    SDL_SetRenderDrawColor(_renderer, sdlColor.r, sdlColor.g, sdlColor.b, 255);
    SDL_RenderFillRect(_renderer, &rect);
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(_renderer, &rect);
}

void SDL::drawCircle(Vector2f position, float radius, Color color) const {
    int x = position.x + radius;
    int y = position.y + radius;
    int r = radius;
    SDL_Color sdlColor = getColor(color);
    SDL_SetRenderDrawColor(_renderer, sdlColor.r, sdlColor.g, sdlColor.b, 255);
    for (int w = r; w >= 0; --w) {
        int h = sqrt(r * r - w * w);
        SDL_RenderDrawPoint(_renderer, x + w, y + h);
        SDL_RenderDrawPoint(_renderer, x + w, y - h);
        SDL_RenderDrawPoint(_renderer, x - w, y + h);
        SDL_RenderDrawPoint(_renderer, x - w, y - h);
    }
}

void SDL::drawSprite(Vector2f position, const std::string &path) const {
    SDL_Surface *surface = IMG_Load(path.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_FreeSurface(surface);
    const SDL_Rect rect = {(int) position.x, (int) position.y, 0, 0};
    SDL_QueryTexture(texture, NULL, NULL, (int *) &rect.w, (int *) &rect.h);
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}

void SDL::drawText(Vector2f position, const std::string &text, unsigned int size, Color color) const {
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("./graphicals/SUBWT___.ttf", size);
    try {
        if (font == nullptr)
            throw SDLError("TTF_OpenFont failed: " + std::string(TTF_GetError()));
    } catch (const SDLError &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    SDL_Color sdlColor = getColor(color);
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), sdlColor);
    try {
        if (surface == nullptr)
            throw SDLError("TTF_RenderText_Solid failed: " + std::string(TTF_GetError()));
    } catch (const SDLError &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
    try {
        if (texture == nullptr)
            throw SDLError("SDL_CreateTextureFromSurface failed: " + std::string(SDL_GetError()));
    } catch (const SDLError &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect dstrect = {(int) position.x, (int) position.y, w, h };
    SDL_RenderCopy(_renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    TTF_Quit();
}

bool SDL::isOpen() const {
    if (_window == nullptr)
        return false;
    return true;
}

Input SDL::getInput()
{
    Input input = Input::NONE;
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        input = Input::ESCAPE;
                        break;
                    case SDLK_UP:
                        input = Input::UP;
                        break;
                    case SDLK_DOWN:
                        input = Input::DOWN;
                        break;
                    case SDLK_LEFT:
                        input = Input::LEFT;
                        break;
                    case SDLK_RIGHT:
                        input = Input::RIGHT;
                        break;
                    case SDLK_RETURN:
                        input = Input::ENTER;
                        break;
                    case SDLK_SPACE:
                        input = Input::SPACE;
                        break;
                    case SDLK_z:
                        input = Input::Z;
                        break;
                    case SDLK_q:
                        input = Input::Q;
                        break;
                    case SDLK_s:
                        input = Input::S;
                        break;
                    case SDLK_d:
                        input = Input::D;
                        break;
                    case SDLK_a:
                        input = Input::A;
                        break;
                    case SDLK_e:
                        input = Input::E;
                        break;
                    case SDLK_BACKSPACE:
                        input = Input::BACKSPACE;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    return input;
}

SDL_Color SDL::getColor(Color color) const {
    if (color == Color::RED) return SDL_Color{255, 0, 0, 255};
    if (color == Color::GREEN) return SDL_Color{0, 255, 0, 255};
    if (color == Color::BLUE) return SDL_Color{0, 0, 255, 255};
    if (color == Color::YELLOW) return SDL_Color{255, 255, 0, 255};
    if (color == Color::MAGENTA) return SDL_Color{255, 0, 255, 255};
    if (color == Color::CYAN) return SDL_Color{0, 255, 255, 255};
    if (color == Color::WHITE) return SDL_Color{255, 255, 255, 255};
    return SDL_Color{0, 0, 0, 255};
}
