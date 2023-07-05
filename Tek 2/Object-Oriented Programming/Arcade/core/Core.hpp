/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Core.hpp
*/

#pragma once

#include "../games/IGame.hpp"
#include "../graphicals/IGraphical.hpp"

#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include <dirent.h>
#include <algorithm>
#include <memory>
#include <vector>
#include <dlfcn.h>
#include <map>
#include <filesystem>

namespace Arcade {

    class DLLoader {
        class DLErrorException : public std::exception {
            public:
                const char *what() const noexcept override { return dlerror(); }
        };

        public:
            DLLoader() = default;
            ~DLLoader() = default;

            void *loadLib(const std::string &path);
            void closeLib(void *handle);

            template<typename Type>
            Type *getSymbol(void *handle, const std::string &sym);

        private:
            std::map<std::string, void*> _loaded_libs;
    };
    class Core {
        public:
            Core(const std::string &libPath);
            ~Core();

            /* Lib */
            void setGameLib(const std::string &gamePath);
            void setGraphicalLib(const std::string &graphicalPath);
            void findLibs(std::vector<std::string> &games, std::vector<std::string> &graphics);
            void switchLibs(std::vector<std::string> graphics, bool Direction);

            /* Menu */
            void displayMenu(const std::string libPath);
            void drawTextMenu(std::vector<std::string> games, std::vector<std::string> graphics, bool isGame);

            /* Game */
            Input getInputs(std::vector<std::string> games, std::vector<std::string> graphics, bool &isGame);
            void gameLoop(Input input);
            void launchGame(bool isGame, std::vector<std::string> games, std::vector<std::string> graphics);

        private:
            /* Game */
            void *_handle_game = nullptr;
            IGame *_game = nullptr;

            /* Graphical */
            std::string _playerName = "Player";
            void *_handle_graphical = nullptr;
            IGraphical *_graphical = nullptr;

            DLLoader _dl;

            /* Menu / Games */
            bool _isInGame = false;
            bool _gameStarted = false;
            int _selectedGameIndex = 0;
            int _selectedGraphicsIndex = 0;
    };
}
