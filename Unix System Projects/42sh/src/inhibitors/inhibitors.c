/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** inhibitors.c
*/

#include "my_sh.h"

static int count_backslash(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == '\\')
            count++;
        i++;
    }
    return count;
}

static void complex_sorting(inhibitors_t *ibt, char *str)
{
    if (str[ibt->i + 1] == '\\' && str[ibt->i + 2] != '\\' && ibt->nb < 4)
        ibt->new_str[ibt->j] = '\\';
    else if (str[ibt->i + 1] == '\\' && str[ibt->i + 2] == '\\') {
        ibt->new_str[ibt->j] = '\\';
        ibt->j++;
    } else {
        ibt->new_str[ibt->j] = ' ';
        ibt->j++;
    }
}

static void base_sorting(inhibitors_t *ibt, char *str)
{
    if (str[ibt->i + 1] == '\\') {
        ibt->new_str[ibt->j] = '\\';
        ibt->j++;
        ibt->i++;
    } else
        complex_sorting(ibt, str);
    ibt->i++;
}

static char *process_loop(inhibitors_t *ibt, char *str)
{
    for (ibt->i = 0; str[ibt->i] != '\0';) {
        if (str[ibt->i] == '\\')
            base_sorting(ibt, str);
        else {
            ibt->new_str[ibt->j] = str[ibt->i];
            ibt->j++;
            ibt->i++;
        }
    }
    return ibt->new_str;
}

char *process_inhibitors(char *str)
{
    inhibitors_t *ibt = malloc(sizeof(inhibitors_t));
    ibt->nb = count_backslash(str);
    if (ibt->nb == 0)
        return str;
    ibt->j = 0;
    ibt->new_str = malloc(sizeof(char) * (my_strlen(str) + ibt->nb + 1));

    ibt->new_str = process_loop(ibt, str);
    ibt->new_str[ibt->j] = '\0';
    for (int i = 0; i < my_strlen(ibt->new_str); i++)
        if (ibt->new_str[i] == ' ' && ibt->new_str[i + 1] == ' ')
            fix_space_inhibitors(ibt, i);
    return ibt->new_str;
}
