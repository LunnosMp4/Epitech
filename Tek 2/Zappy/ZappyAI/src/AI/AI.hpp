/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** AI
*/

#pragma once

#include "ZappyAI.h"
#include "Action.hpp"
#include "Game.hpp"

namespace Zappy
{
    class AI
    {
        struct Level {
            int levelNumber;
            int nbOfPlayers;
            std::map<std::string, int> items;
        };

        public:
            AI(std::shared_ptr<Network> network, std::string name, bool originalProcess);
            ~AI() = default;

            void run();

        public:
            std::shared_ptr<Info::Game> game;

        private:
            std::shared_ptr<Action> _action;
            bool _originalProcess;
            bool _foundBestTile;
            int _bestTile;
            int _nbOfWantedItem;

            std::vector<Level> _levels = {
                {1, 1, { {"linemate", 1}, {"deraumere", 0}, {"sibur", 0}, {"mendiane", 0}, {"phiras", 0}, {"thystame", 0} }},
                {2, 2, { {"linemate", 1}, {"deraumere", 1}, {"sibur", 1}, {"mendiane", 0}, {"phiras", 0}, {"thystame", 0} }},
                {3, 2, { {"linemate", 2}, {"deraumere", 0}, {"sibur", 1}, {"mendiane", 0}, {"phiras", 2}, {"thystame", 0} }},
                {4, 4, { {"linemate", 1}, {"deraumere", 1}, {"sibur", 2}, {"mendiane", 0}, {"phiras", 1}, {"thystame", 0} }},
                {5, 4, { {"linemate", 1}, {"deraumere", 2}, {"sibur", 1}, {"mendiane", 3}, {"phiras", 0}, {"thystame", 0} }},
                {6, 6, { {"linemate", 1}, {"deraumere", 2}, {"sibur", 3}, {"mendiane", 0}, {"phiras", 1}, {"thystame", 0} }},
                {7, 6, { {"linemate", 2}, {"deraumere", 2}, {"sibur", 2}, {"mendiane", 2}, {"phiras", 2}, {"thystame", 1} }},
            };

        private:
            void UpdateLocalInventory(std::map<std::string, int> inventory, std::string item, std::string action);
            void MoveCharacter(int i, int destinationTile, int nb_left, int nb_right, int y);
            void SearchForItems(std::vector<std::vector<std::string>> tiles, std::string item);
            void SearchForPlayers(std::vector<std::vector<std::string>> tiles);
            void CreatePath(std::vector<std::vector<std::string>> tiles, std::string item);

            void UseDirection(int direction);
            int CheckEnoughItems(std::map<std::string, int> inventoryMap, std::vector<std::vector<std::string>> tiles, Level level);
            void CheckItemsOnTile(std::map<std::string, int> inventoryMap, std::vector<std::vector<std::string>> tiles);

            int FoodChecker(std::map<std::string, int> inventoryMap);
            int CheckForFork();
            int CheckFromReceivedBroadcast();
            int CheckOwnElevation(std::map<std::string, int> inventoryMap, std::vector<std::vector<std::string>> tiles);

            void PriorityDistributor(int countdownInvUpdate);
    };
}
