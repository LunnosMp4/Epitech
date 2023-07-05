/*
** EPITECH PROJECT, 2022
** utils
** File description:
** add_node.c
*/

#include "graphic.h"

static void add_null_node(lnk_tlist_t **head,
lnk_tlist_t *newNode, void *data)
{
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = data;
    *head = newNode;
}

void add_type_node(void *data, lnk_tlist_t **head)
{
    lnk_tlist_t *newNode = malloc(sizeof(lnk_tlist_t));

    if (!(*head)) {
        add_null_node(head, newNode, data);
        return;
    }
    newNode->prev = *head;
    (*head)->next = newNode;
    newNode->next = NULL;
    newNode->data = data;
    *head = newNode;
}
