/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** env.c
*/

#include "my_sh.h"

void exec_env(UNUSED char *line, env_t **list, UNUSED char **env)
{
    env_t *tmp = *list;

    tmp = tmp->next;
    while (tmp) {
        if (tmp->id == ENV)
            printf("%s=%s\n", tmp->key, tmp->value);
        tmp = tmp->next;
    }
    p_ntty(HEADER, *list);
}
