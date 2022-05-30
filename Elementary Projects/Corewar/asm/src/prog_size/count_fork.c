/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** count_fork
*/

#include "asm.h"

void count_fork(header_t *header, char **arr)
{
    if (is_direct(arr[1]) == 0)
        header->prog_size += 2;
}
