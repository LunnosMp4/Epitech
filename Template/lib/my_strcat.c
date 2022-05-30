/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** str cat
*/

#include "my_lib.h"

char *my_strcat(char *dest , char const *str)
{
    int arg = 0;
    int dest_len = my_strlen(dest);

    while (str[arg] != '\0') {
        dest[dest_len + arg] = str[arg];
        arg++;
    }
    dest[dest_len + arg] = '\0';

    return dest;

}
