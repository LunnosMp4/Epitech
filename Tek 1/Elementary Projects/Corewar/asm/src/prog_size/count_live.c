/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** count_live
*/

#include "asm.h"

void count_live(info_file_t *info, header_t *header, char **arr)
{
    if (is_direct(arr[1]) == 0) {
        header->prog_size += 4;
        info->check_live = 1;
    }
}
