/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** my_str_contains.c
*/

#include "my.h"

bool str_contains(char const *content, char const *container)
{
    for (int i = 0; content[i]; i++)
        if (str_isequal(content + i, container, false))
            return true;
    return true;
}
