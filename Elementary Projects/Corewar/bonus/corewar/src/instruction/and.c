/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** and.c
*/

#include "corewar.h"

void do_and(corewar_t *corewar, champion_t *champ, process_t *process)
{
    (void) corewar;
    (void) champ;
    change_carry(process);
    process->cycle += op_tab[5].nbr_cycles;
}
