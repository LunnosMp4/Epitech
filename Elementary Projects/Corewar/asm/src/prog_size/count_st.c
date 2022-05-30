/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** count_st
*/

#include "asm.h"

void count_st(header_t *header, char **arr)
{
    if (is_register(arr[1]) == 0)
        header->prog_size += 1;
    else if (is_indirect(arr[1]) == 0)
        header->prog_size += 2;
    if (is_register(arr[2]) == 0)
        header->prog_size += 1;
}
