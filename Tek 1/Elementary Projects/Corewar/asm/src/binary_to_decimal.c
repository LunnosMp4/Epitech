/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** binary_to_decimal
*/

#include "asm.h"

int binary_to_decimal(char *str)
{
    int nb = 0;
    int len = my_strlen(str);

    for (int i = 0; str[i]; i++)
        if (str[i] == '1')
            nb = nb + (1 * my_compute_power_rec(2, len - i - 1));
    return nb;
}
