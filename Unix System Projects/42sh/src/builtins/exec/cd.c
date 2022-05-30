/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** cd.c
*/

#include "my_sh.h"

static void update_pwd(env_t **list, char *old_pwd)
{
    char *pwd = malloc(sizeof(char) * 1024);

    if (!pwd) {
        fprintf(stderr, "Out of memory\n");
        exit(0);
    }
    edit_venv("OLDPWD", list, old_pwd);
    edit_venv("PWD", list, getcwd(pwd, 1024));
}

static void cd_path(char *fenv, char **cmd, env_t **list)
{
    char old_pwd[1024];

    if (!fenv) {
        fprintf(stderr, "cd: Command not found.\n");
        return;
    }
    getcwd(old_pwd, sizeof(old_pwd));
    if (chdir(fenv) != -1) {
        update_pwd(list, old_pwd);
        return;
    }
    if (chdir(cmd[1]) == -1) {
        fprintf(stderr, "%s : %s.\n", cmd[1], strerror(errno));
        return;
    }
    update_pwd(list, old_pwd);
}

static void cd_list(char **cmd, env_t **list)
{
    char *fenv = malloc(sizeof(char) * 1024);
    char *kenv = NULL;

    if (!cmd[1] || str_isequal(cmd[1], "~", true))
        kenv = "HOME";
    if (str_isequal(cmd[1], "-", true))
        kenv = "OLDPWD";
    if (kenv)
        fenv = find_env(kenv, *list);
    cd_path(fenv, cmd, list);
}

void exec_cd(char *line, env_t **list, UNUSED char **env)
{
    char **cmd = strsplit(line, " \t", false);
    int len_cmd = 0;

    for (len_cmd = 0; cmd[len_cmd]; len_cmd++);
    if (len_cmd > 2) {
        fprintf(stderr, "cd: Too many arguments.\n");
        p_ntty(HEADER, *list);
        return;
    }
    cd_list(cmd, list);
    p_ntty(HEADER, *list);
}
