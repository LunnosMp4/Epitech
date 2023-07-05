/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Order.hpp
*/

#pragma once

#include "PizzaFactory.hpp"

namespace Plazza
{
    class Order {
        public:
            Order() {
                std::ofstream logFile("plazza.log");
            }
            ~Order() {
                std::ofstream logFile("plazza.log", std::ios::app);
                logFile << "Total pizzas: " << _nbPizzasTotal << std::endl;
                logFile.close();
            }

            std::string addPizza(std::string type, std::string size, std::string quantity);
            static void checkOrder(std::string type, std::string size, int nbPizzas);
            std::vector<std::shared_ptr<APizza>> getWaitingPizzas(void) const { return _pizzas; };
            void printTicket(void);
            [[maybe_unused]] void waitOrder(void);

        private:
            void _updateLog();

        private:
            std::vector<std::shared_ptr<APizza>> _pizzas;
            int _nbPizzasTotal = 0;
            int _idOrder = 1;
    };
}