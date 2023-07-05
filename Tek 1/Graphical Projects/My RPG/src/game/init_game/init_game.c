/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** create_game.c
*/

#include "my_rpg.h"

void create_view(game_t *game)
{
    game->player = sfView_create();
    sfView_setCenter(game->player, (sfVector2f) {3000 -
    RES / 2, 3000 - RES / 2});
    sfView_setSize(game->player, (sfVector2f) {WIDTH, HEIGHT});
    sfView_setViewport(game->player, (sfFloatRect) {0, 0, 1, 1});
    game->minimap = sfView_create();
    sfView_setSize(game->minimap, (sfVector2f) {WIDTH, HEIGHT});
    sfView_setViewport(game->minimap, (sfFloatRect) {0.80, 0.05, 0.25, 0.25});
}

static void create_game_2(game_t *game)
{
    sfImage *icon;

    game->clock = sfClock_create();
    game->change_weap = 1;
    game->direc_weap = 1;
    game->honney = false;
    game->xp = 0;
    create_sounds(game);
    icon = sfImage_createFromFile("assets/img/icon.png");
    sfRenderWindow_setIcon(game->window, 95, 95, sfImage_getPixelsPtr(icon));
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setVerticalSyncEnabled(game->window, sfTrue);
}

game_t *create_game(sfVideoMode mode, sfColor clear_color)
{
    game_t *game;

    game = malloc(sizeof(struct game));
    init_structure(game);
    game->quest = INTRO;
    create_view(game);
    game->window = sfRenderWindow_create(mode, "My RPG",
    sfResize | sfClose, NULL);
    game->state = MENU;
    game->state_change = false;
    game->clear_color = clear_color;
    game->is_on_map = UKR;
    game->clock = sfClock_create();
    create_game_2(game);
    return game;
}
