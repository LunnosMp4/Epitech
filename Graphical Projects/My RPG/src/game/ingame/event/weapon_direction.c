/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** weapon_direction.c
*/

#include "my_rpg.h"

void weapon_direction_x(game_t *game, object_t *entity, sfVector2f pos)
{
    switch (game->direc_weap) {
        case 1: entity->weapon->utils.rect = (sfIntRect) {668, 0, 25, 15};
            break;
        case 2: entity->weapon->utils.rect = (sfIntRect) {692, 47, 25, 25};
            break;
        case 3: entity->weapon->utils.rect = (sfIntRect) {720, 32, 25, 13};
            break;
        default: break;
    }
    sfSprite_setPosition(entity->weapon->sprite,
    (sfVector2f) {pos.x + 20, pos.y + 14});
}

void weapon_direction_x2(game_t *game, object_t *entity, sfVector2f pos)
{
    switch (game->direc_weap) {
        case 1: entity->weapon->utils.rect = (sfIntRect) {707, 180, 28, 15};
            break;
        case 2: entity->weapon->utils.rect = (sfIntRect) {674, 226, 28, 25};
            break;
        case 3: entity->weapon->utils.rect = (sfIntRect) {645, 212, 25, 12};
            break;
        default: break;
    }
    sfSprite_setPosition(entity->weapon->sprite,
    (sfVector2f) {pos.x - 5, pos.y + 12});
}

void weapon_direction_y(game_t *game, object_t *entity, sfVector2f pos)
{
    switch (game->direc_weap) {
        case 1: entity->weapon->utils.rect = (sfIntRect) {689, 99, 9, 16};
            break;
        case 2: entity->weapon->utils.rect = (sfIntRect) {643, 122, 10, 27};
            break;
        case 3: entity->weapon->utils.rect = (sfIntRect) {660, 151, 6, 25};
            break;
        default: break;
    }
    sfSprite_setPosition(entity->weapon->sprite,
    (sfVector2f) {pos.x + 3, pos.y + 20});
}
