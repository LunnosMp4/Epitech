/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** event.h
*/

#ifndef EVENT_H_
    #define EVENT_H_
    #include "my_rpg.h"
    #include "linked_list.h"

typedef struct event_s {
    int damage;
    sfVector2f target;
    bool is_hit;
    TYPE type;
} event_t;

#endif /* EVENT_H_ */
