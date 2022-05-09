/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_
    #include "my_rpg.h"

typedef struct lnk_list_s {
    struct lnk_list_s *prev;
    struct lnk_list_s *next;
    void *data;
} lnk_list_t;

#endif /* LINKED_LIST_H_ */
