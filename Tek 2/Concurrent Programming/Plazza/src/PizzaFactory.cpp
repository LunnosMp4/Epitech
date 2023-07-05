/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** PizzaFactory.hpp
*/

#include "PizzaFactory.hpp"

using namespace Plazza;

std::shared_ptr<APizza> PizzaFactory::createPizza(const std::string& type, const std::string& size) {
    std::shared_ptr<APizza> pizza = nullptr;
    PizzaSize pizzaSize;
    if (size == "S")
        pizzaSize = PizzaSize::S;
    else if (size == "M")
        pizzaSize = PizzaSize::M;
    else if (size == "L")
        pizzaSize = PizzaSize::L;
    else if (size == "XL")
        pizzaSize = PizzaSize::XL;
    else if (size == "XXL")
        pizzaSize = PizzaSize::XXL;
    else
        return nullptr;

    if (type == "regina")
        pizza = std::make_shared<ReginaPizza>(pizzaSize);
    else if (type == "margarita")
        pizza = std::make_shared<MargaritaPizza>(pizzaSize);
    else if (type == "americana")
        pizza = std::make_shared<AmericanaPizza>(pizzaSize);
    else if (type == "fantasia")
        pizza = std::make_shared<FantasiaPizza>(pizzaSize);
    return pizza;
}
