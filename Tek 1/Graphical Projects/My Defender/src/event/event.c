/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** event.c
*/

#include "my_defender.h"

static void menu_event(game_t *game, lnk_list_t *buttons)
{
    button_t *button = (button_t *) buttons->data;

    if (sfMouse_isButtonPressed(sfMouseLeft) && button_is_hover(game, button)) {
        sfMusic_play(game->sounds->music[0]);
        switch (button->id) {
            case EXIT: sfRenderWindow_close(game->window);
                break;
            case PLAY: game->state = SELECT;
                break;
            case INFO: game->state = INFO;
                break;
            case MUTE: change_volume(game, button);
                break;
            default: break;
        }
    }
}

static void info_event(game_t *game, lnk_list_t *buttons)
{
    button_t *button = (button_t *) buttons->data;

    if (sfMouse_isButtonPressed(sfMouseLeft) && button_is_hover(game, button)) {
        sfMusic_play(game->sounds->music[0]);
        switch (button->id) {
            case EXIT: game->state = MENU;
                break;
            case NEXT: next_page(&game->conf->next, 3);
                break;
            default: break;
        }
    }
}

static void select_event(game_t *game, lnk_list_t *buttons, lnk_ltype_t *ltype)
{
    button_t *button = (button_t *) buttons->data;

    if (sfMouse_isButtonPressed(sfMouseLeft) && button_is_hover(game, button)) {
        sfMusic_play(game->sounds->music[0]);
        switch (button->id) {
            case EXIT: game->state = MENU;
                break;
            case NEXT: next_page(&game->conf->set_map, 2);
                break;
            case BIOME: next_page(&game->conf->set_biome, 5);
                break;
            case RUN: load_map(ltype, game);
            path_mobs(game->conf);
            game->state = INGAME;
                break;
            default: break;
        }
    }
}

static void game_event(game_t *game)
{
    sfMusic_stop(game->sounds->music[0]);
    if (game->event.type == sfEvtClosed || (game->event.type == sfEvtKeyPressed
    && game->event.key.code == sfKeyEscape))
        game->state = MENU;
    if ( game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyP) {
        if (game->pause == 0) {
            game->pause = 1;
            sfMusic_pause(game->sounds->music[1]);
        } else if (game->pause == 1) {
            game->pause = 0;
            sfMusic_play(game->sounds->music[1]);
        }
    }
    if (game->pause == 0)
        turret_isclicked(game);
}

void process_window_events(game_t *game, lnk_ltype_t *ltype, menu_t *menu)
{
    if (game->event.type == sfEvtClosed || (game->event.type == sfEvtKeyPressed
    && game->event.key.code == sfKeyEscape && game->state != INGAME))
        sfRenderWindow_close(game->window);
    if (&game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    switch (game->state) {
        case MENU: process_list(menu->buttons, game, menu_event);
            break;
        case INFO: process_list(menu->buttons, game, info_event);
            break;
        case INGAME: game_event(game);
            break;
        case SELECT: process_ltype(ltype, menu->buttons, game, select_event);
            break;
        default: break;
    }
}
