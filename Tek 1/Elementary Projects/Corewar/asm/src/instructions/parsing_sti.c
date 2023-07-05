/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** parsing_sti
*/

#include "asm.h"

void parsing_sti(char **arr, assembler_t *assem)
{
    int nb = coding_byte(arr);
    int param1 = keep_value(arr[1]);
    int param2 = keep_value(arr[2]);
    int param3 = keep_value(arr[3]);

    check_arg(arr, arr[0], 10);
    write(assem->fd2, &op_tab[10].code, sizeof(char));
    write(assem->fd2, &nb, sizeof(char));
    if (is_register(arr[1]) == 0)
        write(assem->fd2, &param1, REG_SIZE);
    if (is_register(arr[2]) == 0)
        write(assem->fd2, &param2, REG_SIZE);
    else if (is_direct(arr[2]) == 0 || is_indirect(arr[2]) == 0)
        write(assem->fd2, &param2, IND_SIZE);
    if (is_register(arr[3]) == 0) {
        write(assem->fd2, &param3, REG_SIZE);
    } else
        write(assem->fd2, &param3, IND_SIZE);
}
