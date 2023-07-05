/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-enzo.daumalle
** File description:
** exec.c
*/

#include "my_sh.h"

void exec_pipe(builtin_t *builtin, tree_t *tree, env_t *list, char **env)
{
    pid_t pid;
    int fd[2];

    pid = fork();
    if (pid == -1)
        return;
    if (!pid) {
        if (pipe(fd) == -1) {
            perror("pipe");
            exit(84);
        }
        tree->right->fd[IN] = fd[IN];
        tree->left->fd[OUT] = fd[OUT];
        exec_tree(builtin, list, env, tree->left);
        exec_tree(builtin, list, env, tree->right);
        closefd(fd);
        exit(0);
    }
    p_ntty(HEADER, list);
}

static void exe_and_stuff(char **env, char **cmd, char *path, int *stat)
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

static int do_and_stuff(char **env, tree_t *tree, char *cmd, env_t *list)
{
    tree_t *ls = tree;
    char **cmd_tab = NULL;
    char *path = NULL;
    static int stat = 0;
    if (stat)
        return 0;
    if (cmd == NULL) {
        for (; ls->sep != NULL; ls = ls->right)
            do_and_stuff(\
            env, tree, ls->left->cmd == NULL ? "" : ls->left->cmd, list);
        do_and_stuff(env, tree, ls->cmd == NULL ? "" : ls->cmd, list);
        stat = 0;
        return 0;
    }
    if (strlen(cmd) == 0)
        return 0;
    cmd_tab = strsplit(cmd, " \t", false);
    path = get_path(list, cmd_tab);
    exe_and_stuff(env, cmd_tab, path, &stat);
    return 0;
}

static void globbs(tree_t *tree, env_t *list)
{
    if (str_isequal(tree->sep, "*", true) || str_isequal(tree->sep, "?", true)
    || str_isequal(tree->sep, "[", true) || str_isequal(tree->sep, "]", 1)) {
        my_globbing(tree->cmd, list);
        return;
    }
    if (tree->sep)
        redirection(tree);
}

void exec_tree(builtin_t *builtin, env_t *list, char **env, tree_t *tree)
{
    if (!tree)
        return;
    if (str_isequal(tree->sep, "|", true))
        return exec_pipe(builtin, tree, list, env);
    if (str_isequal(tree->sep, "&&", true))
        return do_and_stuff(env, tree, NULL, list) ? 0 : p_ntty(HEADER, list);
    if (str_isequal(tree->sep, "||", true))
        return do_or_stuff(env, tree, NULL, list) ? 0 : p_ntty(HEADER, list);
    globbs(tree, list);
    if (!tree->sep && tree->cmd) {
        tree->cmd = get_alias(list, tree->cmd);
        if (!(builtin = get_builtin(tree->cmd)))
            return exec_binary(&list, env, *tree);
        (*(builtin->fptr))(tree->cmd, &list, env);
        return;
    }
    exec_tree(builtin, list, env, tree->left);
    if (tree->sep[0] != '<' && tree->sep[0] != '>')
        exec_tree(builtin, list, env, tree->right);
}
