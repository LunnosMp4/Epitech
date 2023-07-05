/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Main.cpp
*/

#include "Core.hpp"

using namespace Plazza;

int main(int ac, char **av)
{
    Core plazza;

    if (ac != 4) {
        std::cerr << "Usage: ./plazza [multiplier] [cooks] [time]" << std::endl;
        return 84;
    }

    double multiplier = std::stod(av[1]);
    int cooks = std::stoi(av[2]);
    int refillTime = std::stoi(av[3]);

    if (multiplier <= 0 || cooks <= 0 || refillTime <= 0) {
        std::cerr << "Error: multiplier, cooks and time must be greater than 0" << std::endl;
        return 84;
    }
    return plazza.run(multiplier, cooks, refillTime);
}