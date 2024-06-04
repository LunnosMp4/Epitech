/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Udp
*/

#pragma once

#include "../Serialization/Serializer.hpp"
#include "../Packet.hpp"
#include "../Debug.hpp"
#include <asio.hpp>
#include <iostream>
#include <set>
#include <map>


namespace Cereal {
    namespace Network {

        class UdpServer {
        public:
            UdpServer(asio::io_context& io_context, int port);

            void startReceive();
            void handleReceive(const asio::error_code& error, std::size_t bytes_transferred);

            void sendPacketType(PacketType type, const asio::ip::udp::endpoint& endpoint);
            void sendPacket(const Packet& packet, const asio::ip::udp::endpoint& endpoint);
            void sendTransform(PacketType type, const Cereal::Transform& transform, const std::string& entityName, const int entityId);
            void broadcastData(const Packet& packet);


            void addClient(const asio::ip::udp::endpoint& endpoint);
            std::set<asio::ip::udp::endpoint> getClients();
            void removeClient(const asio::ip::udp::endpoint& endpoint);

            std::string getInputForEntity(int entityId);

            bool joinedGame = false;
            bool startedGame = false;
        private:
            void findInput(const Packet& packet);
            void handlePacket(const Packet& packet);

            std::string _input;
            std::map<int, std::string> _inputsByEntityId;
            std::set<asio::ip::udp::endpoint> _clients;
            asio::ip::udp::socket _socket;
            asio::ip::udp::endpoint _remote_endpoint;
            std::array<char, 1024> _recv_buffer;
        };

    } // namespace Network
} // namespace Cereal