/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** live.c
*/

#include "corewar.h"

void do_live(corewar_t *corewar, champion_t *champ, process_t *process)
{
    champ->is_alive = true;
    champ->nb_live++;
    corewar->last_live = champ->id;
    corewar->nb_live++;
    process->pc = (process->pc + 1) % MEM_SIZE;
    process->is_alive = 1;
    process->cycle += op_tab[0].nbr_cycles;
    my_printf("The player %d(%s) is alive\n",
    champ->id, champ->header->prog_name);
}
