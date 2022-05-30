/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** parsing_ld
*/

#include "asm.h"

void parsing_ld(char **arr, assembler_t *assem)
{
    int nb = coding_byte(arr);
    int param1 = keep_value(arr[1]);
    int param2 = keep_value(arr[2]);

    check_arg(arr, arr[0], 1);
    write(assem->fd2, &op_tab[1].code, sizeof(char));
    write(assem->fd2, &nb, sizeof(char));
    if (is_direct(arr[1]) == 0)
        write(assem->fd2, &param1, DIR_SIZE);
    else if (is_indirect(arr[1]) == 0)
        write(assem->fd2, &param1, IND_SIZE);
    if (is_register(arr[2]) == 0)
        write(assem->fd2, &param2, REG_SIZE);
}
