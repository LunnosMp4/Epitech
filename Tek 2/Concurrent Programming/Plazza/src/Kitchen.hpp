/*
** EPITECH PROJECT, 2023
** B-CCP-400-MPL-4-1-theplazza-enzo.daumalle
** File description:
** Kitchen
*/

#pragma once

#include "Cook.hpp"
#include "pizzas/APizza.hpp"

namespace Plazza
{
    class APizza;

    class Kitchen
    {
        public:
            Kitchen();
            Kitchen(double multiplier, int cooks, int refillTime);
            ~Kitchen() = default;

            void run();
            void cookPizza(const std::string &message);
            void displayStock();
            void startCooking();
            void responseStatus();
            void createNewKitchen();
            bool checkIngredients(PizzaType type, int NbPizza);
            void removeIngredients(PizzaType type);
            void refill();

        private:
            bool isBusy() { return _currentNbPizza >= (_cooksNumber * 2); };
            std::vector<Cook> getCooks() { return _cooks; };
            std::vector<int> getStock() { return _ingredients; };
            int getCookingTime(std::string type);

        private:
            std::vector<Cook> _cooks;
            std::vector<int> _ingredients;
            std::map<int, std::unique_ptr<APizza>> _pizzas;
            int _nextPizzaId = 0;
            double _multiplier;
            int _cooksNumber;
            int _refillTime;
            int _currentNbPizza;
            mqd_t _messageQueue;
            std::mutex _mutex;

            const char* MESSAGE_QUEUE_NAME = "/pizza_queue";
            const mode_t QUEUE_PERMISSIONS = 0666;
            const int MAX_MESSAGE_SIZE = 256;
            const int MAX_MESSAGES = 10;
    };
}
