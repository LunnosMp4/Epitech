/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** is_label
*/

#include "asm.h"

int is_label(char *str)
{
    int len = my_strlen(str);

    if (str[len - 1] == LABEL_CHAR)
        return 0;
    return 1;
}
