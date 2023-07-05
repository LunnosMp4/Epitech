/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** execute_instruction.c
*/

#include "corewar.h"

static void execute_instruction3(corewar_t *corewar,
champion_t *champ, process_t *process)
{
    switch (corewar->arena[process->pos_process]) {
        case 12: do_fork(corewar, champ, process);
            break;
        case 13: do_lld(corewar, champ, process);
            break;
        case 14: do_lldi(corewar, champ, process);
            break;
        case 15: do_lfork(corewar, champ, process);
            break;
        case 16: do_aff(corewar, champ, process);
            break;
    }
}

static void execute_instruction2(corewar_t *corewar,
champion_t *champ, process_t *process)
{
    switch (corewar->arena[process->pos_process]) {
        case 4: do_add(corewar, champ, process);
            break;
        case 5: do_sub(corewar, champ, process);
            break;
        case 6: do_and(corewar, champ, process);
            break;
        case 7: do_or(corewar, champ, process);
            break;
        case 8: do_xor(corewar, champ, process);
            break;
        case 9: do_zjmp(corewar, champ, process);
            break;
        case 10: do_ldi(corewar, champ, process);
            break;
        case 11: do_sti(corewar, champ, process);
            break;
    }
    execute_instruction3(corewar, champ, process);
}

void execute_instruction(corewar_t *corewar,
champion_t *champ, process_t *process)
{
    if (process->cycle == 0) {
        if (corewar->arena[process->pos_process] >= 1 &&
        corewar->arena[process->pos_process] <= 16) {
            switch (corewar->arena[process->pos_process]) {
                case 1: do_live(corewar, champ, process);
                    break;
                case 2: do_ld(corewar, champ, process);
                    break;
                case 3: do_st(corewar, champ, process);
                    break;
            }
            execute_instruction2(corewar, champ, process);
            process->pos_process += 1;
            process->pos_process = modulo_op(process->pos_process, MEM_SIZE);
        } else {
            process->pos_process += 1;
            process->pos_process = modulo_op(process->pos_process, MEM_SIZE);
        }
    } else
        process->cycle -= 1;
}
