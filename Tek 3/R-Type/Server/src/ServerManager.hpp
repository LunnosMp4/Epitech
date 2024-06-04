/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** ServerData
*/

#include "../../CerealEngine/Network/Server/Server.hpp"
#include "../../CerealEngine/CerealEngine.hpp"
#include "Database.hpp"
#include <signal.h>
#include <map>

#pragma once

class ServerManager {
    public:
        ServerManager();
        ~ServerManager();

        void initPlayers();
        void managePlayerInput(ServerManager serverManager, int player, std::string input);
        void sendAllClients(Cereal::Network::Server& server, ServerManager serverManager);

        int ids = 1;
        std::vector<int> clientIds;
        std::vector<int> entitiesIds;
        std::string input = "";

        Cereal::Transform player1Transform;
        Cereal::Transform player2Transform;
        Cereal::Transform player3Transform;
        Cereal::Transform player4Transform;

        Cereal::Stats player1Stats;
        Cereal::Stats player2Stats;
        Cereal::Stats player3Stats;
        Cereal::Stats player4Stats;
    protected:
    private:

};
