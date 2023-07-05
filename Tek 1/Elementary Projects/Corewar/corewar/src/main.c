/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** main.c
*/

#include "corewar.h"

int main(int argc, char **argv)
{
    corewar_t *corewar = init_corewar();

    error_handling(argc, argv);
    check_cor(argc, argv, corewar);
    open_file(argc, argv, corewar);
    init_arena(corewar, argc);
    run_vm(corewar);
    return 0;
}
