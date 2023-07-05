/*
** EPITECH PROJECT, 2023
** B-CCP-400-MPL-4-1-theplazza-enzo.daumalle
** File description:
** Americana
*/

#pragma once

#include "APizza.hpp"

namespace Plazza
{
    class AmericanaPizza : public APizza
    {
        public:
            AmericanaPizza(PizzaSize size) {
                _type = PizzaType::Americana;
                _size = size;
                _cookingTime = 2;
                _ingredients[Dough] = 1;
                _ingredients[Tomato] = 1;
                _ingredients[Gruyere] = 1;
                _ingredients[Steak] = 1;
            };
    };
}
