/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** move_player.c
*/

#include "my_rpg.h"

static void set_direction_x(game_t *game, object_t *entity, sfVector2f move)
{
    int top = 0;
    sfVector2f pos = sfSprite_getPosition(entity->sprite);

    if (entity->utils.rect.top >= 128)
        top = 128;
    if (move.x > 0) {
        entity->utils.rect.top = 64 + top;
        entity->anim->rect.top = 64 + top;
        weapon_direction_x(game, entity, pos);
    } else if (move.x < 0) {
        entity->utils.rect.top = 32 + top;
        entity->anim->rect.top = 32 + top;
        weapon_direction_x2(game, entity, pos);
    }
    sfSprite_setTextureRect(entity->weapon->sprite,
    entity->weapon->utils.rect);
}

static void set_direction_y(game_t *game, object_t *entity, sfVector2f move)
{
    int top = 0;
    sfVector2f pos = sfSprite_getPosition(entity->sprite);

    if (entity->utils.rect.top >= 128)
        top = 128;
    if (move.y > 0) {
        entity->utils.rect.top = 0 + top;
        entity->anim->rect.top = 0 + top;
        entity->weapon->utils.rect = (sfIntRect) {900, 0, 28, 15};
        weapon_direction_y(game, entity, pos);
    } else if (move.y < 0) {
        entity->utils.rect.top = 96 + top;
        entity->anim->rect.top = 96 + top;
        entity->weapon->utils.rect = (sfIntRect) {2000, 0, 28, 15};
    }
    sfSprite_setTextureRect(entity->weapon->sprite,
    entity->weapon->utils.rect);
}

static void set_direction(game_t *game, object_t *entity, sfVector2f move)
{
    set_direction_y(game, entity, move);
    set_direction_x(game, entity, move);
    if (move.x != 0 || move.y != 0)
        anime_sprite(entity, (sfVector2f) {2, 1}, 0.2);
    else {
        entity->anim->rect.left = entity->utils.rect.left + 64;
        sfSprite_setTextureRect(entity->sprite, entity->anim->rect);
    }
}

static void view_player(game_t *game, object_t *entity)
{
    sfVector2f pos_ent = sfSprite_getPosition(entity->sprite);

    if (pos_ent.x < WIDTH / 2)
        pos_ent.x = WIDTH / 2;
    else if (pos_ent.x > 6400 - WIDTH / 2)
        pos_ent.x = 6400 - WIDTH / 2;
    if (pos_ent.y < HEIGHT / 2)
        pos_ent.y = HEIGHT / 2;
    else if (pos_ent.y > 6400 - HEIGHT / 2)
        pos_ent.y = 6400 - HEIGHT / 2;
    sfView_setCenter(game->player, pos_ent);
    sfView_setCenter(game->minimap, pos_ent);
}

void on_move_player(game_t *game, object_t *entity)
{
    sfVector2f move = {0, 0};
    float speed = 0;

    if (entity->utils.type != CHR)
        return;
    speed = entity->stats->speed;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        move.x = -speed;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        move.x = speed;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        move.y = -speed;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        move.y = speed;
    set_direction(game, entity, move);
    view_player(game, entity);
    limited_move(entity, move, game);
}
