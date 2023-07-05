/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** pwd.c
*/

#include "my_sh.h"

void exec_pwd(UNUSED char *line, env_t **list, UNUSED char **env)
{
    char *pwd = find_env("PWD", *list);
    char *newpwd = malloc(sizeof(char) * 1024);

    if (!pwd) {
        edit_venv("PWD", list, getcwd(newpwd, 1024));
        pwd = find_env("PWD", *list);
    }
    printf("%s\n", pwd);
    p_ntty(HEADER, *list);
}
