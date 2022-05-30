/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_cor.c
*/

#include "corewar.h"

static void check_file(char *str)
{
    if (!str_isequal(str + find_word(str, ".cor"), ".cor", true)) {
        my_putstr("Error: file is not a .cor file\n");
        exit(84);
    }
}

static int set_flag(char *arg)
{
    for (int i = 0; arg[i]; i++) {
        if (arg[i] < '0' || arg[i] > '9') {
            exit(84);
        }
    }
    return (my_getnbr(arg));
}

static void check_flags(corewar_t *corewar, char *flag, char *arg)
{
    if (str_isequal(flag, "-dump", true) == true)
        corewar->dump_max = set_flag(arg);
}

void check_cor(int ac, char **av, corewar_t *corewar)
{
    int j = 0;
    int *nb = malloc(sizeof(int) * ac);
    for (int i = 0; i < ac; i++)
        if (av[i + 1] != NULL)
            check_flags(corewar, av[i], av[i + 1]);
    for (int i = 1; i != ac; i++)
        nb[i] = 1;
    for (int i = 1; i != ac; i++, j += 2) {
        if (str_isequal(av[i], "-g", true))
            nb[i] = 0;
        else if (av[i][0] == '-' && av[i + 2] != NULL) {
            nb[i] = 0;
            nb[i + 1] = 0;
            i++;
        } else {
            check_file(av[i]);
            nb[i] = 1;
        }
    }
    corewar->nb = nb;
}
