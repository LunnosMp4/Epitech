/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** loop.c
*/

#include "my_rpg.h"

static void process_story(UNUSED game_t *game, lnk_ltype_t *ltype)
{
    display_dialog(game, ltype->dialog, ltype);
}

static void game_state(game_t *game, menu_t *menu, lnk_ltype_t *ltype)
{
    switch (game->state) {
        case MENU: process_menu(menu, game);
            break;
        case STORY: process_story(game, ltype);
        case GAME_OVER:
        case WIN:
        case PAUSE:
        case INGAME: destroy_menu(menu, ltype);
            process_ingame(game, menu, ltype);
            break;
        case SETTINGS: process_settings(menu, game);
            break;
        default: break;
    }
}

void process_game(game_t *game, menu_t *menu, lnk_ltype_t *ltype)
{
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, game->clear_color);
        game_state(game, menu, ltype);
        sfRenderWindow_display(game->window);
    }
}
