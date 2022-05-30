/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** print_alias.c
*/

#include "my_sh.h"

static void print_alias_name(char *key, char *value)
{
    char **words = strsplit(value, " \t", false);
    int len_words = 0;

    for (; words[len_words]; len_words++);
    if (len_words > 1)
        printf("%s\t(%s)\n", key, value);
    else
        printf("%s\t%s\n", key, value);
}

void exec_alias(env_t **list)
{
    env_t *tmp = *list;

    tmp = tmp->next;
    while (tmp) {
        if (tmp->id == ALIAS)
            print_alias_name(tmp->key, tmp->value);
        tmp = tmp->next;
    }
    p_ntty(HEADER, *list);
}
