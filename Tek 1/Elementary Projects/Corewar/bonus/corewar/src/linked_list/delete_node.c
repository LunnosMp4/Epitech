/*
** EPITECH PROJECT, 2022
** LIB
** File description:
** delete_node.c
*/

#include "corewar.h"

void delete_node(lnk_list_t **head)
{
    lnk_list_t *tmp = *head;

    if (!(*head))
        return;
    if (!(*head)->next) {
        free(*head);
        *head = NULL;
        return;
    }
    while (tmp->next->next)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
}
