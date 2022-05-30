/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** my_str_isequal.c
*/

#include "my.h"

bool str_isequal(char const *from, char const *to, bool strict)
{
    int i = 0;

    if (!from || !to)
        return false;
    while (from[i] && to[i]) {
        if (from[i] != to[i])
            return false;
        i++;
    }
    if (to[i])
        return false;
    if (strict)
        return from[i] == to[i];
    return true;
}
