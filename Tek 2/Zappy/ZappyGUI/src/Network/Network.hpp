/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Network.hpp
*/

#pragma once

#include "ZappyGUI.h"

namespace Zappy
{
    class Network
    {
        public:
            Network(std::string _ip, int _port);
            ~Network();
            void connectToServer();

            void send(std::string message);
            std::string receive();
            std::string receiveLoop();
            std::string getIp() const { return _ip; };
            int getPort() const { return _port; };

        private:
            std::string _ip;
            int _port;
            int _sock;
            struct sockaddr_in _server;
    };
}