/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** commands_select1
*/

#include "server.h"

static int select_eject_command(char *user_command)
{
    if (strcmp(user_command, "Eject") == 0) {
        return 9;
    } else {
        return select_extra_gui(user_command);
    }
}

static int select_object_commands(char *user_command)
{
    if (strcmp(user_command, "Set") == 0) {
        return 11;
    } else if (strcmp(user_command, "Take") == 0) {
        return 10;
    } else
        return select_eject_command(user_command);
}

int select_extra_commands(char *user_command)
{
    if (strcmp(user_command, "Incantation") == 0) {
        return 12;
    } else if (strcmp(user_command, "Fork") == 0) {
        return 8;
    } else
        return select_object_commands(user_command);
    return 84;
}
