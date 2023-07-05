/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** my_strsplit.c
*/

#include "my.h"

static int nb_of_word(char *str, char *cut)
{
    int nb = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == cut[0] && str[i + 1])
            nb += 1;
    return nb + 1;
}

char **strsplit(char *str, char *cut)
{
    char *sstr = strsorted(str, cut);
    int nb = 0;
    char **tab = NULL;
    int j = 0;

    if (!sstr)
        return NULL;
    nb = nb_of_word(sstr, cut);
    tab = malloc(sizeof(char *) * (nb + 1));
    for (int i = 0; j < nb; i += range_strlen(sstr + i, NULL, cut, false) + 1)
        tab[j++] = range_strdup(sstr + i, NULL, cut, false);
    tab[nb] = NULL;
    free(sstr);
    return tab;
}
