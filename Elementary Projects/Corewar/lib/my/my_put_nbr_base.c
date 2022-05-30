/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** my_put_nbr_base
*/

#include "my.h"

int my_put_nbr_base(int nbr, char const *base)
{
    if (!base)
        return -1;
    if (nbr > 0) {
        my_put_nbr_base(nbr / my_strlen(base), base);
        my_putchar(base[nbr % my_strlen(base)]);
    }
    return 0;
}
