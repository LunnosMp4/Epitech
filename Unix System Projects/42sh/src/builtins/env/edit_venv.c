/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** edit_env.c
*/

#include "my_sh.h"

void edit_venv(char *kenv, env_t **env, char *nwvenv)
{
    char *venv = malloc(sizeof(char) * 1024);
    env_t *tmp = *env;

    if (!venv) {
        fprintf(stderr, "Out of memory\n");
        exit(84);
    }
    while (tmp && !str_isequal(tmp->key, kenv, true))
        tmp = tmp->next;
    if (!tmp)
        return add_node_at_back(kenv, nwvenv, ENV, env);
    tmp->value = my_strdup(nwvenv);
}
