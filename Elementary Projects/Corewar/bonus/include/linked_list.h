/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_
    #include "graphic.h"

typedef struct lnk_tlist_s {
    struct lnk_tlist_s *prev;
    struct lnk_tlist_s *next;
    void *data;
} lnk_tlist_t;

#endif /* LINKED_LIST_H_ */
