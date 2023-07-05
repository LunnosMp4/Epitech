/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** parsing_lfork
*/

#include "asm.h"

void parsing_lfork(char **arr, assembler_t *assem)
{
    int param1 = keep_value(arr[1]);

    check_arg(arr, arr[0], 14);
    write(assem->fd2, &op_tab[14].code, sizeof(char));
    if (is_direct(arr[1]) == 0)
        write(assem->fd2, &param1, IND_SIZE);
}
