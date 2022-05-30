/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** setenv.c
*/

#include "my_sh.h"

static bool error_handling(char **cmd, int len_cmd)
{
    if (len_cmd > 3) {
        fprintf(stderr, "setenv: Too many arguments.\n");
        return true;
    }
    if (cmd[1][0] < 'A' || cmd[1][0] > 'z' ||
    (cmd[1][0] > 'Z' && cmd[1][0] < 'a')) {
        fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
        return true;
    }
    if (!my_str_isalpha_numeric(cmd[1])) {
        fprintf(stderr, "setenv: Variable name must ");
        fprintf(stderr, "contain alphanumeric characters.\n");
        return true;
    }
    return false;
}

void set_env(char *line, env_t **list, char **env)
{
    int len_cmd = 0;
    char **cmd = strsplit(line, " \t", false);

    for (len_cmd = 0; cmd[len_cmd]; len_cmd += 1);
    if (len_cmd == 1) {
        exec_env(NULL, list, env);
        return;
    }
    if (error_handling(cmd, len_cmd)) {
        p_ntty(HEADER, *list);
        return;
    }
    if (len_cmd == 2)
        add_node_at_back(cmd[1], "\0", ENV, list);
    if (len_cmd == 3)
        add_node_at_back(cmd[1], cmd[2], ENV, list);
    p_ntty(HEADER, *list);
}
