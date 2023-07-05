/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** delete_node.c
*/

#include "my_rpg.h"

void delete_node(lnk_list_t **node)
{
    lnk_list_t *tmp = *node;

    if (!tmp->next && !tmp->prev)
        return;
    *node = tmp->next;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
}
