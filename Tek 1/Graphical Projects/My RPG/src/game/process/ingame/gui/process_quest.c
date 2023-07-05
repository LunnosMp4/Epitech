/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** process_quest.c
*/

#include "my_rpg.h"

void process_quest_prologue(game_t *game,
object_t *object, sfVector2f min)
{
    static int animation = 0;

    if (animation >= 255)
        animation = 255;
    if (object->utils.type == QUEST_1) {
        min = (sfVector2f)
        {(sfView_getCenter(game->player).x + WIDTH / 2 - 268),
        sfView_getCenter(game->player).y - HEIGHT / 2 + 250};
        sfSprite_setPosition(object->sprite, min);
        sfSprite_setScale(object->sprite, (sfVector2f) {0.5, 0.5});
        if (game->quest == PROLII || game->quest == PARTI || game->quest == PARTII) {
            sfSprite_setColor(object->sprite, sfColor_fromRGBA(255, 255, 255,
            animation++));
            sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
        }
    }
}

void process_quest_miel(game_t *game,
object_t *object, sfVector2f min)
{
    static int animation = 0;

    if (animation >= 255)
        animation = 255;
    if (object->utils.type == QUEST_2) {
        min = (sfVector2f)
        {(sfView_getCenter(game->player).x + WIDTH / 2 - 268),
        sfView_getCenter(game->player).y - HEIGHT / 2 + 350};
        sfSprite_setPosition(object->sprite, min);
        sfSprite_setScale(object->sprite, (sfVector2f) {0.5, 0.5});
        if (game->quest == PARTI || game->quest == PARTII) {
            sfSprite_setColor(object->sprite, sfColor_fromRGBA(255, 255, 255,
            animation++));
            sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
        }
    }
}

