/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** print_win.c
*/

#include "corewar.h"

void print_win_last(corewar_t *corewar, lnk_list_t *champs)
{
    for (lnk_list_t *tmp = champs; tmp; tmp = tmp->next) {
        if (corewar->last_live == tmp->champ->id &&
        tmp->champ->is_alive == true) {
            my_printf("The player %d(%s) has won\n", corewar->last_live,
            tmp->champ->header->prog_name);
        }
    }
    exit(0);
}

void print_win(lnk_list_t *champs)
{
    for (lnk_list_t *tmp = champs; tmp; tmp = tmp->next) {
        if (tmp->champ->is_alive == true)
            my_printf("The player %d(%s) has won\n", tmp->champ->id,
            tmp->champ->header->prog_name);
    }
    exit(0);
}