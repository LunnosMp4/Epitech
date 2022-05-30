/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** exec.c
*/

#include "my_sh.h"

static void wait_exec(int state, env_t **list)
{
    wait(&state);
    if (WIFSIGNALED(state))
        sign_handler(state);
    p_ntty(HEADER, *list);
}

static void apply_inhibitors(char **cmd)
{
    for (int i = 0; cmd[i] != NULL; i++)
        cmd[i] = process_inhibitors(cmd[i]);
}

void exec_binary(env_t **list, char **env, tree_t leaf)
{
    int state = 0;
    char **cmd = NULL;
    char *path = NULL;

    if (check_line(leaf.cmd, &cmd, &path, list))
        return;
    apply_inhibitors(cmd);
    if (!fork()) {
        dup2(leaf.fd[IN], STDIN_FILENO);
        dup2(leaf.fd[OUT], STDOUT_FILENO);
        state = execve(cmd[0], cmd, env);
        closefd(leaf.fd);
        if (state == -1 && path)
            state = execve(path, cmd, env);
        if (state == -1) {
            fprintf(stderr, "%s: Command not found.\n", cmd[0]);
            exit(0);
        }
    } else
        wait_exec(state, list);
}
