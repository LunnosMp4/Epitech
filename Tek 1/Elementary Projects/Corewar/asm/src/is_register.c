/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** is_register
*/

#include "asm.h"

int is_register(char *str)
{
    if (str[0] == 'r')
        str++;
    else
        return 1;
    if (my_getnbr(str) > 0 && my_getnbr(str) < 17)
        return 0;
    return 1;
}
