/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** parsing_aff
*/

#include "asm.h"

void parsing_aff(char **arr, assembler_t *assem)
{
    int nb = coding_byte(arr);
    int param1 = keep_value(arr[1]);

    check_arg(arr, arr[0], 16);
    write(assem->fd2, &op_tab[8].code, sizeof(char));
    write(assem->fd2, &nb, sizeof(char));
    if (is_register(arr[1]) == 0)
        write(assem->fd2, &param1, REG_SIZE);
}
