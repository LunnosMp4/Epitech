/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Order.cpp
*/

#include "Order.hpp"

using namespace Plazza;

void Order::checkOrder(std::string type, std::string size, int nbPizzas) {
    if (type != "regina" && type != "margarita" && type != "americana" && type != "fantasia")
        throw std::invalid_argument("Invalid pizza type");
    if (size != "S" && size != "M" && size != "L" && size != "XL" && size != "XXL")
        throw std::invalid_argument("Invalid pizza size");
    if (nbPizzas < 1)
        throw std::invalid_argument("Invalid pizza quantity");
}

void Order::_updateLog() {
    std::ofstream logFile("plazza.log", std::ios::app);

    time_t now = time(0);
    tm *ltm = localtime(&now);

    for (auto &pizza : _pizzas) {
        logFile << "Order n°" << _idOrder << " - Type: " << pizza->getTypeString() << ", Size: " << pizza->getSize() << ", Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << std::endl;
    }
}

void Order::printTicket()
{
    _updateLog();
    std::cout << "|---------------------------------------" << std::endl;
    std::cout << "|          RESTAURANT TICKET            " << std::endl;
    std::cout << "|---------------------------------------" << std::endl;
    std::cout << "| Order n°" << _idOrder << std::endl;
    std::cout << "|---------------------------------------" << std::endl;
    std::cout << "| Pizzas: " << std::endl;
    for (auto it = _pizzas.begin(); it != _pizzas.end();) {
        std::string pizzaName = (*it)->getTypeString();
        pizzaName[0] = std::toupper(pizzaName[0]);

        std::cout << "|  " << pizzaName << " " << (*it)->getSizeString() << std::endl;

        it = _pizzas.erase(it);
    }
    std::cout << "|---------------------------------------" << std::endl;
    std::cout << std::endl;

    _idOrder++;
}

std::string Order::addPizza(std::string type, std::string size, std::string quantity) {
    int nbPizzas = std::stoi(quantity);
    checkOrder(type, size, nbPizzas);

    std::shared_ptr<APizza> pizza = PizzaFactory::createPizza(type, size);
    if (pizza) {
        for (int i = 0; i < nbPizzas; i++) {
            _pizzas.push_back(pizza);
        }
        _nbPizzasTotal += nbPizzas;
    }

    return type + " " + size + " " + quantity;
}

[[maybe_unused]] void Order::waitOrder(void) {
    for (int i = 0; i < _nbPizzasTotal; i++) {
        while (!_pizzas[i]->getIsCooked());
    }
}
