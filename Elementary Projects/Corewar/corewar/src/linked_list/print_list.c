/*
** EPITECH PROJECT, 2022
** LIB
** File description:
** print_list.c
*/

#include "corewar.h"

void print_list(lnk_list_t *node)
{
    if (!node)
        return;
    my_printf("%d\n", node->champ->hex_code);
    print_list(node->next);
}
