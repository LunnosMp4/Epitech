/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Plazza.hpp
*/

#pragma once

#include "../include/Plazza.h"

#include "Kitchen.hpp"
#include "Order.hpp"

#include "pizzas/Fantasia.hpp"
#include "pizzas/Regina.hpp"
#include "pizzas/Americana.hpp"
#include "pizzas/Margarita.hpp"


namespace Plazza
{
    class Core
    {
        public:
            Core() = default;
            ~Core() = default;

            int run(double multiplier, int cooks, int refillTime);
            void getStatusFromKitchens();

        private:
            Order _order;
            std::vector<pid_t> _kitchens_pid;
            std::vector<mqd_t> _messageQueues;
            mqd_t _messageQueue;

            const char* MESSAGE_QUEUE_NAME = "/pizza_queue";
            const mode_t QUEUE_PERMISSIONS = 0666;
            const int MAX_MESSAGE_SIZE = 256;
            const int MAX_MESSAGES = 10;
    };
}
