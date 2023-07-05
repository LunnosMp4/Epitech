/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** AI
*/

#include "AI.hpp"

using namespace Zappy;

AI::AI(std::shared_ptr<Network> network, std::string teamName, bool originalProcess)
{
    game = std::make_shared<Info::Game>();
    _action = std::make_shared<Action>(game, network, teamName);
    _originalProcess = originalProcess;
}

void AI::UpdateLocalInventory(std::map<std::string, int> inventory, std::string item, std::string action)
{
    for (auto &pair : inventory) {
        if (pair.first == item) {
            if (action == "take")
                pair.second++;
            if (action == "set")
                pair.second--;
        }
    }
    game->setInventory(inventory);
}

void AI::MoveCharacter(int i, int destinationTile, int nb_left, int nb_right, int y)
{
    if (i == destinationTile || i - nb_left == destinationTile || i + nb_right == destinationTile) {
        for (int j = 0; j < y; j++)
            _action->Forward();
        if (nb_left > 0) {
            _action->Left();
            for (int j = 0; j < nb_left; j++)
                _action->Forward();
        }
        if (nb_right > 0) {
            _action->Right();
            for (int j = 0; j < nb_right; j++)
                _action->Forward();
        }
    }
}

void AI::SearchForItems(std::vector<std::vector<std::string>> tiles, std::string item)
{
    int NewNbOfItem = 0;

    _foundBestTile = false;
    _nbOfWantedItem = 0;
    _bestTile = 0;

    for (int i = 0; i < (int)tiles.size(); i++) {
        NewNbOfItem = 0;
        for (int j = 0; j < (int)tiles[i].size(); j++)
            if (tiles[i][j] == item)
                NewNbOfItem++;
        if (NewNbOfItem > _nbOfWantedItem) {
            _foundBestTile = true;
            _nbOfWantedItem = NewNbOfItem;
            _bestTile = i;
        }
    }
}

void AI::SearchForPlayers(std::vector<std::vector<std::string>> tiles)
{
    _foundBestTile = false;
    _nbOfWantedItem = 0;
    _bestTile = 0;

    for (int i = 1; i < (int)tiles.size(); i++) {
        for (int j = 0; j < (int)tiles[i].size(); j++)
            if (tiles[i][j] == "player") {
                _foundBestTile = true;
                _bestTile = i;
            }
    }
}

void AI::CreatePath(std::vector<std::vector<std::string>> tiles, std::string item)
{
    int nb_left = 0;
    int nb_right = 0;
    int y = 1;
    int rowCounter = 4;

    if (item == "player")
        SearchForPlayers(tiles);
    else
        SearchForItems(tiles, item);
    if (!_foundBestTile) {
        _bestTile = rand() % (int)tiles.size();
        std::cout << "No " << item << " found, moving to random tile " << _bestTile << std::endl;
    } else
        std::cout << "Found " << _nbOfWantedItem << " " << item << " on tile " << _bestTile << std::endl;

    if (_bestTile != 0) {
        for (int i = 2; i < (int)tiles.size();) {
            for (int j = 1; j <= y; j++) {
                if (i - j == _bestTile) {
                    nb_left = j;
                    break;
                }
                if (i + j == _bestTile) {
                    nb_right = j;
                    break;
                }
            }
            MoveCharacter(i, _bestTile, nb_left, nb_right, y);
            i += rowCounter;
            rowCounter += 2;
            y++;
        }
    }
    for (int i = 0; i < _nbOfWantedItem; i++) {
        _action->Take(item);
        UpdateLocalInventory(game->getInventory(), item, "take");
    }
}


