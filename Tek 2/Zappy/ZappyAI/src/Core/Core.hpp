/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Core
*/

#pragma once

#include "ZappyAI.h"
#include "Network.hpp"
#include "AI.hpp"

namespace Zappy {
    class Core {
        public:
            Core(std::string ip, int port);
            Core(int ac, char **av);
            ~Core() = default;

            void run();

        private:
            void printUsage();
            void parseArgs(int ac, char **av);

        private:
            std::string _ip = "localhost";
            int _port = 4269;
            std::string _name;
            bool _orignalProcess;

            std::shared_ptr<Network> _network;
            std::shared_ptr<AI> _ai;
    };
}
