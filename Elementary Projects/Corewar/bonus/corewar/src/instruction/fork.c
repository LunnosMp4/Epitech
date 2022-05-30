/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** fork.c
*/

#include "corewar.h"

void do_fork(corewar_t *corewar, champion_t *champ, process_t *process)
{
    (void) corewar;
    (void) champ;
    process->cycle += op_tab[11].nbr_cycles;
}
