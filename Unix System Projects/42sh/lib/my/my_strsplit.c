/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** my_strsplit.c
*/

#include "my.h"

static int nb_of_word(char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == ' ' && str[i + 1])
            nb++;
    return nb + 1;
}

char **strsplit(char *str, char *cut, bool word)
{
    char *sstr = strsorted(str, cut, word);
    int nb = 0;
    char **tab = NULL;
    int j = 0;

    if (!sstr)
        return NULL;
    nb = nb_of_word(sstr);
    tab = malloc(sizeof(char *) * (nb + 1));
    for (int i = 0; j < nb; i += range_strlen(sstr + i, NULL, " ", false) + 1)
        tab[j++] = range_strdup(sstr + i, NULL, " ", false);
    tab[nb] = NULL;
    free(sstr);
    return tab;
}
