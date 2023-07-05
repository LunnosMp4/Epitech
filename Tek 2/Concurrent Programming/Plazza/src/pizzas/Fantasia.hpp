/*
** EPITECH PROJECT, 2023
** B-CCP-400-MPL-4-1-theplazza-enzo.daumalle
** File description:
** APizza
*/

#pragma once

#include "APizza.hpp"

namespace Plazza
{
    class FantasiaPizza : public APizza
    {
        public:
            FantasiaPizza(PizzaSize size) {
                _type = PizzaType::Fantasia;
                _size = size;
                _cookingTime = 4;
                _ingredients[Dough] = 1;
                _ingredients[Tomato] = 1;
                _ingredients[Eggplant] = 1;
                _ingredients[GoatCheese] = 1;
                _ingredients[ChiefLove] = 1;
            }
    };
}
