/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-loic.tisseyre
** File description:
** my_events.c
*/

#include "../include/my_structures.h"

sfBool collision2(game_t *game, entity_t *entity);

void time_of_explosion(animation_t *animation, game_t *game, entity_t *entity);

void reverse_duck(game_t *game, entity_t *entity);

int analyse_events(game_t *game, sfEvent event,
entity_t *entity, animation_t *animation)
{
    if (event.type == sfEvtMouseButtonPressed &&
    event.key.code == sfMouseLeft) {
        manage_mouse_click(game, entity, animation);
    }
    if (event.type == sfEvtClosed || event.type ==
    sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        close_window(game->window);
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    return 0;
}

sfBool collision(game_t *game, entity_t *entity)
{
    int pos_entity1x = sfMouse_getPosition(game->window).x;
    int pos_entity1y = sfMouse_getPosition(game->window).y;
    int pos_entity2x = sfSprite_getPosition(entity->sprite).x;
    int pos_entity2y = sfSprite_getPosition(entity->sprite).y;

    if ((pos_entity1x >= pos_entity2x && pos_entity1x <= pos_entity2x + 100)
    && (pos_entity1y >= pos_entity2y && pos_entity1y <= pos_entity2y + 100))
        return sfTrue;
    else
        return sfFalse;
}

int manage_mouse_click(game_t *game, entity_t *entity, animation_t *animation)
{
    sfMusic_setVolume(game->blood, 70);
    sfMusic_play(game->gun);
    sfVector2f out = {-1100, -1000};
    if (collision(game, entity) == sfTrue ||
    collision2(game, entity) == sfTrue) {
        game->score += 1;
        reverse_duck(game, entity);
        sfMusic_play(game->blood);
    } else {
        game->loose -= 1;
    }
    return 0;
}

void my_crosshair(game_t *game, entity_t *entity)
{
    int posx = sfMouse_getPositionRenderWindow(game->window).x;
    int posy = sfMouse_getPositionRenderWindow(game->window).y;
    sfWindow_setMouseCursorVisible(game->window, sfFalse);
    sfVector2f aimpos = {posx - 35, posy - 35};
    sfSprite_setPosition(entity->cursor, aimpos);
}

void set_spawn(sfRenderWindow *window, entity_t *entity, game_t *game)
{
    int num = (rand() % (550 - 100 + 1)) + 100;
    sfVector2f out = {-1000, -1000};
    sfVector2f base = {-169, num};
    int gposx = sfSprite_getPosition(entity->sprite).x;
    if (gposx > 950 || gposx < -210) {
        sfVector2f flip = {1, 1};
        sfSprite_setScale(entity->sprite, flip);
        game->speed = game->speed + 1;
        sfSprite_setPosition(entity->sprite, base);
    }
}