/*
** EPITECH PROJECT, 2022
** utils
** File description:
** process_list.c
*/

#include "graphic.h"

void process_list(game_t *game, type_t *type, lnk_tlist_t **list,
void (*pointer)(game_t *, type_t *, lnk_tlist_t *))
{
    lnk_tlist_t *tmp = *list;

    while (tmp) {
        pointer(game, type, tmp);
        tmp = tmp->prev;
    }
}
