/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_str_islower.c
*/

#include <stdbool.h>

bool my_str_islower(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 'a' || str[i] > 'z')
            return false;
    return true;
}