void AI::UseDirection(int direction)
{
    std::vector<std::vector<std::string>> tiles = game->getTiles();
    std::string message = game->getBroadcastMessage();
    direction = game->getDirectionOfBroadcast();
    int nbOfPlayers = 0;

    for (int i = 0; i < (int)tiles[0].size(); i++)
        if (tiles[0][i] == "player")
            nbOfPlayers++;
    if (nbOfPlayers > 1) {
        while (1) {
            message = game->getBroadcastMessage();
            if (message.find("Started") != std::string::npos) {
                _action->Incantation();
                break;
            }
        }
        return;
    }

    switch (direction) {
        case Info::Direction::NONE:
            break;
        case Info::Direction::FRONT:
            _action->Forward();
            break;
        case Info::Direction::FRONT_LEFT:
            _action->Forward();
            _action->Left();
            _action->Forward();
            break;
        case Info::Direction::LEFT:
            _action->Left();
            _action->Forward();
            break;
        case Info::Direction::BACK_LEFT:
            _action->Left();
            _action->Forward();
            _action->Left();
            _action->Forward();
            break;
        case Info::Direction::BACK:
            _action->Left();
            _action->Left();
            _action->Forward();
            break;
        case Info::Direction::BACK_RIGHT:
            _action->Right();
            _action->Forward();
            _action->Right();
            _action->Forward();
            break;
        case Info::Direction::RIGHT:
            _action->Right();
            _action->Forward();
            break;
        case Info::Direction::FRONT_RIGHT:
            _action->Forward();
            _action->Right();
            _action->Forward();
            break;
        default:
            break;
    }
    std::cout << "Direction: " << direction << std::endl;
}

int AI::CheckEnoughItems(std::map<std::string, int> inventoryMap, std::vector<std::vector<std::string>> tiles, Level level)
{
    int nbOfItem = 0;

    for (const auto &item : level.items) {
        nbOfItem = 0;
        for (int i = 0; i < (int)tiles[0].size(); i++)
            if (tiles[0][i] == item.first)
                nbOfItem++;
        if ((nbOfItem < item.second) && (inventoryMap[item.first] < item.second)) {
            CreatePath(tiles, item.first);
            return 1;
        }
    }
    for (const auto &item : level.items) {
        nbOfItem = 0;
        if (inventoryMap[item.first] > 0 && item.second > 0) {
            _action->Set(item.first);
            UpdateLocalInventory(game->getInventory(), item.first, "set");
        }
        for (int i = 0; i < (int)tiles[0].size(); i++)
            if (tiles[0][i] == item.first)
                nbOfItem++;
        if ((nbOfItem < item.second) && (inventoryMap[item.first] < item.second)) {
            CreatePath(tiles, item.first);
            return 1;
        }
        // if there is one item not int the required items, take it
        for (int i = 0; i < (int)tiles[0].size(); i++) {
            if (tiles[0][i] == item.first) {
                if (item.second == 0) {
                    _action->Take(item.first);
                    UpdateLocalInventory(game->getInventory(), item.first, "take");
                }
            }
        }
    }
    return 0;
}

int AI::FoodChecker(std::map<std::string, int> inventoryMap)
{
    for (const auto &item : inventoryMap) {
        if (item.first == "food" && item.second < 9) {
            CreatePath(game->getTiles(), "food");
            return 1;
        }
    }
    return 0;
}

int AI::CheckForFork()
{
    if (game->getLevel() == 1 && _originalProcess) {
        _action->Fork();
        _originalProcess = false;
        return 1;
    }
    if (game->getLevel() == 3 && !game->IsAlreadyFork()) {
        _action->Fork();
        game->setIsAlreadyFork(true);
        return 1;
    }
    return 0;
}

int AI::CheckFromReceivedBroadcast()
{
    bool isFriendly = game->IsConcernedByBroadcast();
    int lvlRequired = game->getLevelRequiredForIncantation();
    std::string message = game->getBroadcastMessage();
    int direction = game->getDirectionOfBroadcast();
    std::vector<std::vector<std::string>> tiles = game->getTiles();
    int nbOfPlayers = 0;

    if (direction == Info::Direction::NONE)
        return 0;

    if (isFriendly && lvlRequired == game->getLevel() && lvlRequired != 1) {
        while (!(message.find("Starting") != std::string::npos)) {
            nbOfPlayers = 0;
            _action->Look();
            tiles = game->getTiles();
            if (message.find("Incantation") != std::string::npos) {
                for (int i = 0; i < (int)tiles[0].size(); i++)
                    if (tiles[0][i] == "player")
                        nbOfPlayers++;
                if (nbOfPlayers > 1 && direction == Info::Direction::NONE) {
                    _action->Incantation();
                    return 0;
                }
                if (direction == Info::Direction::NONE) {
                    return 0;
                }
                UseDirection(direction);
                if (game->getLevel() == lvlRequired +1)
                    return 1;
                std::cout << "Coming for help" << std::endl;
                continue;
            }
            return 1;
        }
    } else if (!isFriendly && lvlRequired == game->getLevel()){
        if (rand() % 5 != 0) {
            std::cout << "Ignored enemy broadcast" << std::endl;
            return 0;
        }
        while (!(message.find("Finished") != std::string::npos)) {
            nbOfPlayers = 0;
            _action->Look();
            tiles = game->getTiles();
            if (message.find("Starting") != std::string::npos) {
                direction = game->getDirectionOfBroadcast();
                if (direction == Info::Direction::NONE) {
                    _action->Eject();
                    return 0;
                }
                for (int i = 0; i < (int)tiles[0].size(); i++)
                    if (tiles[0][i] == "player")
                        nbOfPlayers++;
                if (nbOfPlayers > 1 && direction == Info::Direction::NONE) {
                    _action->Eject();
                    return 0;
                }
                UseDirection(direction);
                std::cout << "tracking enemy" << std::endl;
                continue;
            }
            return 1;
        }
    }
    return 0;
}

