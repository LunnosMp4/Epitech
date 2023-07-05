/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** keep_value
*/

#include "asm.h"

int keep_value(char *str)
{
    int nb = 0;

    if (is_register(str) == 0) {
        str++;
        return my_getnbr(str);
    }
    if (is_direct(str) == 0 && str[1] == '-') {
        str++;
        str++;
    } else if (is_direct(str) == 0 && str[1] == LABEL_CHAR) {
        str++;
        str++;
    } else
        str++;
    if (is_indirect(str) == 0)
        str++;
    if (my_getnbr(str) < 9)
        str = my_strcat("0", str);
    nb = my_getnbr(str);
    return nb;
}
