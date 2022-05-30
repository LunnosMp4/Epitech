/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** my_str_to_word_array.c
*/

#include "my.h"

static bool find_sep(char c, char *sep)
{
    for (int i = 0; sep[i]; i++)
        if (sep[i] == c)
            return true;
    return false;
}

static int max_words(char *str)
{
    int current_x = 1;
    int max_size = 0;

    if (my_strlen(str) < 1)
        return 0;
    for (int i = 0; str[i]; i++) {
        if (current_x > max_size)
            max_size = current_x;
        if (str[i] == '\n' || str[i] == ' ' || str[i] == '\0') {
            current_x = 0;
            continue;
        }
        current_x++;
    }
    return max_size;
}

static int count_line(char *buffer, char *sep, int *height)
{
    int i = 0;

    for (; buffer[i]; i++) {
        if (find_sep(buffer[i], sep))
            *height += 1;
    }
    if (!find_sep(buffer[i - 1], sep)) {
        *height += 1;
        i += 1;
    }
    return max_words(buffer) + 1;
}

static char **malloc_tab(int h, int w)
{
    char **arr = malloc(sizeof(char *) * (h + 1));

    for (int y = 0; y != h; y++) {
        arr[y] = (char *)malloc(sizeof(char) * ((w * h) + 1));
        arr[y][0] = '\0';
    }
    return arr;
}

char **my_str_to_word_array(char *buffer, char *sep)
{
    int height = 0;
    int width = count_line(buffer, sep, &height);
    char **arr = malloc_tab(height, width);
    int index = 0;
    int bindex = 0;

    for (int z = buffer[0] == 32 ? 1 : 0; buffer[z]; z++) {
        for (; (find_sep(buffer[z], sep) && find_sep(buffer[z + 1], sep))
        || (buffer[z] == 32 && buffer[z + 1] == 32); z++);
        if ((find_sep(buffer[z], sep)) && my_strlen(arr[bindex]) > 0) {
            index = 0;
            bindex++;
        } else {
            arr[bindex][index++] = buffer[z];
            arr[bindex][index] = '\0';
        }
    }
    arr[bindex + 1] = NULL;
    return arr;
}
