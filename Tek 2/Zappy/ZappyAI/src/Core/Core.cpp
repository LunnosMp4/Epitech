/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Core
*/

#include "Core.hpp"

using namespace Zappy;

Core::Core(std::string ip, int port) {
    _ip = ip;
    _port = port;
    _orignalProcess = false;
}

Core::Core(int ac, char **av)
{
    parseArgs(ac, av);
    _orignalProcess = true;
}

void Core::printUsage(void)
{
    std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tname\tis the name of the team" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
    exit(0);
}

void Core::parseArgs(int ac, char **av)
{
    bool isTeamName = false;

    if (ac == 2 && std::string(av[1]) == "-help")
        printUsage();
    for (int i = 1; i < ac; i++) {
        if (std::string(av[i]) == "-p") {
            _port = std::stoi(av[i + 1]);
            i++;
        }
        if (std::string(av[i]) == "-n") {
            isTeamName = true;
            _name = std::string(av[i + 1]);
            i++;
        }
        if (std::string(av[i]) == "-h") {
            _ip = std::string(av[i + 1]);
            i++;
        }
    }
    if (!isTeamName) {
        std::cerr << "Invalid team name" << std::endl;
        exit(84);
    }
    if (_port <= 0 || _port > 65535) {
        std::cerr << "Invalid port number" << std::endl;
        exit(84);
    }
    if (_ip == "localhost")
        _ip = "127.0.0.1";
}

void Core::run() {
    _network = std::make_shared<Network>(_ip, _port);
    _ai = std::make_shared<AI>(_network, _name, _orignalProcess);

    _ai->run();
}
