/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** exit.c
*/

#include "my_sh.h"

void exec_exit(char *line, env_t **list, UNUSED char **env)
{
    int argc;
    int val_exit = 0;
    char **cmd = strsplit(line, " \t", false);

    for (argc = 0; cmd[argc]; argc++);
    if (argc > 1) {
        if (cmd[1] && my_str_isnum(cmd[1]) && argc == 2) {
            p_ntty(EXIT, *list);
            val_exit = my_getnbr(cmd[1]);
            exit(val_exit);
        }
        fprintf(stderr, "exit: Expression Syntax.\n");
        return;
    }
    p_ntty(EXIT, *list);
    exit(0);
}
