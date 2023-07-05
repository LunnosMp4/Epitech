/*
** EPITECH PROJECT, 2021
** test
** File description:
** find_word.c
*/

#include "my.h"

int find_word(char const *str, char const *word)
{
    int index = 0;

    if (!word)
        return 0;
    while (str[index] && !str_isequal(str + index, word, false))
        index++;
    return index;
}
