/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** error
*/

#include "server.h"

void sig_handler(int signo)
{
    if (signo == SIGINT)
        exit(0);
}
