/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** do_or_stuff.c
*/

#include "my_sh.h"

static void exe_or_stuff(char **env, char **cmd, char *path, int *stat)
{
    pid_t pid = 0;
    int wstatus = 0;

    pid = fork();
    if (pid == 0) {
        execve(path, cmd, env);
    } else
        waitpid(pid, &wstatus, 0);
    *stat = wstatus;
}

int do_or_stuff(char **env, tree_t *tree, char *cmd, env_t *list)
{
    tree_t *ls = tree;
    char **cmd_tab = NULL;
    char *path = NULL;
    static int stat = 1;

    if (!stat)
        return 0;
    if (cmd == NULL) {
        for (; ls->sep != NULL; ls = ls->right)
            do_or_stuff(\
            env, tree, ls->left->cmd == NULL ? "" : ls->left->cmd, list);
        do_or_stuff(env, tree, ls->cmd == NULL ? "" : ls->cmd, list);
        stat = 1;
        return 0;
    }
    if (strlen(cmd) == 0)
        return 0;
    cmd_tab = strsplit(cmd, " \t", false);
    path = get_path(list, cmd_tab);
    exe_or_stuff(env, cmd_tab, path, &stat);
    return 0;
}
