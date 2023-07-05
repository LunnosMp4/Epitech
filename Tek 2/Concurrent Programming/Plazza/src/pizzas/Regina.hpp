/*
** EPITECH PROJECT, 2023
** B-CCP-400-MPL-4-1-theplazza-enzo.daumalle
** File description:
** Regina
*/

#pragma once

#include "APizza.hpp"

namespace Plazza
{
    class ReginaPizza : public APizza {
        public:
            ReginaPizza(PizzaSize size) {
                _type = PizzaType::Regina;
                _size = size;
                _cookingTime = 2;
                _ingredients[Dough] = 1;
                _ingredients[Tomato] = 1;
                _ingredients[Gruyere] = 1;
                _ingredients[Ham] = 1;
                _ingredients[Mushrooms] = 1;
            };
            ~ReginaPizza() = default;
    };
}
