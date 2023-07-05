/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** init_env.c
*/

#include "my_sh.h"

static void parse_env(char *env, env_t **list)
{
    char *key = malloc(sizeof(char) * (my_strlen(env) + 1));
    char *value = malloc(sizeof(char) * (my_strlen(env) + 1));
    int i = 0;
    int j = 0;

    for (; env[i] != '='; i++)
        key[i] = env[i];
    key[i++] = '\0';
    for (; env[i]; i++)
        value[j++] = env[i];
    value[j] = '\0';
    add_node_at_back(key, value, ENV, list);
}

env_t *init_env(char **env)
{
    env_t *list = malloc(sizeof(env_t));
    list->env_array = env;

    list->key = NULL;
    list->value = NULL;
    list->next = NULL;
    for (int i = 0; env[i]; i++)
        parse_env(env[i], &list);
    return list;
}
