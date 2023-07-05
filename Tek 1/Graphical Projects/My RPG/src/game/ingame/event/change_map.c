/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** change_map.c
*/

#include "my_rpg.h"

static void back_map(lnk_ltype_t *ltype, game_t *game)
{
    if (entity_in_area(ltype->chr, (sfVector2f) {0, 3200}, 100)
    && game->is_on_map == FRONT) {
        game->is_on_map = UKR;
        sfMusic_stop(game->music[MFIGHT]);
        sfMusic_play(game->music[MBASE]);
        sfSprite_setPosition(ltype->chr->sprite,
        (sfVector2f) {6290, sfSprite_getPosition(ltype->chr->sprite).y});
        sfSprite_setTexture(ltype->map->sprite, ltype->map_ukr, sfTrue);
        sfSprite_setTexture(ltype->ovcoat->sprite, ltype->ovcoat_ukr, sfTrue);
    }
    if (entity_in_area(ltype->chr, (sfVector2f) {0, 3200}, 100)
    && game->is_on_map == RUS) {
        game->is_on_map = FRONT;
        sfSprite_setPosition(ltype->chr->sprite,
        (sfVector2f) {6290, sfSprite_getPosition(ltype->chr->sprite).y});
        sfSprite_setTexture(ltype->map->sprite, ltype->warzone, sfTrue);
        sfSprite_setTexture(ltype->ovcoat->sprite, ltype->ovcoat_war, sfTrue);
    }
}

static void change_map_front(lnk_ltype_t *ltype, game_t *game)
{
    if (entity_in_area(ltype->chr, (sfVector2f) {6400, 3200}, 100)
    && game->is_on_map == UKR && game->quest == PARTI) {
        game->is_on_map = FRONT;
        sfMusic_stop(game->music[MBASE]);
        sfMusic_play(game->music[MFIGHT]);
        sfSprite_setPosition(ltype->chr->sprite,
        (sfVector2f) {200, sfSprite_getPosition(ltype->chr->sprite).y});
        sfSprite_setTexture(ltype->map->sprite, ltype->warzone, sfTrue);
        sfSprite_setTexture(ltype->ovcoat->sprite, ltype->ovcoat_war, sfTrue);
    }
}

static void change_map_rus(lnk_ltype_t *ltype, game_t *game)
{
    if (entity_in_area(ltype->chr, (sfVector2f) {6400, 3200}, 100)
    && game->is_on_map == FRONT) {
        game->is_on_map = RUS;
        sfSprite_setPosition(ltype->chr->sprite,
        (sfVector2f) {200, sfSprite_getPosition(ltype->chr->sprite).y});
        sfSprite_setTexture(ltype->map->sprite, ltype->map_russ, sfTrue);
        sfSprite_setTexture(ltype->ovcoat->sprite, ltype->ovcoat_russ, sfTrue);
    }
}

static void change_map_boss(lnk_ltype_t *ltype, game_t *game)
{
    if (entity_in_area(ltype->chr, (sfVector2f) {4585, 4475}, 100)
    && game->is_on_map == RUS) {
        game->is_on_map = BOSS;
        sfMusic_stop(game->music[MFIGHT]);
        sfMusic_play(game->music[MBOSS]);
        sfSprite_setPosition(ltype->chr->sprite,
        (sfVector2f) {3190, 3185});
        sfSprite_setPosition(ltype->poutine->sprite,
        (sfVector2f) {3185, 2540});
        sfSprite_setTexture(ltype->map->sprite, ltype->map_boss, sfTrue);
    }
}

void change_map(lnk_ltype_t *ltype, game_t *game)
{
    init_map_binary(game);
    back_map(ltype, game);
    change_map_front(ltype, game);
    change_map_rus(ltype, game);
    change_map_boss(ltype, game);
}
