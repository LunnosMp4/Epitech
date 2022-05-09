/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-luca.orelli
** File description:
** split_sep.c
*/

#include "my_rpg.h"

int count(char const *str, char ch)
{
    int cpt = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == ch)
            cpt++;
    return cpt;
}

char **split_string(char const *str, char sep)
{
    int count_words = count(str, sep);
    int j = 0;
    int x = 0;
    char **tab = malloc(sizeof(char *) * (count_words + 2));

    for (int i = 0; str[i] != '\0'; j++) {
        for (; str[i] == sep && str[i] != '\0'; i++);
        if (str[i] == '\0' || tab == NULL)
            break;
        for (x = i; str[x] != sep && str[x] != '\0'; x++);
        tab[j] = malloc(sizeof(char) * (x - i + 2));
        for (x = 0; str[i] != sep && str[i] != '\0'; i++) {
            tab[j][x] = str[i];
            x++;
        }
        tab[j][x] = '\0';
    }
    tab[j] = NULL;
    return tab;
}
