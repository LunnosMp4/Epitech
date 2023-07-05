/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_str_isprintable.c
*/

#include "my.h"

bool my_str_isprintable(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < ' ' || str[i] == 127)
            return false;
    return true;
}
