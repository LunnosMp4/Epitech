/*
** EPITECH PROJECT, 2023
** B-CCP-400-MPL-4-1-theplazza-enzo.daumalle
** File description:
** Plazza.h
*/

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <vector>
#include <signal.h>
#include <cstring>
#include "mqueue.h"
#include <thread>
#include <chrono>
#include <mutex>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

namespace Plazza {
    enum PizzaType
    {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum PizzaSize
    {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };
}