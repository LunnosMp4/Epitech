/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** event.c
*/

#include "my_rpg.h"

void pause_events(game_t *game, lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;

    if (ishover(game, object) && object->utils.type == BTN_EXIT &&
    game->event.type == sfEvtMouseButtonPressed)
        sfRenderWindow_close(game->window);
    if (ishover(game, object) && object->utils.type == BTN_PLAY &&
    game->event.type == sfEvtMouseButtonPressed)
        game->state = INGAME;
}

void menu_events(game_t *game, UNUSED menu_t *menu, lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;

    if (game->event.type == sfEvtClosed || (game->event.type == sfEvtKeyPressed
    && game->event.key.code == sfKeyEscape))
        sfRenderWindow_close(game->window);
    if (ishover(game, object) && game->event.type == sfEvtMouseButtonPressed) {
        sfSound_play(game->sounds[2]);
        if (object->utils.type == BTN_PLAY) {
            sfMusic_stop(game->music[MMENU]);
            sfMusic_play(game->music[MBASE]);
            game->state = INGAME;
        }
        if (object->utils.type == BTN_EXIT)
            sfRenderWindow_close(game->window);
        if (object->utils.type == BTN_SETTINGS)
            game->state = SETTINGS;
    }
}

static void manage_volume(game_t *game, lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;
    game->volume = sfMusic_getVolume(game->music[0]);

    if (ishover(game, object) && sfMouse_isButtonPressed(sfMouseLeft)) {
        if (object->utils.type == BTN_VOL_M)
            game->volume -= 1;
        if (object->utils.type == BTN_VOL_P)
            game->volume += 1;
        if (game->volume > 100)
            game->volume = 100;
        if (game->volume <= 0)
            game->volume = 1;
    }
    for (int i = 0; i < NB_MUSIC; i++)
        sfMusic_setVolume(game->music[i], game->volume);
}

static void manage_size(game_t *game, lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;
    int size = 0;

    if (ishover(game, object) && sfMouse_isButtonPressed(sfMouseLeft)) {
        if (object->utils.type == BTN_SIZE_M)
            size--;
        if (object->utils.type == BTN_SIZE_P)
            size++;
        if (size > 1)
            size = 1;
        if (size < -1)
            size = -1;
    }
    if (size == 1)
        sfRenderWindow_setSize(game->window, (sfVector2u) {1920, 1080});
    if (size == -1)
        sfRenderWindow_setSize(game->window, (sfVector2u) {WIDTH, HEIGHT});
}

void settings_events(game_t *game, UNUSED menu_t *menu, lnk_list_t *list)
{
    if (game->event.type == sfEvtClosed || (game->event.type == sfEvtKeyPressed
    && game->event.key.code == sfKeyEscape))
        game->state = MENU;
    manage_volume(game, list);
    manage_size(game, list);
}
