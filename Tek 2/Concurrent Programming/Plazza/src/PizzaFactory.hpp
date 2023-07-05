/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** PizzaFactory.hpp
*/

#pragma once

#include "Plazza.h"
#include "pizzas/APizza.hpp"
#include "pizzas/Fantasia.hpp"
#include "pizzas/Regina.hpp"
#include "pizzas/Americana.hpp"
#include "pizzas/Margarita.hpp"

namespace Plazza
{
    class PizzaFactory
    {
        public:
            static std::shared_ptr<APizza> createPizza(const std::string& type, const std::string& size);
    };
}