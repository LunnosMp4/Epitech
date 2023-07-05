/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** parsing_st
*/

#include "asm.h"

void parsing_st(char **arr, assembler_t *assem)
{
    int nb = coding_byte(arr);
    int param1 = keep_value(arr[1]);
    int param2 = keep_value(arr[2]);

    check_arg(arr, arr[0], 2);
    write(assem->fd2, &op_tab[2].code, sizeof(char));
    write(assem->fd2, &nb, sizeof(char));
    if (is_register(arr[1]) == 0)
        write(assem->fd2, &param1, REG_SIZE);
    if (is_indirect(arr[2]) == 0)
        write(assem->fd2, &param2, IND_SIZE);
    else if (is_register(arr[2]) == 0)
        write(assem->fd2, &param2, REG_SIZE);
}
