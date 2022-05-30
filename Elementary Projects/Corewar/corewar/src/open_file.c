/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** open_file.c
*/

#include "corewar.h"

void open_file(int ac, char **av, corewar_t *corewar)
{
    for (int i = 1; i != ac; i++)
        if (corewar->nb[i])
            add_node(read_cor(av[i]), &corewar->champs);
}
