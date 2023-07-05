/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Core.cpp
*/

#include "Core.hpp"

static void signalHandler(int signum)
{
    if (signum == SIGINT) {
        std::cout << "Pizzeria is closing..." << std::endl;
        exit(0);
    }
}

namespace Plazza
{
    int Core::run(double multiplier, int cooks, int refillTime)
    {
        std::string input;
        signal(SIGINT, signalHandler);

        struct mq_attr attr;
        attr.mq_flags = O_NONBLOCK;
        attr.mq_maxmsg = MAX_MESSAGES;
        attr.mq_msgsize = MAX_MESSAGE_SIZE;
        attr.mq_curmsgs = 0;
        // Open message queue
        _messageQueue = mq_open(MESSAGE_QUEUE_NAME, O_CREAT | O_RDWR | O_NONBLOCK, QUEUE_PERMISSIONS, &attr);
        if (_messageQueue == -1) {
            perror("mq_open");
            return 84;
        }

        std::cout << "Welcome to Pizzeria!" << std::endl;
        std::cout << "Enter the pizza order (type size quantity), 'status' to get the status of the kitchens or 'exit' to close the pizzeria." << std::endl;

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            return 84;
        } else if (pid == 0) {
            Kitchen kitchen(multiplier, cooks, refillTime);
            kitchen.run();
            return 0;
        }
        while (std::getline(std::cin, input)) {
            if (input == "exit") {
                mq_close(_messageQueue);
                mq_unlink(MESSAGE_QUEUE_NAME);
                return 0;
            }
            if (input == "status") {
                getStatusFromKitchens();
                continue;
            }
            std::regex regexPattern(R"((\w+)\s+(\w+)\s+x(\d+))");
            std::smatch match;
            std::string::const_iterator searchStart(input.cbegin());
            try {
                while (std::regex_search(searchStart, input.cend(), match, regexPattern)) {
                    std::string message = _order.addPizza(match[1], match[2], match[3]);

                    if (mq_send(_messageQueue, message.c_str(), message.size(), 0) == -1) {
                        perror("mq_send");
                        return 84;
                    }

                    searchStart = match.suffix().first;
                }
                _order.printTicket();
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }

        _order.~Order();
        mq_close(_messageQueue);
        mq_unlink(MESSAGE_QUEUE_NAME);
        wait(nullptr);

        return 0;
    }

    void Core::getStatusFromKitchens() {
        std::string message = "status";
        if (mq_send(_messageQueue, message.c_str(), message.size(), 0) == -1) {
            perror("mq_send");
            return;
        }
    }
}
