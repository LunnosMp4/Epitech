/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** lld.c
*/

#include "corewar.h"

void do_lld(corewar_t *corewar, champion_t *champ, process_t *process)
{
    (void) corewar;
    (void) champ;
    change_carry(process);
    process->cycle += op_tab[12].nbr_cycles;
}
