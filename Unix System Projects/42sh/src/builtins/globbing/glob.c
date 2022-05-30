/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** glob.c
*/

#include "my_sh.h"

int globbing_error(char **cmd, env_t *list, int r)
{
    if (r != 0) {
        if (r == GLOB_NOMATCH) {
            fprintf(stderr, "%s: No match.\n", cmd[0]);
            p_ntty(HEADER, list);
            return 1;
        } else {
            fprintf(stderr, "%s: Some kinda glob error.\n", cmd[0]);
            p_ntty(HEADER, list);
            return 1;
        }
    }
    return 0;
}

void my_globbing(char *line, env_t *list)
{
    char **found;
    glob_t gstruct;
    char **cmd = strsplit(line, " \t", true);
    int r = 0;
    int i = 0;

    for (int i = 0; cmd[i]; i += 1)
        r = glob(cmd[i], GLOB_ERR, NULL, &gstruct);
    if (globbing_error(cmd, list, r) == 1)
        return;
    found = gstruct.gl_pathv;
    cmd[my_len_tab(cmd) - 1] = NULL;
    cmd = realloc(cmd, sizeof(char *) * (my_len_tab(cmd) +
    my_len_tab(found) + 1));
    for (int i = my_len_tab(cmd); *found; i++) {
        cmd[i] = *found;
        found += 1;
    }
    cmd[i] = NULL;
}
