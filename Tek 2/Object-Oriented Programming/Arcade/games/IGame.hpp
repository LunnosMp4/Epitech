/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGame.hpp
*/

#pragma once

#include "../core/Utils.hpp"
#include "../graphicals/IGraphical.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <thread>

#define START_WIN_X X_MIDDLE - 150
#define START_WIN_Y Y_MIDDLE - 200
#define WIN_X 400
#define WIN_Y 400

enum class GameState {
    RUNNING,
    PAUSED,
    GAME_OVER,
    WIN
};

class IGame {
    public:
        IGame() = default;
        virtual ~IGame() = default;

        /**
         * @brief Initialize the game
         *
         * @param graphics The graphical library to use
         * @param playerName The player name of the current player
         */
        virtual void init(IGraphical *graphics, std::string playerName) = 0;
        /**
         * @brief Update the game each frame
         *
         */
        virtual void update() = 0;
        /**
         * @brief Handle the input of the player
         *
         * @param input The input of the player
         */
        virtual void handleInput(Input input) = 0;
        /**
         * @brief Render the game
         *
         */
        virtual void render() = 0;

        /**
         * @brief Get the Name of the game
         *
         * @return std::string The name of the game
         */
        virtual std::string getName() const = 0;
        /**
         * @brief Get the Current Score of the game
         *
         * @return unsigned int The current score of the game
         */
        virtual unsigned int getCurrentScore() const = 0;
        /**
         * @brief Get the High Score of the game
         *
         * @return unsigned int The high score of the game
         */
        virtual unsigned int getHighScore() const = 0;
        /**
         * @brief Set the State of the game
         *
         * @param state The state of the game (RUNNING, PAUSED, GAME_OVER, WIN)
         */
        virtual void setState(GameState state) = 0;
        /**
         * @brief Get the State of the game
         *
         * @return GameState The state of the game (RUNNING, PAUSED, GAME_OVER, WIN)
         */
        virtual GameState getState() const = 0;

    protected:
        GameState _state = GameState::PAUSED;
        unsigned int _currentScore;
        unsigned int _highScore;
        std::unordered_map<std::string, unsigned int> _highScores;
        std::string _playerName;
        IGraphical *_graphical;
};
