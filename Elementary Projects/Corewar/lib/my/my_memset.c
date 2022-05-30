/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** my_memset
*/

#include "my.h"

void *my_memset(void *ptr, int c, size_t n)
{
    for (size_t i = 0; i < n; i++)
        ((char *)ptr)[i] = c;
    return ptr;
}
