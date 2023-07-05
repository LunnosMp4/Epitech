/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** count_or
*/

#include "asm.h"

void count_or(header_t *header, char **arr)
{
    if (is_register(arr[1]) == 0)
        header->prog_size += 1;
    else if (is_direct(arr[1]) == 0)
        header->prog_size += 4;
    else
        header->prog_size += 2;
    if (is_register(arr[2]) == 0)
        header->prog_size += 1;
    else if (is_direct(arr[2]) == 0)
        header->prog_size += 4;
    else
        header->prog_size += 2;
    if (is_register(arr[3]) == 0)
        header->prog_size += 1;
}
