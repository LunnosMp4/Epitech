/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** itoa.c
*/

#include "graphic.h"

char *itoa(int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;

    if (nb == 0)
        return "0";
    if (nb < 0) {
        str[i++] = '-';
        nb = -nb;
    }
    while (nb > 0) {
        str[i] = nb % 10 + '0';
        nb = nb / 10;
        i++;
    }
    str[i] = '\0';
    return str;
}
