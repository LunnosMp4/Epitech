/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** find_env.c
*/

#include "my_sh.h"

char *find_env(char *kenv, env_t *env)
{
    while (env) {
        if (str_isequal(env->key, kenv, true) && env->id == ENV)
            break;
        env = env->next;
    }
    if (!env)
        return NULL;
    return my_strdup(env->value);
}
