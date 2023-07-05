/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** global_select
*/

#include "server.h"

int which_command(char *user_command)
{
    int return_value = select_extra_commands(user_command);

    if (return_value == 84)
        return_value = select_info_commands(user_command);

    if (return_value == 84)
        return_value = select_move_commands(user_command);

    return return_value;
}
