/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Main.cpp
*/

#include "Core.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./arcade [libGraphical]" << std::endl;
        return 84;
    }
    Arcade::Core core(av[1]);
    return 0;
}
