/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** unset_alias.c
*/

#include "my_sh.h"

void unset_alias(char *line, env_t **list, UNUSED char **env)
{
    int len_cmd = 0;
    char **cmd = strsplit(line, " \t", false);

    line += find_word(line, cmd[2]);
    for (len_cmd = 0; cmd[len_cmd]; len_cmd += 1);
    if (len_cmd < 2) {
        fprintf(stderr, "unalias: Too few arguments.\n");
        p_ntty(HEADER, *list);
        return;
    }
    for (int i = 1; cmd[i]; i++)
        search_node(cmd[i], list);
    p_ntty(HEADER, *list);
}
