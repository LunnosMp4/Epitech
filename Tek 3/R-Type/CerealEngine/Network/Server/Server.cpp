/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Server
*/

#include "Server.hpp"

using namespace Cereal::Network;

Server::Server(int tcp_port, int udp_port)
    : _io_context(),
      _tcp_server(_io_context, tcp_port, udp_port),
      _udp_server(_io_context, udp_port) {
    // Initialization code here if needed
}

void Server::start() {
    std::cout << "Server started. TCP and UDP servers are running." << std::endl;
    _io_context.run();
}

void Server::stop() {
    _io_context.stop();
}

void Server::sendDataToClient(PacketType type, const Cereal::Transform& transform, const std::string& entityName, const int entityId) {
    _udp_server.sendTransform(type, transform, entityName, entityId);
}

std::string Server::getInputFromClient(int entityId) {
    return _udp_server.getInputForEntity(entityId);
}

std::set<asio::ip::udp::endpoint> Server::getClients() {
    return _udp_server.getClients();
}

bool Server::getGameStarted() {
    return _udp_server.startedGame;
}
