/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** commands_select1
*/

#include "server.h"

int select_extra_gui(char *user_command)
{
    if (strcmp(user_command, "msz") == 0) {
        return 13;
    } else
        return 84;
}
