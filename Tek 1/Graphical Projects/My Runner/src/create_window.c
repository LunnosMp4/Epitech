/*
** EPITECH PROJECT, 2021
** Bootstrap MyRunner
** File description:
** create_window.c
*/

#include "../include/my_runner.h"
#include "../include/object.h"

void reset_movement(game_t *game);

game_t *create_game(sfVideoMode mode, game_t *game, sfColor clear_color)
{
    game->window = sfRenderWindow_create(mode, "My Runner", sfClose, NULL);
    sfWindow_setFramerateLimit(game->window, 60);
    game->clear_color = clear_color;
    return game;
}

void draw_game(game_t *game, object_t *object, fond_t *fond)
{
    if (game->score >= fond->max) {
        game->score = fond->max;
        draw_gamewin(game, object, fond);
        sfRenderWindow_clear(game->window, sfBlack);
    } else if (game->score <= 0) {
        game->score = 0;
        draw_gameloose(game, object, fond);
        sfRenderWindow_clear(game->window, sfBlack);
    } else
        draw_game2(game, object, fond);
}

void destroy_game(game_t *game, object_t *object, fond_t *fond)
{
    sfMusic_destroy(fond->MainMusic);
    sfMusic_destroy(game->jump);
    sfRenderWindow_destroy(game->window);
    sfText_destroy(game->text);
    sfSprite_destroy(fond->object1->sprite);
    sfSprite_destroy(fond->object0->sprite);
    sfSprite_destroy(fond->object2->sprite);
    sfSprite_destroy(fond->object3->sprite);
    sfSprite_destroy(fond->object4->sprite);
    sfSprite_destroy(fond->object5->sprite);
    sfSprite_destroy(fond->object6->sprite);
    sfSprite_destroy(fond->object7->sprite);
    sfSprite_destroy(fond->fox->sprite);
    sfSprite_destroy(fond->log->sprite);
    sfSprite_destroy(fond->log2->sprite);
    sfSprite_destroy(fond->object8->sprite);
    free(fond);
    free(object);
    free(game);
}

void game_pause(game_t *game, object_t *object, fond_t *fond)
{
    if (game->start != 1) {
        return;
    }
    if (game->pause == 1) {
        return;
    }
    if (game->score < fond->max && game->score > 0)
        game->score += 1;
    run_animations(game, object, fond);
    reset_movement(game);
}

void process_game(sfEvent event, game_t *game,
object_t *object, fond_t *fond)
{
    sfVector2f origin = {fond->nb, 450};
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &event)) {
            analyse_events(game, event, object, fond);
        }
        game_pause(game, object, fond);
        sfVector2f newpos = {game->x, game->y};
        sfSprite_setPosition(fond->fox->sprite, newpos);
        detect_collision(game, object, fond, origin);
    }
}