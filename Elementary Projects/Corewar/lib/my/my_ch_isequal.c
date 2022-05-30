/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** my_ch_isequal.c
*/

#include "my.h"

bool ch_isequal(char ch, char const *container)
{
    for (int i = 0; container[i]; i++)
        if (ch == container[i])
            return true;
    return false;
}
