/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** create_dialog.c
*/

#include "my_rpg.h"

dialog_t *create_dialog(char *text, game_t *game, sfTexture *bg,
sfTexture *faces)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));

    dialog->text = sfText_create();
    dialog->clock = sfClock_create();
    dialog->next_page = false;
    dialog->font = sfFont_createFromFile("assets/arial.ttf");
    dialog->str = text;
    dialog->active = false;
    sfText_setFont(dialog->text, dialog->font);
    sfText_setCharacterSize(dialog->text, 22);
    sfText_setPosition(dialog->text, (sfVector2f) {
    sfView_getCenter(game->player).x - WIDTH / 2 + 200,
    sfView_getCenter(game->player).y + HEIGHT / 3.6});
    sfText_setColor(dialog->text, (sfColor) {255, 255, 255, 180});
    dialog->background = create_object((utils_t) {{0, 0, 1200, 200},
    (sfVector2f) {sfView_getCenter(game->player).x - WIDTH / 2,
    sfView_getCenter(game->player).y + HEIGHT / 5}, IMG}, NULL, bg);
    dialog->faces = create_object((utils_t) {{0, 0, 96, 96},
    (sfVector2f) {sfView_getCenter(game->player).x - WIDTH / 2.2,
    sfView_getCenter(game->player).y + HEIGHT / 3.7}, IMG}, NULL, faces);
    return dialog;
}
