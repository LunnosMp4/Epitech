/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** algo_fight.c
*/

#include "my_rpg.h"

static void check_alive(object_t *entity, game_t *game,
lnk_ltype_t *ltype)
{
    int top = 0;

    if (entity->utils.rect.top >= 128)
        top = 128;
    if (entity->stats->hp <= 0 && entity->utils.type == HEROES) {
        if (entity_in_area(ltype->chr, entity->pos, 300))
            ltype->dialog->active = true;
        entity->anim->rect.top = top;
        entity->anim->rect.left = entity->utils.rect.left + 96;
        sfSprite_setTextureRect(entity->sprite, entity->anim->rect);
    } else if (entity->stats->hp <= 0) {
        entity->anim->rect.top = top;
        entity->anim->rect.left = entity->utils.rect.left + 96;
        sfSprite_setTextureRect(entity->sprite, entity->anim->rect);
        sfSprite_setColor(entity->sprite,
        sfColor_fromRGBA(255, 255, 255, 255));
        entity->stats->hp = 1;
        entity->utils.type = DEAD;
        game->xp += 10;
    }
}

static void dodge_effects(object_t *entity, sfVector2f penemy,
sfVector2f pentity, game_t *game)
{
    if (entity_in_area(entity, penemy, 300) && rand() % 5)
        flee(entity, penemy, pentity, game);
}

void algo_fight(lnk_list_t *list, lnk_ltype_t *ltype, game_t *game)
{
    object_t *entity = (object_t *) list->data;

    if (entity_in_area(entity, entity->event->target, 32)
    && game->is_on_map == FRONT)
        hurt(entity);
    if (game->state == INGAME) {
        dodge_effects(entity, entity->event->target, entity->pos, game);
        set_entity_direction(entity, entity->pos);
        check_alive(entity, game, ltype);
    }
}
