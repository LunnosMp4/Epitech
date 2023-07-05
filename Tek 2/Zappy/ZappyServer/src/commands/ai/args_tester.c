/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** args_tester
*/

#include "server.h"

static bool command_args_good_extra2(char *command, char **args)
{
    int code = which_command(command);

    switch (code) {
    case 9:
        if (!args[0])
            return true;
        break;
    case 10:
        if (args[0] && !args[1])
            return is_item(args[0]);
        break;
    }
    return false;
}

bool command_args_good_extra(char *command, char **args)
{
    int code = which_command(command);
    switch (code) {
    case 11:
        if (args[0] && !args[1])
            return is_item(args[0]);
        break;
    case 8:
        if (!args[0])
            return true;
        break;
    case 12:
        if (!args[0])
            return true;
        break;
    default:
        return command_args_good_extra2(command, args);
    }
    return false;
}

static bool command_args_good_info2(char *command, char **args)
{
    int code = which_command(command);

    switch (code) {
    case 5:
        if (!args[0])
            return true;
        break;
    }
    return false;
}

bool command_args_good_info(char *command, char **args)
{
    int code = which_command(command);
    switch (code) {
    case 6:
        if (args[0] && !args[1])
            return true;
        break;
    case 7:
        if (!args[0])
            return true;
        break;
    case 4:
        if (!args[0])
            return true;
        break;
    default:
        return command_args_good_info2(command, args);
    }
    return false;
}

bool command_args_good_move(char *command, char **args)
{
    int code = which_command(command);

    switch (code) {
    case 1:
        if (!args[0])
            return true;
        break;
    case 2:
        if (!args[0])
            return true;
        break;
    case 3:
        if (!args[0])
            return true;
        break;
    default:
        return false;
    }
    return false;
}
