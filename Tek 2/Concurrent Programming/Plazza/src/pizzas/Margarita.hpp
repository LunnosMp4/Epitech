/*
** EPITECH PROJECT, 2023
** B-CCP-400-MPL-4-1-theplazza-enzo.daumalle
** File description:
** Margarita
*/

#pragma once

#include "APizza.hpp"

namespace Plazza
{
    class MargaritaPizza : public APizza {
        public:
            MargaritaPizza(PizzaSize size) {
                _type = PizzaType::Margarita;
                _size = size;
                _cookingTime = 1;
                _ingredients[Dough] = 1;
                _ingredients[Tomato] = 1;
                _ingredients[Gruyere] = 1;
            };
            ~MargaritaPizza() = default;
    };
}
