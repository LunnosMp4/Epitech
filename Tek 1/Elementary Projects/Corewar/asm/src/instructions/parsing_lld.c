/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** parsing_lld
*/

#include "asm.h"

void parsing_lld(char **arr, assembler_t *assem)
{
    int param1 = keep_value(arr[1]);
    int param2 = keep_value(arr[2]);
    int nb = coding_byte(arr);

    check_arg(arr, arr[0], 12);
    write(assem->fd2, &op_tab[12].code, sizeof(char));
    write(assem->fd2, &nb, sizeof(char));
    if (is_direct(arr[1]) == 0)
        write(assem->fd2, &param1, DIR_SIZE);
    else if (is_indirect(arr[1]) == 0)
        write(assem->fd2, &param2, IND_SIZE);
    if (is_register(arr[2]) == 0)
        write(assem->fd2, &param2, REG_SIZE);
}
