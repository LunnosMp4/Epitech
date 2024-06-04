/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** ServerData
*/

#include "ServerManager.hpp"

ServerManager::ServerManager()
{
    initPlayers();
}

ServerManager::~ServerManager()
{
}

void ServerManager::initPlayers() {
    std::cout << "Initializing players..." << std::endl;
    player1Transform = Cereal::Transform({0, 0, 0}, {0, 0, 0}, 0.01f);
    player2Transform = Cereal::Transform({0, 0, 0}, {0, 0, 0}, 0.01f);
    player3Transform = Cereal::Transform({0, 0, 0}, {0, 0, 0}, 0.01f);
    player4Transform = Cereal::Transform({0, 0, 0}, {0, 0, 0}, 0.01f);

    player1Stats = Cereal::Stats(100, 20, 0.2f);
    player2Stats = Cereal::Stats(100, 20, 0.2f);
    player3Stats = Cereal::Stats(100, 20, 0.2f);
    player4Stats = Cereal::Stats(100, 20, 0.2f);
}

void ServerManager::managePlayerInput(ServerManager serverManager, int player, std::string input) {
    switch (player) {
        case 1:
            if (input == "UP")
                player1Transform.position.z += player1Stats.velocity;
            else if (input == "DOWN")
                player1Transform.position.z -= player1Stats.velocity;
            else if (input == "LEFT")
                player1Transform.position.x -= player1Stats.velocity;
            else if (input == "RIGHT")
                player1Transform.position.x += player1Stats.velocity;
            break;
        case 2:
            if (input == "UP")
                player2Transform.position.z += player2Stats.velocity;
            else if (input == "DOWN")
                player2Transform.position.z -= player2Stats.velocity;
            else if (input == "LEFT")
                player2Transform.position.x -= player2Stats.velocity;
            else if (input == "RIGHT")
                player2Transform.position.x += player2Stats.velocity;
            break;
        case 3:
            if (input == "UP")
                player3Transform.position.z += player3Stats.velocity;
            else if (input == "DOWN")
                player3Transform.position.z -= player3Stats.velocity;
            else if (input == "LEFT")
                player3Transform.position.x -= player3Stats.velocity;
            else if (input == "RIGHT")
                player3Transform.position.x += player3Stats.velocity;
            break;
        case 4:
            if (input == "UP")
                player4Transform.position.z += player4Stats.velocity;
            else if (input == "DOWN")
                player4Transform.position.z -= player4Stats.velocity;
            else if (input == "LEFT")
                player4Transform.position.x -= player4Stats.velocity;
            else if (input == "RIGHT")
                player4Transform.position.x += player4Stats.velocity;
            break;
        default:
            break;
    }
}

static void sendToClient(Cereal::Network::Server& server, int clientId, PacketType type, const Cereal::Transform& transform, const std::string& playerName) {
    server.sendDataToClient(type, transform, playerName, clientId);
}

void ServerManager::sendAllClients(Cereal::Network::Server& server, ServerManager serverManager) {
    std::vector<std::thread> threads;
    PacketType type = PacketType::UPDATE_ENTITY;

    for (auto& clientId : clientIds) {
        std::string input = server.getInputFromClient(clientId);
        std::cout << "Input from client " << clientId << ": " << input << std::endl;
        managePlayerInput(serverManager, clientId, input);

        Cereal::Transform* transform;
        switch (clientId) {
            case 1: transform = &player1Transform; break;
            case 2: transform = &player2Transform; break;
            case 3: transform = &player3Transform; break;
            case 4: transform = &player4Transform; break;
            default: continue;
        }

        threads.emplace_back(sendToClient, std::ref(server), clientId, type, *transform, "Player" + std::to_string(clientId));
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        if (thread.joinable())
            thread.join();
    }
}
