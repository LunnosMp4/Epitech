/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** commands_select2
*/

#include "server.h"

static int select_data_commands(char *user_command)
{
    if (strcmp(user_command, "Look") == 0) {
        return 4;
    } else if (strcmp(user_command, "Inventory") == 0) {
        return 5;
    } else {
        return 84;
    }
}

int select_info_commands(char *user_command)
{
    if (strcmp(user_command, "Broadcast") == 0) {
        return 6;
    } else if (strcmp(user_command, "Connect_nbr") == 0) {
        return 7;
    } else {
        return select_data_commands(user_command);
    }
}
