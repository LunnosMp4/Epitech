/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** my_arenacpy.c
*/

char *my_arenacpy(char *dest, char *src, int max_size)
{
    int j = 0;

    for (int i = 0; i != max_size; i++) {
        if (src[i] == 0)
            dest[j++] = 0;
        dest[j++] = src[i];
    }
    return dest;
}
