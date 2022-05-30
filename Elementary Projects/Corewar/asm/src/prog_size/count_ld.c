/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** count_ld
*/

#include "asm.h"

void count_ld(header_t *header, char **arr)
{
    if (is_direct(arr[1]) == 0)
        header->prog_size += 4;
    else if (is_indirect(arr[1]) == 0)
        header->prog_size += 2;
    if (is_register(arr[2]) == 0)
        header->prog_size += 1;
}
