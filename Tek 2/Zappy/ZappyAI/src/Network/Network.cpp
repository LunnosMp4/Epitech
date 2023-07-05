/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Network.cpp
*/

#include "Network.hpp"

using namespace Zappy;

Network::Network(std::string ip, int port) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip.c_str(), &(sa.sin_addr));
    if (result == 0) {
        std::cerr << "Error: invalid IP address" << std::endl;
        exit(84);
    } else if (result < 0) {
        std::cerr << "Error: inet_pton failed" << std::endl;
        exit(84);
    }

    _ip = ip;
    _port = port;
    connectToServer();
}

Network::~Network() {
    close(_sock);
}

void Network::connectToServer() {
    _sock = socket(AF_INET, SOCK_STREAM, 0);
    if (_sock == -1) {
        std::cerr << "Could not create socket" << std::endl;
        exit(84);
    }

    _server.sin_addr.s_addr = inet_addr(_ip.c_str());
    _server.sin_family = AF_INET;
    _server.sin_port = htons(_port);

    if (connect(_sock, (struct sockaddr *)&_server, sizeof(_server)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        exit(84);
    }

    std::cout << "Connected to " << _ip << ":" << _port << std::endl;
}

std::string Network::receive() {
    char buffer[1024] = {0};
    std::string message;

    int flags = fcntl(_sock, F_GETFL, 0);
    fcntl(_sock, F_SETFL, flags);

    int bytesRead = 0;

    while (true) {
        bytesRead = read(_sock, buffer, 1);
        if (bytesRead < 0 && errno != EWOULDBLOCK) {
            std::cerr << "Error: read failed" << std::endl;
            exit(84);
        }

        if (bytesRead == 0)
            break;

        message += buffer[0];

        if (buffer[0] == '\n')
            break;
    }

    fcntl(_sock, F_SETFL, flags);

    return message;
}

void Network::send(std::string message) {
    std::stringstream ss;
    ss << message;

    if (write(_sock, ss.str().c_str(), ss.str().length()) < 0) {
        std::cerr << "Error: write failed" << std::endl;
        exit(84);
    }
}

std::string Network::receiveLoop() {
    std::string message = "";
    std::string tmp = "";

    while (true) {
        tmp = receive();
        if (tmp == "")
            break;
        message += tmp;
    }
    return message;
}
