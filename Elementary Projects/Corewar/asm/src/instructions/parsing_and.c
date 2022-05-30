/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** parsing_and
*/

#include "asm.h"

static void write_good_register(char **arr, assembler_t *assem, int param1)
{
    if (is_register(arr[1]) == 0)
        write(assem->fd2, &param1, REG_SIZE);
    else if (is_indirect(arr[1]) == 0)
        write(assem->fd2, &param1, IND_SIZE);
    else
        write(assem->fd2, &param1, DIR_SIZE);
}

void parsing_and(char **arr, assembler_t *assem)
{
    int nb = coding_byte(arr);
    int param1 = keep_value(arr[1]);
    int param2 = keep_value(arr[2]);
    int param3 = keep_value(arr[3]);

    check_arg(arr, arr[0], 5);
    write(assem->fd2, &op_tab[5].code, sizeof(char));
    write(assem->fd2, &nb, sizeof(char));
    write_good_register(arr, assem, param1);
    if (is_register(arr[2]) == 0)
        write(assem->fd2, &param2, REG_SIZE);
    else if (is_indirect(arr[2]) == 0)
        write(assem->fd2, &param2, IND_SIZE);
    else
        write(assem->fd2, &param2, DIR_SIZE);
    if (is_register(arr[3]) == 0)
        write(assem->fd2, &param3, REG_SIZE);
}
