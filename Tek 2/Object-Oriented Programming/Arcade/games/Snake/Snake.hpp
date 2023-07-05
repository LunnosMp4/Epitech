/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Snake.cpp
*/

#pragma once

#include "../IGame.hpp"

#define SNAKE_HIGHSCORES_FILE "Snake.txt"

class Snake : public IGame {
    public:
        ~Snake() override {}

        void init(IGraphical *graphics, std::string playerName) override;
        void update() override ;
        void handleInput(Input input) override;
        void render() override;

        std::string getName() const override { return "Snake"; }
        unsigned int getCurrentScore() const override { return _currentScore; }
        unsigned int getHighScore() const override { return _highScore; }
        void setState(GameState state) override { _state = state; }
        GameState getState() const override { return _state; }

    private:
        const int Size = 20;
        const int width = Size * Size;
        const int height = Size * Size;
        int num = 4;
        int dir = 1;
        bool _firstStart = true;

        struct SnakeSegment {
            int x, y;
        } s[100];

        struct Fruit {
            int x, y;
        } f;

        unsigned int _currentScore = 0;
        unsigned int _highScore = 0;
        std::unordered_map<std::string, unsigned int> _highScores;
        std::string _playerName;
        GameState _state = GameState::PAUSED;

        IGraphical *_graphics;

        void start();
        void generateFruit();
        void updateSnake();
        bool checkCollision();
        void loadHighScores();
        void saveHighScores();
        void updateHighScore();
        void delay(int milliseconds);
};

extern "C" IGame *entryPoint()
{
    return new Snake();
}