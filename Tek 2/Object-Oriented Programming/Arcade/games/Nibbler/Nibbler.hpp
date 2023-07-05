/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Nibbler.cpp
*/

#pragma once

#include "../IGame.hpp"

#define MAP_1                     "./games/Nibbler/maps/map_1.txt"
#define MAP_2                     "./games/Nibbler/maps/map_2.txt"
#define MAP_3                     "./games/Nibbler/maps/map_3.txt"
#define NIBBLER_HIGHSCORES_FILE   "Nibbler.txt"
#define WALL                      '1'
#define EMPTY                     '0'

class Nibbler : public IGame {
    public:
        ~Nibbler() override {}

        void init(IGraphical *graphics, std::string playerName) override;
        void update() override ;
        void handleInput(Input input) override;
        void render() override;

        std::string getName() const override { return "Nibbler"; }
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
        std::vector<std::vector<char>> map;
        int _nbFruit = 5;
        unsigned int _level = 0;

        struct NibblerSegment {
            int x, y;
        } s[100];

        struct Fruit {
            int x, y;
        } f[5];

        unsigned int _currentScore = 0;
        unsigned int _highScore = 0;
        std::unordered_map<std::string, unsigned int> _highScores;
        std::string _playerName;
        GameState _state = GameState::PAUSED;

        IGraphical *_graphics;

        void start();
        void generateFruit();
        void updateNibbler();
        bool checkCollision();
        void loadHighScores();
        void saveHighScores();
        void updateHighScore();
        void displayHighScores();
        void print_map_and_fruit();
        void changeMap();
        void respawnSnake();
        void delay(int milliseconds);
        std::vector<std::vector<char>> readMapNibbler(std::string fileName);
};

extern "C" IGame *entryPoint()
{
    return new Nibbler();
}