/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** my_range_strdup.c
*/

#include "my.h"

char *range_strdup(char const *str, char const *start, char const *stop,
bool count_start)
{
    int i = 0;
    int j = 0;
    int len = range_strlen(str, start, stop, count_start);
    char *new = malloc(sizeof(char) * (len + 1));

    if (!str || !stop || len == -1)
        return NULL;
    i = find_word(str, start);
    if (!count_start && i != 0)
        i += my_strlen(start);
    while (str[i] && !str_isequal(str + i, stop, false))
        new[j++] = str[i++];
    new[j] = '\0';
    if (!new[0])
        return NULL;
    return new;
}
