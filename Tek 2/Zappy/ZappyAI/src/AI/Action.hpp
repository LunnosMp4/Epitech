/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Action
*/

#pragma once

#include "ZappyAI.h"
#include "Network.hpp"
#include "Response.hpp"
#include "Game.hpp"

namespace Zappy {

    class Action {
        public:
            Action(std::shared_ptr<Info::Game> game, std::shared_ptr<Network> network, std::string teamName);
            ~Action() = default;
            void Listen();

            /*  MOVE  */
            void Forward();
            void Right();
            void Left();

            /*  INFO  */
            void Look();
            void Inventory();
            void Broadcast(std::string message);

            /* EXTRA */
            void ConnectNbr();
            void Fork();
            void Eject();
            void Take(std::string object);
            void Set(std::string object);
            void Incantation();

        private:
            std::shared_ptr<Network> _network;
            std::shared_ptr<Server::Response> _response;
    };
}
