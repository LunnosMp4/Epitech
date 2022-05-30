/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** add_node_env.c
*/

#include "my_sh.h"

void add_node_at_back(char *key, char *value, int id, env_t **node)
{
    env_t *newNode = malloc(sizeof(env_t));
    env_t *lastNode = NULL;

    newNode->key = key;
    newNode->value = value;
    newNode->id = id;
    newNode->next = NULL;
    if (*node == NULL)
        *node = newNode;
    else {
        lastNode = *node;
        while (lastNode->next)
            lastNode = lastNode->next;
        lastNode->next = newNode;
    }
}
