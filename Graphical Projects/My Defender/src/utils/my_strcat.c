/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** str cat
*/

#include "my_defender.h"

char *my_strcat(char *dest , char const *src)
{
    int arg = 0;
    int dest_len = my_strlen(dest);

    while (src[arg] != '\0') {
        dest[dest_len + arg] = src[arg];
        arg++;
    }
    dest[dest_len + arg] = '\0';

    return dest;
}
