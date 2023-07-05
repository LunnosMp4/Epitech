/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Response
*/

#include "Response.hpp"
#include "Core.hpp"

Server::Response::Response(std::shared_ptr<Info::Game> receiveGame, std::shared_ptr<Zappy::Network> network, std::string teamName) : game(receiveGame), _network(network) {
    std::smatch match = ParseResponse(std::regex(R"(WELCOME\n)"));
    match = ParseResponse(std::regex(R"((\d+)\n|ko\n)"));
    game->setClientID(std::stoi(match[0]));
    if (match[0] == "ko\n") {
        std::cout << "Invalid team name or Server error" << std::endl;
        exit(84);
    }
    match = ParseResponse(std::regex(R"((\d+) (\d+)\n)"));
    game->setTeamName(teamName);
    game->setMapSize({std::stoi(match[0]), std::stoi(match[1])});
}

std::smatch Server::Response::ParseResponse(std::regex regexPattern) {
    if (!_responseInProcess)
        _response = _network->receive();
    if (_response.empty() || Listen())
        return ParseResponse(regexPattern);
    // DEBUG //
    // std::cout << "Response <" + _response << ">" << std::endl;
    std::smatch match;
    if (!(std::regex_search(_response, match, regexPattern))) {
        std::cout << "Parsing error from this server response: \"" << _response << "\"" << std::endl;
        exit(84);
    }

    return match;
}

/*  LISTEN  */
bool Server::Response::Listen() {
    if (_responseInProcess)
        return false;
    if (_response.find("message") != std::string::npos) {
        BroadcastMessage();
        return true;
    }
    if (_response.find("eject") != std::string::npos) {
        Ejected();
        return true;
    }
    if (_response.find("dead") != std::string::npos) {
        Dead();
        return true;
    }
    return false;
}

void Server::Response::BroadcastMessage() {
    _responseInProcess = true;
    std::smatch match = ParseResponse(std::regex(R"(message (\d+), ([a-zA-Z0-9]+): (.+)\n)"));
    if (game->getTeamName() == match[2])
        game->setIsConcernedByBroadcast(true);
    else
        game->setIsConcernedByBroadcast(false);
    game->setDirectionOfBroadcast(std::stoi(match[1]));
    std::string message = match[3];
    if (message.find("Incantation") != std::string::npos)
        game->setLevelRequiredForIncantation(message.c_str()[0] - '0');
    game->setBroadcastMessage(match[3]);
    std::cout << "Message received" << std::endl;
    _responseInProcess = false;
}

void Server::Response::Ejected() {
    _responseInProcess = true;
    std::smatch match = ParseResponse(std::regex(R"(eject: (\d+)\n)"));
    game->setDirectionFromEjection(std::stoi(match[1]));
    std::cout << "Ejected" << std::endl;
    _responseInProcess = false;
}

void Server::Response::Dead() {
    _responseInProcess = true;
    std::cout << "Ok" << std::endl;
    std::smatch match = ParseResponse(std::regex("dead\n"));
    game->setIsDead(true);
    std::cout << "You're dead" << std::endl;
    exit(0);
}

/*  MOVE  */
void Server::Response::Forward() {
    std::smatch match = ParseResponse(std::regex("ok\n"));
    std::cout << "Forward" << std::endl;
}

void Server::Response::Right() {
    std::smatch match = ParseResponse(std::regex("ok\n"));
    std::cout << "Right" << std::endl;
}

void Server::Response::Left() {
    std::smatch match = ParseResponse(std::regex("ok\n"));
    std::cout << "Left" << std::endl;
}

/*  INFO  */
void Server::Response::Inventory() {
    std::smatch match = ParseResponse(std::regex(R"(\[ ([a-zA-Z]+) (\d+), ([a-zA-Z]+) (\d+), ([a-zA-Z]+) (\d+), ([a-zA-Z]+) (\d+), ([a-zA-Z]+) (\d+), ([a-zA-Z]+) (\d+), ([a-zA-Z]+) (\d+) \]\n)"));
    std::map<std::string, int> inventory;

    for (size_t i = 1; i < match.size(); i += 2) {
        std::string key = match[i].str();
        int value = std::stoi(match[i + 1].str());
        inventory[key] = value;
    }
    game->setInventory(inventory);
    std::cout << "Inventory" << std::endl;
}

