/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Game.hpp
*/

#include "Game.hpp"

using namespace Info;

Game::Game() {
    _teamName = "";
    _clientID = 0;
    _mapSize = {0, 0};
    _connectNbr = 0;
    _isAlreadyFork = false;
    _message = "";
    _directionOfBroadcast = 0;
    _isConcernedByBroadcast = false;
    _levelRequiredForIncantation = 0;
    _directionFromEject = Direction::NONE;
    _tiles = {};
    _character = {1, false, false, false, {}};
}
