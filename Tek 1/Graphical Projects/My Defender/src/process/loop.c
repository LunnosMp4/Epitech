/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** loop.c
*/

#include "my_defender.h"

void process_list(lnk_list_t *list, game_t *game, void
(*pointer)(game_t *, lnk_list_t *))
{
    while (list != NULL) {
        pointer(game, list);
        list = list->prev;
    }
}

void process_ltype(lnk_ltype_t *ltype, lnk_list_t *list, game_t *game, void
(*pointer)(game_t *, lnk_list_t *, lnk_ltype_t *))
{
    while (list != NULL) {
        pointer(game, list, ltype);
        list = list->prev;
    }
}

static void play_game(game_t *game, menu_t *menu, lnk_ltype_t *ltype)
{
    spawn_monster(ltype, game);
    process_list(ltype->textures, game, process_texture);
    process_list(ltype->mobs, game, process_sprite);
    process_list(menu->buttons, game, process_game_button);
    process_ltype(ltype, ltype->bulding, game, build_towers);
    if (game->pause == 1)
        sfRenderWindow_drawText(game->window, game->text->paused, NULL);
}

static void game_state(game_t *game, menu_t *menu, lnk_ltype_t *ltype)
{
    switch (game->state) {
        case MENU: process_menu(menu, game);
            break;
        case INGAME: play_game(game, menu, ltype);
            break;
        case SELECT: process_menu_map(menu, game);
            break;
        case INFO: process_menu_info(menu, game);
            break;
        default: break;
    }
}

int process_game(game_t *game, lnk_ltype_t *ltype, menu_t *menu)
{
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            process_window_events(game, ltype, menu);
        sfRenderWindow_clear(game->window, game->clear_color);
        game_state(game, menu, ltype);
        sfRenderWindow_display(game->window);
    }
    return 0;
}
