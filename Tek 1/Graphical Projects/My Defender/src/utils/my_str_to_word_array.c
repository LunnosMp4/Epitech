/*
** EPITECH PROJECT, 2021
** My Defender
** File description:
** my_str_to_word_array.c
*/

#include "my_defender.h"

int count_line(char *str, int *nbline)
{
    int i;

    for (i = 0; str[i]; i++)
        if (str[i] == '\n' && str[i + 1] != '\0')
            *nbline += 1;
    *nbline += 1;
    return ((i + 1) - (*nbline)) / (*nbline);
}

char **save_posstr(char *str)
{
    int i = 0;
    int j = 0;
    int nbline = 0;
    int nbrow = count_line(str, &nbline);
    char **p_str = malloc(sizeof(char *) * (nbline + 1));

    for (int tab = 0; tab < nbline; tab++) {
        p_str[tab] = malloc(sizeof(char) * nbrow + 1);
        for (j = 0; j < nbrow; j++)
            p_str[tab][j] = str[i++];
        p_str[tab][j] = '\0';
        i += 1;
    }
    p_str[nbline] = NULL;
    return p_str;
}
