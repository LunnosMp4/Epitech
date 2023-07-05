/*
** EPITECH PROJECT, 2022
** LIB
** File description:
** add_node.c
*/

#include "corewar.h"

void add_node(champion_t *champ, lnk_list_t **head)
{
    lnk_list_t *new_node = malloc(sizeof(lnk_list_t));
    lnk_list_t *tmp = *head;

    new_node->champ = champ;
    new_node->next = NULL;
    if (!(*head)) {
        *head = new_node;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
}
