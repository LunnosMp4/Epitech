/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** interface_wpn.c
*/

#include "my_rpg.h"

static void process_profile(game_t *game, object_t *object)
{
    if (object->utils.type == IMG) {
        sfVector2f min = {(sfView_getCenter(game->player).x - WIDTH / 2 + 20),
        sfView_getCenter(game->player).y +
        HEIGHT / 2 - object->utils.rect.height - 12};
        sfSprite_setPosition(object->sprite, min);
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    }
}

static void use_honey(game_t *game, object_t *object, sfVector2f min)
{
    if (!game->honney && game->is_on_map == FRONT)
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    if (game->honney) {
        min = (sfVector2f)
        {(sfView_getCenter(game->player).x + WIDTH / 2 - 68),
        sfView_getCenter(game->player).y + HEIGHT / 2 - 180};
        sfSprite_setPosition(object->sprite, min);
        sfSprite_setScale(object->sprite, (sfVector2f) {2.5, 2.5});
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    }
}

static void process_interface_health(game_t *game, object_t *object)
{
    sfVector2f min;

    if (object->utils.type == HEALTH) {
        min =
        (sfVector2f) {(sfView_getCenter(game->player).x + WIDTH / 2 - 150),
        sfView_getCenter(game->player).y + HEIGHT / 2 - 140};
        sfSprite_setPosition(object->sprite, min);
        sfSprite_setScale(object->sprite, (sfVector2f) {2.5, 2.5});
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    }
    if (object->utils.type == HEALTH_RD)
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    if (object->utils.type == HONEY) {
        use_honey(game, object, min);
    }
}

static void process_interface_wpn(game_t *game, object_t *object)
{
    if (object->utils.type == WPN) {
        sfVector2f min = {(sfView_getCenter(game->player).x + WIDTH / 2 - 208),
        sfView_getCenter(game->player).y + HEIGHT / 2 - 60};
        sfSprite_setPosition(object->sprite, min);
        sfSprite_setScale(object->sprite, (sfVector2f) {2.5, 2.5});
        switch (game->direc_weap) {
            case 1: object->utils.rect = (sfIntRect) {668, 0, 25, 15};
                break;
            case 2: object->utils.rect = (sfIntRect) {692, 47, 25, 15};
                break;
            case 3: object->utils.rect = (sfIntRect) {720, 32, 25, 12};
                break;
            default: break;
        }
        sfSprite_setTextureRect(object->sprite, object->utils.rect);
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    }
    if (object->utils.type == NPC && game->quest == PROLI)
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    process_profile(game, object);
    process_interface_health(game, object);
}

void process_interface_popup(game_t *game,
object_t *object)
{
    sfVector2f min;

    process_inv_popup(game, object, min);
    process_quest_prologue(game, object, min);
    process_quest_miel(game, object, min);
    if (object->utils.type == NPC && game->quest == PROLI &&
    game->is_on_map == UKR)
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    process_interface_wpn(game, object);
}