static std::vector<std::vector<std::string>> splitVision(std::smatch match) {
    std::vector<std::vector<std::string>> result;

    std::string trimmedInput = match[1].str();

    std::regex regexPattern(R"(\s*,\s*)"); // Expression régulière pour diviser par ","
    std::sregex_token_iterator iter(trimmedInput.begin(), trimmedInput.end(), regexPattern, -1);
    std::sregex_token_iterator end;

    while (iter != end) {
        std::string element = *iter++;
        std::vector<std::string> subVector;

        std::regex regexPattern2(R"(\s+)"); // Expression régulière pour diviser par " "
        std::sregex_token_iterator iter2(element.begin(), element.end(), regexPattern2, -1);
        std::sregex_token_iterator end2;

        while (iter2 != end2) {
            std::string subElement = *iter2++;
            subVector.push_back(subElement);
        }

        result.push_back(subVector);
    }

    return result;
}

void Server::Response::Look() {
    std::smatch match = ParseResponse(std::regex(R"(\[\s*([^\]]+)\s*\])"));
    game->setTiles(splitVision(match));
    std::cout << "Look" << std::endl;
}

void Server::Response::Broadcast() {
    std::smatch match = ParseResponse(std::regex("ok\n"));
    std::cout << "Broadcast" << std::endl;
}


/*  EXTRA  */
void Server::Response::ConnectNbr() {
    std::smatch match = ParseResponse(std::regex(R"(\d+\n)"));
    game->setConnectNbr(std::stoi(match[0]));
    std::cout << "ConnectNbr" << std::endl;
}

void Server::Response::Fork() {
    game->setIsForking(true);
    std::smatch match = ParseResponse(std::regex("ok\n"));
    // fork
    pid_t pid = fork();
    if (pid == 0) {
        std::cout << "Forking" << std::endl;
        Zappy::Core core(_network->getIp(), _network->getPort());
        core.run();
    } else if (pid < 0) {
        std::cout << "Fork failed" << std::endl;
    }
    std::cout << "Fork" << std::endl;
    game->setIsForking(false);
}

void Server::Response::Eject() {
    std::smatch match = ParseResponse(std::regex("ok\n|ko\n"));

    if (match[0] == "ko\n") {
        std::cout << "Eject failed" << std::endl;
        return;
    }
    std::cout << "Eject" << std::endl;
}

void Server::Response::Take(std::string object) {
    std::smatch match = ParseResponse(std::regex("ok\n|ko\n"));

    if (match[0] == "ko\n") {
        std::cout << "Take failed" << std::endl;
        return;
    }
    std::cout << "Take: " << object << std::endl;
}

void Server::Response::Set(std::string object) {
    std::smatch match = ParseResponse(std::regex("ok\n|ko\n"));

    if (match[0] == "ko\n") {
        std::cout << "Set failed" << std::endl;
        return;
    }
    std::cout << "Set: " << object << std::endl;
}

void Server::Response::Incantation() {
    /* Wait for the start of the incantation */
    std::smatch match = ParseResponse(std::regex("Elevation underway\n|ko\n"));
    game->setIsIncanting(true);
    std::cout << "Incantation" << std::endl;
    if (match[0] == "ko\n") {
        std::cout << "Incantation failed" << std::endl;
        return;
    }

    /* Wait for the end of the incantation */
    std::smatch matchLevel = ParseResponse(std::regex("Current level: (\\d+)\n"));
    game->setIsIncanting(false);
    std::cout << "Level up: " << matchLevel[1] << std::endl;
    game->setLevel(std::stoi(matchLevel[1]));
}
