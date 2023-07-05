/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** is_indirect
*/

#include "asm.h"

static int is_indirect2(char *str, int i, int j)
{
    for (; LABEL_CHARS[j]; j++) {
        if (str[i] == LABEL_CHARS[j])
            break;
        if (LABEL_CHARS[j] == '\0' && str[i] != '\0')
            return 1;
    }
    return 0;
}

int is_indirect(char *str)
{
    int i = 0;
    int j = 0;

    if (my_str_isnum(str) == true)
        return 0;
    if (str[0] == LABEL_CHAR)
        str++;
    else
        return 1;
    for (; str[i]; i++) {
        if (is_indirect2(str, i, j) == 1)
            return 1;
    }
    return 0;
}
