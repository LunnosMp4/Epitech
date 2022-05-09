/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** init_structure.c
*/

#include "my_rpg.h"

static sfRectangleShape *create_progress_bar(sfColor color,
sfVector2f size)
{
    sfRectangleShape *progress_bar = sfRectangleShape_create();

    sfRectangleShape_setFillColor(progress_bar, color);
    sfRectangleShape_setSize(progress_bar, size);
    return progress_bar;
}

void init_structure(game_t *game)
{
    game->progress_bar = malloc(sizeof(struct progress_bar));
    game->progress_bar->effect = malloc(sizeof(struct effect));
    game->progress_bar->weather = malloc(sizeof(struct weather));
    game->progress_bar->health = create_progress_bar(sfRed,
    (sfVector2f) {100 * 3, 32});
    game->progress_bar->xp = create_progress_bar(sfGreen,
    (sfVector2f) {100 * 2.25, 25});
    game->progress_bar->weather->cycle = 10;
    game->progress_bar->weather->day = true;
    game->progress_bar->weather->clock = sfClock_create();
    game->progress_bar->weather->brightness = create_progress_bar(
    sfColor_fromRGBA(0, 0, 0, game->progress_bar->weather->cycle),
    (sfVector2f) {WIDTH, HEIGHT});
    game->progress_bar->weather->min = rand() % (60 - 10) + 10;
    game->progress_bar->weather->max = rand() % (180 - 80) + 80;
    game->progress_bar->effect->is_bombing = false;
    game->progress_bar->effect->clock = sfClock_create();
    game->progress_bar->effect->clock_bomb = sfClock_create();
}
