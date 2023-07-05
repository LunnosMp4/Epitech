/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** process_vm.c
*/

#include "corewar.h"

static int check_lives(lnk_list_t *champs)
{
    int nb_live = 0;

    for (lnk_list_t *tmp = champs; tmp; tmp = tmp->next) {
        if (tmp->champ->is_alive == true)
            nb_live++;
    }
    return nb_live;
}

static void start_instruction(corewar_t *corewar,
champion_t *champ, process_t *process)
{
    for (process_t *tmp = process; tmp != NULL; tmp = tmp->next) {
        if (check_lives(corewar->champs) <= 1)
            print_win(corewar->champs);
        execute_instruction(corewar, champ, process);
        if (tmp->child != NULL && tmp->child->is_alive == 1)
            start_instruction(corewar, champ, tmp->child);
    }
}

static void process_instruction(corewar_t *corewar, lnk_list_t *champs)
{
    for (lnk_list_t *tmp = champs; tmp; tmp = tmp->next) {
        if (tmp->champ->is_alive == true)
            start_instruction(corewar, tmp->champ, tmp->champ->process);
    }
}

static int process_cycle(corewar_t *corewar)
{
    if (corewar->cycle - corewar->last_cycle_check >=
    corewar->cycle_to_die) {
        corewar->last_cycle_check = corewar->cycle;
        corewar->cycle_to_die -= CYCLE_DELTA;
        if (corewar->cycle_to_die <= 0)
            return 1;
    }
    return 0;
}

void run_vm(corewar_t *corewar)
{
    corewar->cycle = 0;
    corewar->last_cycle_check = corewar->cycle;
    corewar->cycle_to_die = CYCLE_TO_DIE;
    corewar->nb_live = NBR_LIVE;
    corewar->nb_check = 0;

    while (corewar->cycle_to_die > 0 && corewar->nb_live > 0) {
        process_instruction(corewar, corewar->champs);
        if (check_lives(corewar->champs) <= 1)
            print_win(corewar->champs);
        if (process_cycle(corewar) == 1)
            break;
        corewar->cycle++;
    }
    print_win_last(corewar, corewar->champs);
}
