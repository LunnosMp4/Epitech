/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** main.c
*/

#include "graphic.h"

int main(int argc, char **argv)
{
    corewar_t *corewar = init_corewar();

    error_handling(argc, argv);
    check_cor(argc, argv, corewar);
    open_file(argc, argv, corewar);
    init_arena(corewar, argc);
    for (int i = 0; i < argc; i++)
        if (argv[i] && str_isequal(argv[i], "-g", true))
            return graphic(corewar);
    run_vm(corewar);

    return 0;
}
