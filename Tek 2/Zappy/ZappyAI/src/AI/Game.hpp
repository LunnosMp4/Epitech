/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Game.hpp
*/

#pragma once

#include "ZappyAI.h"


namespace Info {

    struct MapSize {
        int x;
        int y;
    };

    enum Direction {
        NONE = 0,
        FRONT = 1,
        FRONT_LEFT = 2,
        LEFT = 3,
        BACK_LEFT = 4,
        BACK = 5,
        BACK_RIGHT = 6,
        RIGHT = 7,
        FRONT_RIGHT = 8
    };

    struct Character {
        int level;
        bool isDead;
        bool isForking;
        bool isIncanting;
        std::map<std::string, int> inventory;
    };

    class Game {
        public:
            Game();
            ~Game() = default;

            /* GETTERS */
            std::string getTeamName() const { return _teamName; };
            int getClientID() const { return _clientID; };
            MapSize getMapSize() const { return _mapSize; };
            int getConnectNbr() const { return _connectNbr; };
            bool IsAlreadyFork() const { return _isAlreadyFork; };
            /* Broadcast */
            std::string getBroadcastMessage() const { return _message; };
            int getDirectionOfBroadcast() const { return _directionOfBroadcast; };
            bool IsConcernedByBroadcast() const { return _isConcernedByBroadcast; };

            int getLevelRequiredForIncantation() const { return _levelRequiredForIncantation; };
            int getDirectionFromEjection() const { return _directionFromEject; };
            std::vector<std::vector<std::string>> getTiles() const { return _tiles; };
            /* Character */
            Character getCharacter() const { return _character; };
            int getLevel() const { return _character.level; };
            bool IsDead() const { return _character.isDead; };
            bool IsForking() const { return _character.isForking; };
            bool IsIncanting() const { return _character.isIncanting; };
            std::map<std::string, int> getInventory() const { return _character.inventory; };

            /* SETTERS */
            void setTeamName(std::string teamName) { _teamName = teamName; };
            void setClientID(int clientID) { _clientID = clientID; };
            void setMapSize(MapSize mapSize) { _mapSize = mapSize; };
            void setConnectNbr(int connectNbr) { _connectNbr = connectNbr; };
            void setIsAlreadyFork(bool isAlreadyFork) { _isAlreadyFork = isAlreadyFork; };
            /* Broadcast */
            void setBroadcastMessage(std::string message) { _message = message; };
            void setDirectionOfBroadcast(int directionOfBroadcast) { _directionOfBroadcast = directionOfBroadcast; };
            void setIsConcernedByBroadcast(bool isConcernedByBroadcast) { _isConcernedByBroadcast = isConcernedByBroadcast; };

            void setLevelRequiredForIncantation(int levelRequiredForIncantation) { _levelRequiredForIncantation = levelRequiredForIncantation; };
            void setDirectionFromEjection(int directionFromEject) { _directionFromEject = directionFromEject; };
            void setTiles(std::vector<std::vector<std::string>> tiles) { _tiles = tiles; };
            /* Character */
            void setCharacter(Character character) { _character = character; };
            void setLevel(int level) { _character.level = level; };
            void setIsDead(bool isDead) { _character.isDead = isDead; };
            void setIsForking(bool isForking) { _character.isForking = isForking; };
            void setIsIncanting(bool isIncanting) { _character.isIncanting = isIncanting; };
            void setInventory(std::map<std::string, int> inventory) { _character.inventory = inventory; };

            // DEBUG //
            void PrintGameInfo() {
                std::cout << "Team name: " << _teamName << std::endl;
                std::cout << "Client ID: " << _clientID << std::endl;
                std::cout << "Map size: " << _mapSize.x << "x" << _mapSize.y << std::endl;
                std::cout << "ConnectNbr: " << _connectNbr << std::endl;
                std::cout << "Message: " << _message << std::endl;
                std::cout << "Direction of the Broadcast: " << _directionOfBroadcast << std::endl;
                std::cout << "Am I concerned by the message: " << _isConcernedByBroadcast << std::endl;
                std::cout << "Level required for incantation: " << _levelRequiredForIncantation << std::endl;
                std::cout << "Direction from ejection: ";
                if (_directionFromEject == FRONT)
                    std::cout << "FRONT" << std::endl;
                else if (_directionFromEject == FRONT_LEFT)
                    std::cout << "FRONT_LEFT" << std::endl;
                else if (_directionFromEject == LEFT)
                    std::cout << "LEFT" << std::endl;
                else if (_directionFromEject == BACK_LEFT)
                    std::cout << "BACK_LEFT" << std::endl;
                else if (_directionFromEject == BACK)
                    std::cout << "BACK" << std::endl;
                else if (_directionFromEject == BACK_RIGHT)
                    std::cout << "BACK_RIGHT" << std::endl;
                else if (_directionFromEject == RIGHT)
                    std::cout << "RIGHT" << std::endl;
                else if (_directionFromEject == FRONT_RIGHT)
                    std::cout << "FRONT_RIGHT" << std::endl;
                else
                    std::cout << "NONE" << std::endl;
                int nb = 0;
                std::cout << "Tiles: " << std::endl;
                for (const auto &row : _tiles) {
                    std::cout << "  " << nb++ << ":" << std::endl;
                    for (const auto &tile : row)
                        std::cout << "    " << tile << std::endl;
                    std::cout << std::endl;
                }
                std::cout << "Character level: " << _character.level << std::endl;
                std::cout << "Character is dead: " << _character.isDead << std::endl;
                std::cout << "Character is forking: " << _character.isForking << std::endl;
                std::cout << "Character is incanting: " << _character.isIncanting << std::endl;
                std::cout << "Character inventory: " << std::endl;
                std::cout << "    Food: " << _character.inventory["food"] << std::endl;
                std::cout << "    Linemate: " << _character.inventory["linemate"] << std::endl;
                std::cout << "    Deraumere: " << _character.inventory["deraumere"] << std::endl;
                std::cout << "    Sibur: " << _character.inventory["sibur"] << std::endl;
                std::cout << "    Mendiane: " << _character.inventory["mendiane"] << std::endl;
                std::cout << "    Phiras: " << _character.inventory["phiras"] << std::endl;
                std::cout << "    Thystame: " << _character.inventory["thystame"] << std::endl;
            }

        private:
            std::string _teamName;
            int _clientID;
            MapSize _mapSize;
            int _connectNbr;
            bool _isAlreadyFork;

            /* Broadcast */
            std::string _message;
            int _directionOfBroadcast;
            bool _isConcernedByBroadcast;

            int _levelRequiredForIncantation;
            int _directionFromEject;
            std::vector<std::vector<std::string>> _tiles;
            Character _character;
    };
}
