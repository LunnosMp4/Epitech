/*
** EPITECH PROJECT, 2022
** utils
** File description:
** process_ltype.c
*/

#include "my_rpg.h"

void process_ltype(game_t *game, lnk_ltype_t ltype, lnk_list_t **list,
void (*pointer)(game_t *, lnk_ltype_t *, lnk_list_t *))
{
    lnk_list_t *tmp = *list;

    while (tmp) {
        pointer(game, &ltype, tmp);
        tmp = tmp->prev;
    }
}

void process_lmenu(game_t *game, menu_t *menu, lnk_list_t *list,
void (*pointer)(game_t *, menu_t *, lnk_list_t *))
{
    while (list) {
        pointer(game, menu, list);
        list = list->prev;
    }
}

void process_list(game_t *game, lnk_list_t *list,
void (*pointer)(game_t *, lnk_list_t *))
{
    while (list) {
        pointer(game, list);
        list = list->prev;
    }
}
