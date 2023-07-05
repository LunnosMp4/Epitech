/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** tools
*/

#include "server.h"

bool is_in_array(char **array, char *str)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (strcmp(array[i], str) == 0) {
            return true;
        }
    }

    return false;
}

bool is_only_digits(char *str)
{
    if (str == NULL)
        return false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }

    return true;
}

bool is_item(char *item)
{
    if (strcmp(item, "food") == 0 || strcmp(item, "linemate") == 0 ||
    strcmp(item, "deraumere") == 0 || strcmp(item, "sibur") == 0 ||
    strcmp(item, "mendiane") == 0 || strcmp(item, "phiras") == 0 ||
    strcmp(item, "thystame") == 0)
        return true;
    return false;
}
