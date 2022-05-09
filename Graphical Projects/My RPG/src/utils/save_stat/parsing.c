/*
** EPITECH PROJECT, 2021
** my_part
** File description:
** parsing.c
*/

#include "my_rpg.h"

char **parsing_arg(char *buffer)
{
    char **tab = split_string(buffer, '\n');
    char *new_string = malloc(sizeof(char) * (my_strlen(tab[2]) + 1));
    char **final_tab = split_string(my_strcpy(new_string, tab[2]), ' ');

    return final_tab;
}
