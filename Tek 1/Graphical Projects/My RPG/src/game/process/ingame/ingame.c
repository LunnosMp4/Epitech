/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** ingame.c
*/

#include "my_rpg.h"

void process_rain(game_t *game, lnk_list_t *list)
{
    particles_t *particles = (particles_t *) list->data;

    if (game->state != PAUSE)
        sfRectangleShape_move(particles->shape, (sfVector2f) {0, 8});
    if (sfRectangleShape_getPosition(particles->shape).y > 6400)
        sfRectangleShape_setPosition(particles->shape, (sfVector2f)
        {sfRectangleShape_getPosition(particles->shape).x,
        sfRectangleShape_getPosition(particles->shape).y - 6400});
    if (game->progress_bar->weather->cycle >= game->progress_bar->weather->min
    && game->progress_bar->weather->cycle <= game->progress_bar->weather->max)
        sfRenderWindow_drawRectangleShape(game->window, particles->shape,
        NULL);
}

static void change_weap(game_t *game, lnk_ltype_t *ltype, object_t *object)
{
    sfVector2f player_pos = sfSprite_getPosition(ltype->chr->sprite);

    if (game->change_weap == 1) {
        object->weapon = create_object((utils_t) {{668, 0, 25, 15},
        {player_pos.x, player_pos.y}, GLOCK}, NULL, ltype->entities);
        game->direc_weap = 1;
        game->change_weap = 0;
    }
    if (game->change_weap == 2) {
        object->weapon = create_object((utils_t) {{692, 47, 25, 15},
        {player_pos.x, player_pos.y}, AK47}, NULL, ltype->entities);
        game->direc_weap = 2;
        game->change_weap = 0;
    }
    if (game->change_weap == 3) {
        object->weapon = create_object((utils_t) {{720, 32, 25, 15},
        {player_pos.x, player_pos.y}, SNIPER}, NULL, ltype->entities);
        game->direc_weap = 3;
        game->change_weap = 0;
    }
}

void change_weather(game_t *game)
{
    if (game->progress_bar->weather->day && game->is_on_map != BOSS) {
        game->progress_bar->weather->cycle += 2;
        if (game->progress_bar->weather->cycle >= 200) {
            game->progress_bar->weather->min = rand() % (60 - 10) + 10;
            game->progress_bar->weather->max = rand() % (180 - 80) + 80;
            game->progress_bar->weather->day = false;
        }
    }
    if (!game->progress_bar->weather->day && game->is_on_map != BOSS) {
        game->progress_bar->weather->cycle -= 2;
        if (game->progress_bar->weather->cycle <= 10) {
            game->progress_bar->weather->day = true;
            game->progress_bar->weather->min = rand() % (60 - 10) + 10;
            game->progress_bar->weather->max = rand() % (180 - 80) + 80;
        }
    }
    if (game->is_on_map == BOSS)
        game->progress_bar->weather->cycle = 0;
}

void do_cycle(game_t *game)
{
    if (get_seconds(game->progress_bar->weather->clock,
    game->progress_bar->weather->time) > CYCLE &&
    game->state != PAUSE) {
        change_weather(game);
        sfClock_restart(game->progress_bar->weather->clock);
    }
}

void process_ingame(game_t *game, menu_t *menu, lnk_ltype_t *ltype)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        ingame_events(game, ltype);
        process_list(game, menu->ingame->buttons, pause_events);
    }
    sfRenderWindow_setView(game->window, game->player);
    sfRenderWindow_drawSprite(game->window, ltype->map->sprite, NULL);
    change_weap(game, ltype, ltype->chr);
    process_chr(game, ltype->chr, ltype);
    process_list(game, ltype->particles, process_rain);
    process_list(game, ltype->text, process_texts);
    map_ingame(game, menu, ltype);
    day_cycle(game);
    do_cycle(game);
    process_ltype(game, *ltype, &ltype->effects, process_effects);
    if (game->state == GAME_OVER)
        process_game_over(game, ltype->interface);
    if (game->state == WIN)
        process_win(game, ltype->interface);
    sfRenderWindow_setView(game->window, game->minimap);
    process_minimap(game, ltype);
    change_map(ltype, game);
}
