/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** allies.c
*/

#include "my_rpg.h"

static void refresh_info(object_t *entity, lnk_ltype_t *ltype,
lnk_list_t *target)
{
    lnk_list_t *effects = &(*ltype->effects);

    entity->pos = sfSprite_getPosition(entity->sprite);
    entity->event->target = (sfVector2f) {-1, -1};
    for (; effects; effects = effects->prev)
        event_types(entity, entity->event, effects);
    for (; target; target = target->prev)
        event_types(entity, entity->event, target);
}

void process_enemies(game_t *game, lnk_ltype_t *ltype, lnk_list_t *list)
{
    object_t *enemy = (object_t *) list->data;
    lnk_list_t *allies = &(*ltype->allies);

    if (enemy->utils.type == DEAD) {
        sfRenderWindow_drawSprite(game->window, enemy->sprite, NULL);
        return;
    }
    if (enemy->utils.type == INVISIBLE)
        return;
    refresh_info(enemy, ltype, allies);
    if (entity_in_area(enemy, ltype->chr->pos, 200)
    && enemy->utils.type == HEROES)
        flee(enemy, ltype->chr->pos, enemy->pos, game);
    if (entity_in_area(enemy, ltype->chr->pos, 250)
    && enemy->utils.type == ENEMY)
        flee(enemy, ltype->chr->pos, enemy->pos, game);
    if (entity_in_area(enemy, ltype->chr->pos, 500)
    && enemy->utils.type != DEAD && game->state == INGAME)
        follow(enemy, ltype->chr->pos, enemy->pos, game);
    algo_fight(list, ltype, game);
    set_entity_direction(enemy, enemy->pos);
    if (game->is_on_map == FRONT || game->is_on_map == RUS) {
        sfRenderWindow_drawSprite(game->window, enemy->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, enemy->weapon->sprite, NULL);
    }
}

void process_allies(game_t *game, lnk_ltype_t *ltype, lnk_list_t *list)
{
    object_t *allie = (object_t *) list->data;
    sfVector2f move = {2, 0};
    lnk_list_t *enemies = &(*ltype->enemy);

    if (allie->utils.type == INVISIBLE)
        return;
    refresh_info(allie, ltype, enemies);
    if (allie->utils.type == ALLIES && game->state == INGAME)
        limited_move(allie, move, game);
    algo_fight(list, ltype, game);
    sfRenderWindow_drawSprite(game->window, allie->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, allie->weapon->sprite, NULL);
}

void process_chr(game_t *game, object_t *chr, lnk_ltype_t *ltype)
{
    lnk_list_t *enemies = &(*ltype->enemy);

    chr->pos = sfSprite_getPosition(ltype->chr->sprite);
    chr->event->target = (sfVector2f) {-1, -1};
    for (; enemies; enemies = enemies->prev)
        event_types(chr, chr->event, enemies);
    chr->event->damage = 3;
    if ((entity_in_area(ltype->chr, ltype->chr->event->target, 300)
    || entity_in_area(ltype->chr, ltype->poutine->pos, 200))
    && game->state == INGAME)
        hurt(ltype->chr);
    if (chr->stats->hp <= 0 && game->state == INGAME)
        game->state = GAME_OVER;
    if (game->state == INGAME)
        on_move_player(game, chr);
    game->entity = sfSprite_getPosition(chr->sprite);
    sfRenderWindow_drawSprite(game->window, chr->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, chr->weapon->sprite, NULL);
}
