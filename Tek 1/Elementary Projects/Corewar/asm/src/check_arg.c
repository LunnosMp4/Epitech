/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** check_arg
*/

#include "asm.h"

void check_arg(char **arr, char *str, int i)
{
    int nb_arg = 0;

    for (int i = 1; arr[i]; i++, nb_arg++);
    if (op_tab[i].nbr_args != nb_arg) {
        my_printf("Wrong number of arguments for %s instruction.\n", str);
        exit(84);
    }
}
