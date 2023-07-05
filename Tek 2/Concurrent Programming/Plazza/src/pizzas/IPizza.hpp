/*
** EPITECH PROJECT, 2023
** B-CCP-400-MPL-4-1-theplazza-enzo.daumalle
** File description:
** APizza
*/

#pragma once

#include "../Kitchen.hpp"

namespace Plazza
{
    enum Ingredient
    {
        ChiefLove   = 0,
        Dough       = 1,
        Eggplant    = 2,
        GoatCheese  = 3,
        Gruyere     = 4,
        Ham         = 5,
        Mushrooms   = 6,
        Steak       = 7,
        Tomato      = 8
    };

    class IPizza
    {
        public:
            virtual ~IPizza() = default;

            virtual PizzaType getType() const = 0;
            virtual PizzaSize getSize() const = 0;
            virtual double getCookingMultiplier() const = 0;
            virtual std::map<Ingredient, int> getIngredients() const = 0;
            virtual bool getIsCooked() const = 0;
    };
}
