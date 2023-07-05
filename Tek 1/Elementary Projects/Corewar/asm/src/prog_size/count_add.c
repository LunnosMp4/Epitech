/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** count_add
*/

#include "asm.h"

void count_add(header_t *header, char **arr)
{
    if (is_register(arr[1]) == 0)
        header->prog_size += 1;
    if (is_register(arr[2]) == 0)
        header->prog_size += 1;
    if (is_register(arr[3]) == 0)
        header->prog_size += 1;
}
