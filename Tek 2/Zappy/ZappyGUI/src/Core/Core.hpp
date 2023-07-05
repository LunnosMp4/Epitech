/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Core.hpp
*/

#pragma once

#include "ZappyGUI.h"
#include "Raylib.hpp"
#include "Network.hpp"
#include "Game.hpp"

namespace Zappy
{
    class Core
    {
        public:
            Core(int ac, char **av);
            ~Core() = default;
            void run();

        private:
            void parseArgs(int ac, char **av);
            void printHelp() const;

            void initLauncher();
            void drawLauncher();
            void updateLauncher();

        private:
            std::shared_ptr<Raylib> raylib;
            std::string _ip;
            std::string _port;

            int _sock;
            struct sockaddr_in _server;
            std::shared_ptr<Network> _network;
            std::shared_ptr<Game> _game;

            Texture2D _background;
            Vector2 _backgroundPosition;
            bool _ipIsHovered = false;
            bool _portIsHovered = false;
            bool useLauncher = false;
            Camera2D _camera;
    };
}