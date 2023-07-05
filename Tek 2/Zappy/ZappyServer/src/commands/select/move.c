/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** move
*/

#include "server.h"

static int select_direction_commands(char *user_command)
{
    if (strcmp(user_command, "Right") == 0) {
        return 2;
    } else if (strcmp(user_command, "Left") == 0) {
        return 3;
    } else {
        return 84;
    }
}

int select_move_commands(char *user_command)
{
    if (strcmp(user_command, "Forward") == 0) {
        return 1;
    } else {
        return select_direction_commands(user_command);
    }
}
