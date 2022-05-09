/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** anime_sprite.c
*/

#include "my_rpg.h"

static void go_down(sfIntRect org_rect, sfIntRect *rect, sfVector2f nbfrm)
{
    if (rect->top < rect->height * (nbfrm.y - 1) + org_rect.top)
        rect->top += rect->height;
    else
        rect->top = org_rect.top;
    rect->left = org_rect.left;
}

void anime_sprite(object_t *entity, sfVector2f nbfrm, float frame)
{
    entity->anim->seconds =
    get_seconds(entity->anim->clock, entity->anim->time);
    if (entity->anim->seconds > frame) {
        if (entity->anim->rect.left >= ENTW * (nbfrm.x - 1)
        + entity->utils.rect.left)
            go_down(entity->utils.rect, &entity->anim->rect, nbfrm);
        else
            entity->anim->rect.left += ENTW;
        sfSprite_setTextureRect(entity->sprite, entity->anim->rect);
        sfClock_restart(entity->anim->clock);
    }
}
