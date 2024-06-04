/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Client
*/

#pragma once

#include "../Serialization/Serializer.hpp"
#include "../Packet.hpp"
#include "../Debug.hpp"

#include <asio.hpp>
#include <iostream>

namespace Cereal {
    namespace Network {
        class Client {
            public:
                Client(asio::io_context& io_context);

                void start();
                void stop();

                void configConnection(const std::string& host, const int tcp_port);
                bool connectToServer();
                void disconnectFromServer();

                void sendInput(const std::string& input);

                Cereal::Transform getTransformComponent(PacketType type);
                int getEntityId(PacketType type);

                void sendUdpPacket(const Packet& packet);
                void sendPacketType(PacketType type);

                bool getStartedGame();

            private:

                void receiveUdpPort(const std::string& host, int udp_port);

                void receivePacket();
                void handlePacket(const Packet& packet);

                void updateEntity(const Packet& packet);

                // void send_udp_request(const std::string& host, const std::string& service);

                // void start_tcp_receive();
                // void start_udp_receive();

                // void handle_tcp_read(const asio::error_code& error, size_t bytes_transferred);
                // void handle_udp_read(const asio::error_code& error, size_t bytes_transferred);

                Packet _updatePacket;
                Cereal::Transform _transform;
                int _entityId = -1;
                bool _startedGame = false;
                asio::io_context& _io_context;
                asio::ip::tcp::socket _tcp_socket;
                asio::ip::udp::socket _udp_socket;
                asio::ip::udp::endpoint _udp_endpoint;
                std::array<char, 1024> _tcp_recv_buffer;
                std::array<char, 1024> _udp_recv_buffer;

                std::string _host;
                int _tcp_port;
                int _udp_port;

                int _id = -1;
        };
    }
}