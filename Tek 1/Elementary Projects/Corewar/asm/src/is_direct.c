/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** is_direct
*/

#include "asm.h"

static int is_direct2(char *str, int i, int j)
{
    for (; LABEL_CHARS[j]; j++) {
        if (str[i] == LABEL_CHARS[j])
            break;
        if (LABEL_CHARS[j] == '\0' && str[i] != '\0')
            return 1;
    }
    return 0;
}

int is_direct(char *str)
{
    int i = 0;
    int j = 0;

    if (str[0] == DIRECT_CHAR)
        str++;
    else
        return 1;
    if ((str[0] == '-' && my_str_isnum(str++) == true) ||
        my_str_isnum(str) == true)
        return 0;
    if (str[0] == LABEL_CHAR) {
        str++;
    }
    for (; str[i]; i++) {
        if (is_direct2(str, i, j) == 1)
            return 1;
    }
    return 0;
}
