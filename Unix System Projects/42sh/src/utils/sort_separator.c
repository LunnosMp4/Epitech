/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-enzo.daumalle
** File description:
** sort_separator.c
*/

#include "my_sh.h"

static int is_sep(char **sep, char *line)
{
    int i = 0;

    for (i = 0; sep[i]; i++)
        if (str_isequal(line, sep[i], false))
            return i;
    return 0;
}

static void error_seps(int state)
{
    char *error = NULL;

    switch (state) {
        case 3:
        case 4:
        case 5:
        case 6: error = "Missing name for redirect.";
            break;
        case 0:
        case 1:
        case 2: error = "Invalid null command.";
            break;
        default:
            break;
    }
    fprintf(stderr, "%s\n", error);
}

static bool contains_words(char ch, bool wait_cmd)
{
    if (!ch_isequal(ch, " \t\n") || !wait_cmd)
        return false;
    return true;
}

static char *check_syntax(char *str, char **seps)
{
    bool wait_cmd = true;
    int state = 0;
    int i = 0;

    while (str[i]) {
        for (; str[i] && is_sep(seps, str + i) == 0; i++)
            wait_cmd = contains_words(str[i], wait_cmd);
        if ((state = is_sep(seps, str + i)) != 0 && wait_cmd)
            break;
        else if (is_sep(seps, str + i) != 0 && !wait_cmd) {
            wait_cmd = true;
            i += my_strlen(seps[state]);
        }
    }
    if (state != 0) {
        error_seps(state);
        return NULL;
    }
    return str;
}

char *sort_seps(char *str, char **seps)
{
    int i = 0;
    int j = 0;
    char *str_sorted = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (*str == **seps && *str)
        str += 1;
    while (str[i]) {
        while (str[i] == **seps)
            i++;
        if (i > 1 && str[i - 1] == **seps)
            str_sorted[j++] = **seps;
        str_sorted[j++] = str[i];
        if (str[i])
            i++;
    }
    if (str[i])
        return str;
    str_sorted[j] = '\0';
    return check_syntax(str_sorted, seps);
}
