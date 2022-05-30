/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** check_commands.c
*/

#include "my_sh.h"

char *get_path(env_t *list, char **cmd)
{
    int i = 0;
    char **path = strsplit(find_env("PATH", list), ":", false);
    char *acs = NULL;

    if (!path)
        return NULL;
    acs = strcat_alloc(path[i++], "/");
    acs = strcat_alloc(acs, *cmd);
    while ((access(acs, X_OK)) != 0) {
        free(acs);
        if (!path[++i])
            return NULL;
        acs = strcat_alloc(path[i], "/");
        acs = strcat_alloc(acs, *cmd);
        if (!path[i])
            return NULL;
    }
    if (access(acs, X_OK) == -1)
        fprintf(stderr, "Permission denied\n");
    return acs;
}

static bool check_command(char *line, char ***cmd, char **path, env_t **list)
{
    int i = 0;

    for (; line[i] && (line[i] == ' ' || line[i] == '\t'); i++);
    if (!line[i]) {
        p_ntty(HEADER, *list);
        return false;
    }
    *cmd = strsplit(line, " \t", false);
    *path = get_path(*list, *cmd);
    return true;
}

static bool check_jobs(char ***cmd, char **path, env_t *list)
{
    static int i = 0;
    pid_t pid;
    *path = get_path(list, *cmd);
    printf("[%d] %d\n", i, getpid());
    pid = fork();
    if (pid == 0)
        execve(*path, *cmd, list->env_array);
    i++;
    return true;
}

bool check_line(char *line, char ***cmd, char **path, env_t **list)
{
    if (!check_command(line, &*cmd, &*path, list))
        return true;
    if (line[my_strlen(line) - 1] == '&' &&
    my_strlen(line) > 1 && line[my_strlen(line) - 2] != '&') {
        line[my_strlen(line) - 1] = '\0';
        *cmd = strsplit(line, " \t", false);
        if (check_jobs(&*cmd, &*path, *list))
            return true;
    }
    return false;
}
