/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** unsetenv.c
*/

#include "my_sh.h"

static void delete_node(env_t *newlist, env_t *tmp, char *key)
{
    while (newlist->next != NULL) {
        if (str_isequal(newlist->next->key, key, true)) {
            tmp = newlist->next;
            newlist->next = newlist->next->next;
            free(tmp);
            break;
        } else
            newlist = newlist->next;
    }
}

void search_node(char *key, env_t **list)
{
    env_t *tmp = NULL;

    if (str_isequal((*list)->key, key, true)) {
        tmp = *list;
        *list = (*list)->next;
        free(tmp);
    } else {
        env_t *newlist = *list;
        delete_node(newlist, tmp, key);
    }
}

void unset_env(char *line, env_t **list, UNUSED char **env)
{
    char **cmd = strsplit(line, "\t ", false);
    int len;

    for (len = 0; cmd[len]; len++);
    if (len < 2) {
        my_putstr("unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 1; cmd[i]; i++)
        search_node(cmd[i], list);
    p_ntty(HEADER, *list);
}
