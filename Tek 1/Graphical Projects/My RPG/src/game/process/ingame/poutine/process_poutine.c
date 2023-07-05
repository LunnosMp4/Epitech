/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** process_poutine.c
*/

#include "my_rpg.h"

static void process_next_poutine(game_t *game, lnk_ltype_t *ltype)
{
    if (ltype->poutine->stats->hp <= 0 && game->state == INGAME) {
        sfSprite_setPosition(ltype->poutine->sprite, (sfVector2f){-100, -100});
        game->state = WIN;
    }
    if (entity_in_area(ltype->poutine, ltype->chr->pos, 100))
        flee(ltype->poutine, ltype->chr->pos, ltype->poutine->pos, game);
    if (entity_in_area(ltype->poutine, ltype->chr->pos, 800))
        follow(ltype->poutine, ltype->chr->pos, ltype->poutine->pos, game);
    set_poutine_direction(ltype->poutine, ltype->poutine->pos);
    sfRenderWindow_drawSprite(game->window, ltype->poutine->sprite, NULL);
}

static void change_sprite(game_t *game, lnk_ltype_t *ltype)
{
    ltype->poutine->utils.rect = (sfIntRect) {752, 0, 63, 64};
    ltype->poutine->anim->rect = (sfIntRect) {752, 0, 63, 64};
    sfSprite_setScale(ltype->poutine->sprite, (sfVector2f) {3, 3});
    sfSound_play(game->sounds[ROAR]);
}

static int take_damage(game_t *game)
{
    int damage = 20;

    if (game->honney == true)
        damage = 60;
    return damage;
}

static void honey_dialog(game_t *game, lnk_ltype_t *ltype)
{
    if (game->honney) {
        game->honney = false;
        dialog_event(game, ltype, "MielPops");
    }
}

void process_poutine(game_t *game, lnk_ltype_t *ltype)
{
    lnk_list_t *effects = &(*ltype->effects);
    static bool roar = true;
    static int hbox = 32;
    int damage = take_damage(game);
    ltype->poutine->pos = sfSprite_getPosition(ltype->poutine->sprite);
    ltype->poutine->event->target = (sfVector2f) {-1, -1};
    if (ltype->poutine->stats->hp <= 4000 && game->state == INGAME) {
        if (roar) {
            roar = false;
            hbox = 192;
            honey_dialog(game, ltype);
            change_sprite(game, ltype);
        }
    }
    for (; effects; effects = effects->prev)
        event_types(ltype->poutine, ltype->poutine->event, effects);
    if (entity_in_area(ltype->poutine, ltype->poutine->event->target, hbox)) {
        ltype->poutine->stats->hp -= damage;
        hurt(ltype->poutine);
    }
    process_next_poutine(game, ltype);
}
