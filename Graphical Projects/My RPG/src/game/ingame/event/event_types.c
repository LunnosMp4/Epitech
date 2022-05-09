/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** event_types.c
*/

#include "my_rpg.h"

void event_types(object_t *allie, event_t *event, lnk_list_t *list)
{
    object_t *enemy = (object_t *) list->data;
    sfVector2f penemy = sfSprite_getPosition(enemy->sprite);
    sfVector2f pallie = sfSprite_getPosition(allie->sprite);
    static float best_score = 0;
    float score = (penemy.x - pallie.x) + (penemy.y - pallie.y);

    score < 0 ? score = -score : 0;
    best_score < 0 ? best_score = -best_score : 0;
    if (event->target.x == -1 && event->target.y == -1) {
        event->target = penemy;
        event->is_hit = false;
        event->damage = 20;
        best_score = (penemy.x - pallie.x) + (penemy.y - pallie.y);
    }
    if (score < best_score) {
        event->target = penemy;
        event->is_hit = false;
        event->damage = 20;
        best_score = score;
    }
}
