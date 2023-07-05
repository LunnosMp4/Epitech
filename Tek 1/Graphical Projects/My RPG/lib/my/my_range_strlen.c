/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** my_range_strlen.c
*/

#include "my.h"

int range_strlen(char const *str, char const *start, char const *stop,
bool count_start)
{
    int i = 0;
    int len = 0;

    if (!str || !stop)
        return -1;
    if (start) {
        if (!count_start)
            len -= my_strlen(start);
        i = find_word(str, start);
    }
    if (!str[i])
        return -1;
    for (; str[i] && !str_isequal(str + i, stop, false); i++)
        len++;
    if (!str[i] && i == 0)
        return -1;
    return len;
}
