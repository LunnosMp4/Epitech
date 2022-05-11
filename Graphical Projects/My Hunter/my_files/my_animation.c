/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-loic.tisseyre
** File description:
** my_animation.c
*/

#include "../include/my_structures.h"

void duck_speed(game_t *game);
void duck_rev_speed(game_t *game);

void run_animation(animation_t *animation, game_t *game, \
entity_t *entity, sfVector2f movex)
{
    animation->time = sfClock_getElapsedTime(animation->clock);
    game->seconds = animation->time.microseconds / 200000.0;
    if (game->seconds > 0.5) {
        if (animation->rect.left == 220)
            animation->rect.left = 0;
        else
            animation->rect.left = animation->rect.left + 110;
        sfSprite_setTextureRect(entity->sprite, animation->rect);
        sfClock_restart(animation->clock);
        sfSprite_move(entity->sprite, movex);
    }
}

void blood_explosion(animation_t *animation, game_t *game, entity_t *entity)
{
    animation->time2 = sfClock_getElapsedTime(animation->clock);
    game->seconds2 = animation->time2.microseconds / 200000.0;
    if (game->seconds2 > 0.5) {
        if (animation->rect2.left == 1280)
            animation->rect2.left = 0;
        else
            animation->rect2.left = animation->rect2.left + 256;
    sfSprite_setTextureRect(entity->blood, animation->rect2);
    sfClock_restart(animation->clock2);
    }
}

void sinusoidal_movement(entity_t *entity , game_t *game)
{
    int num = (rand() % (2 - 1 + 1)) + 1;
    sfVector2f movey;
    if (num == 1) {
        sfVector2f movey = {0, 2};
    } else {
        sfVector2f movey = {0, -2};
    }
    sfSprite_move(entity->sprite, movey);
    sfRenderWindow_drawSprite(game->window, entity->sprite, NULL);
}

void is_dead(game_t *game, entity_t *entity, animation_t *animation)
{
    int gposx = sfSprite_getPosition(entity->sprite).x;
    if (gposx < -170 || gposx > 900) {
        sfRenderWindow_drawSprite(game->window, entity->blood, NULL);
    }

}

void reverse_duck(game_t *game, entity_t *entity)
{
    int gposx = sfSprite_getPosition(entity->cursor).x;
    int gposy = sfSprite_getPosition(entity->cursor).y;
    int num = (rand() % (550 - 100 + 1)) + 100;
    sfVector2f back = {-200, num};
    sfVector2f end = {930, num};
    sfVector2f tp = {gposx - 80, gposy - 80};
    int rdm = (rand() % (2 - 1 + 1)) + 1;
    if (rdm == 1) {
        sfSprite_setPosition(entity->blood, tp);
        sfVector2f flip = {-1, 1};
        sfSprite_setScale(entity->sprite, flip);
        duck_rev_speed(game);
        sfSprite_setPosition(entity->sprite, end);
    } else if (rdm == 2) {
        sfSprite_setPosition(entity->blood, tp);
        sfVector2f flip = {1, 1};
        sfSprite_setScale(entity->sprite, flip);
        duck_speed(game);
        sfSprite_setPosition(entity->sprite, back);
    }
}