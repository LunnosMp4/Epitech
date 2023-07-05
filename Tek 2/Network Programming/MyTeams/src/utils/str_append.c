/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** str_append.c
*/

#include "myteams.h"

char *str_append(char *dest, const char *src)
{
    size_t dest_len = dest != NULL ? strlen(dest) : 0;
    size_t src_len = strlen(src);
    size_t new_size = dest_len + src_len + 1;

    dest = realloc(dest, new_size);
    if (dest == NULL)
        return NULL;
    memcpy(dest + dest_len, src, src_len + 1);
    return dest;
}
