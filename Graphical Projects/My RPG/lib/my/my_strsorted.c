/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** my_strsorted.c
*/

#include "my.h"

static char *split_by_word(char *str, char *word)
{
    int i = 0;
    int j = 0;
    char *str_sorted = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str_isequal(str, word, false) && *str)
        str += my_strlen(word);
    while (str[i]) {
        if (i > 1 && str_isequal(str + i, word, false)) {
            i += my_strlen(word);
            str_sorted[j++] = ' ';
        }
        str_sorted[j++] = str[i];
        i++;
    }
    if (str[i])
        return str;
    str_sorted[j] = '\0';
    return str_sorted;
}

static char *split_each_char(char *str, char *splitters)
{
    int i = 0;
    int j = 0;
    char *str_sorted = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (ch_isequal(*str, splitters) && *str)
        str += 1;
    while (str[i]) {
        while (i > 1 && ch_isequal(str[i], splitters))
            i++;
        if (i > 1 && ch_isequal(str[i - 1], splitters))
            str_sorted[j++] = ' ';
        str_sorted[j++] = str[i];
        i++;
    }
    if (str[i])
        return str;
    str_sorted[j] = '\0';
    return str_sorted;
}

char *strsorted(char *str, char *cut, bool word)
{
    if (word)
        return split_by_word(str, cut);
    return split_each_char(str, cut);
}
