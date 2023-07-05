/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Response
*/

#pragma once

#include "ZappyAI.h"
#include "Network.hpp"
#include "Game.hpp"

namespace Server {

    class Response {
        public:
            Response(std::shared_ptr<Info::Game> receiveGame, std::shared_ptr<Zappy::Network> network, std::string teamName);
            ~Response() = default;


            std::smatch ParseResponse(std::regex regex);

            /*  LISTEN  */
            bool Listen();
            void BroadcastMessage();
            void Ejected();
            void Dead();


            /*  MOVE  */
            void Forward();
            void Right();
            void Left();

            /*  INFO  */
            void Look();
            void Inventory();
            void Broadcast();

            /* EXTRA */
            void ConnectNbr();
            void Fork();
            void Eject();
            void Take(std::string object);
            void Set(std::string object);
            void Incantation();

        public:
            std::shared_ptr<Info::Game> game;

        private:
            std::shared_ptr<Zappy::Network> _network;
            std::string _response;
            bool _responseInProcess;
    };
}
