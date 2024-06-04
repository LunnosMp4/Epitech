/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Server header
*/

#pragma once

#include "TcpServer.hpp"
#include "UdpServer.hpp"

namespace Cereal {
    namespace Network {
        class Server {
            public:
                Server(int tcp_port, int udp_port);

                void start();
                void stop();

                void sendDataToClient(PacketType type, const Cereal::Transform& transform, const std::string& entityName, const int entityId);

                std::string getInputFromClient(int entityId);
                std::set<asio::ip::udp::endpoint> getClients();
                bool getGameStarted();

                // auto transform = e.getComponent<Cereal::Transform>();
                // auto stats = e.getComponent<Cereal::Stats>();
                // void updateEntity(Entity entity);
                // void deleteEntity(int entityId);
                // void sendGameData(void);

            private:
                asio::io_context _io_context;
                TcpServer _tcp_server;
                UdpServer _udp_server;
        };
    }
}