void AI::CheckItemsOnTile(std::map<std::string, int> inventoryMap, std::vector<std::vector<std::string>> tiles)
{
    std::map<std::string, int> itemsOnTile;
    int characterLevel = game->getLevel();

    for (const auto &item : inventoryMap)
        if (item.first != "food")
            itemsOnTile[item.first] = 0;

    for (int i = 0; i < (int)tiles[0].size(); i++) {
        for (const auto &item : itemsOnTile) {
            if (tiles[0][i] == item.first)
                itemsOnTile[item.first]++;
        }
    }

    for (const auto &level : _levels) {
        if (characterLevel == level.levelNumber) {
            for (const auto &item : level.items) {
                while (itemsOnTile[item.first] > item.second) {
                    _action->Take(item.first);
                    itemsOnTile[item.first]--;
                    UpdateLocalInventory(game->getInventory(), item.first, "take");
                }
                while (itemsOnTile[item.first] < item.second && inventoryMap[item.first] > 0) {
                    _action->Set(item.first);
                    itemsOnTile[item.first]++;
                    UpdateLocalInventory(game->getInventory(), item.first, "set");
                }
            }
        }
    }
}

int AI::CheckOwnElevation(std::map<std::string, int> inventoryMap, std::vector<std::vector<std::string>> tiles)
{
    int characterLevel = game->getLevel();
    std::string message = game->getBroadcastMessage();
    int countNbOfPlayers = 0;

    for (const auto &level : _levels) {
        if (characterLevel == level.levelNumber) {
            countNbOfPlayers = 0;
            if (CheckEnoughItems(inventoryMap, tiles, level) == 1)
                return 1;
            for (int i = 0; i < (int)tiles[0].size(); i++)
                if (tiles[0][i] == "player")
                    countNbOfPlayers++;
            if (countNbOfPlayers < level.nbOfPlayers) {
                std::cout << "Broadcasting for Players" << std::endl;
                _action->Broadcast(game->getTeamName() + ": " + std::to_string(characterLevel) + ": (Required player lvl for Incantation)");
                return 1;
            }
            break;
        }
    }
    _action->Look();
    if (message.find("Incantation") != std::string::npos) {
        game->setBroadcastMessage("");
        return 1;
    }
    CheckItemsOnTile(inventoryMap, game->getTiles());
    _action->Broadcast(game->getTeamName() + ": " + std::to_string(characterLevel) + ": Starting Incantation");
    _action->Incantation();
    _action->Broadcast(game->getTeamName() + ": " + std::to_string(characterLevel) + ": Finished Incantation");
    return 0;
}

void AI::PriorityDistributor(int countdownInvUpdate)
{
    if (countdownInvUpdate > 3) {
        _action->Inventory();
        countdownInvUpdate = 0;
    }
    countdownInvUpdate++;

    _action->Inventory();

    if (FoodChecker(game->getInventory()) == 1)
        return;
    if (CheckForFork() == 1)
        return;
    if (CheckFromReceivedBroadcast() == 1)
        return;
    if (CheckOwnElevation(game->getInventory(), game->getTiles()) == 1)
        return;
}

void AI::run()
{
    int countdownInvUpdate = 0;
    /* Logique du bot */
    _action->Inventory();       // NEEDED FOR WORKING

    while (1) {
        if (game->IsDead())
            break;
        if (game->IsIncanting())
            continue;

        _action->Look();

        PriorityDistributor(countdownInvUpdate);
    }
}
