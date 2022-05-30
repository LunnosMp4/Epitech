/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** coding_byte
*/

#include "asm.h"

int coding_byte(char **arr)
{
    int nb = 0;
    char *str = malloc(sizeof(char) * 1000);

    str[0] = '\0';
    for (int i = 0; arr[i]; i++) {
        if (is_register(arr[i]) == 0)
            str = my_strcat(str, "01");
        if (is_direct(arr[i]) == 0)
            str = my_strcat(str, "10");
        if (is_indirect(arr[i]) == 0)
            str = my_strcat(str, "11");
    }
    str = my_strcat(str, "00");
    nb = binary_to_decimal(str);
    return nb;
}
