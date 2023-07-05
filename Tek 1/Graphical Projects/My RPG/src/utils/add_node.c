/*
** EPITECH PROJECT, 2022
** utils
** File description:
** add_node.c
*/

#include "my_rpg.h"

static void add_null_node(lnk_list_t **head,
lnk_list_t *newNode, void *data)
{
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = data;
    *head = newNode;
}

void add_node(void *data, lnk_list_t **head)
{
    lnk_list_t *newNode = malloc(sizeof(lnk_list_t));

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
