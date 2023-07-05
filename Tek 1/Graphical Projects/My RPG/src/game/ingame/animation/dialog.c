/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** chat.c
*/

#include "my_rpg.h"

void change_face_dialog(dialog_t *dialog)
{
    dialog->faces->utils.rect.left = 600;
    if (str_isequal(dialog->str, "Mikhail", false))
        dialog->faces->utils.rect.left = 0;
    if (str_isequal(dialog->str, "Mariya", false))
        dialog->faces->utils.rect.left = 96;
    if (str_isequal(dialog->str, "Ilona", false))
        dialog->faces->utils.rect.left = 192;
    if (str_isequal(dialog->str, "Orest", false))
        dialog->faces->utils.rect.left = 288;
    if (str_isequal(dialog->str, "Ruslan", false))
        dialog->faces->utils.rect.left = 384;
    if (str_isequal(dialog->str, "Poutine", false))
        dialog->faces->utils.rect.left = 480;
    sfSprite_setTextureRect(dialog->faces->sprite, dialog->faces->utils.rect);
}

static void dialog_str(dialog_t *dialog, game_t *game)
{
    if (*(dialog->str) == '\0') {
        sfText_setString(dialog->text, "");
        dialog->end = true;
        game->state = INGAME;
    }
}

void display_dialog(game_t *game, dialog_t *dialog, UNUSED lnk_ltype_t *ltype)
{
    static float seconds = 0;
    static int j = 1;
    char *anim_dialog = malloc(sizeof(char) * j + 1);

    if (dialog->next_page) {
        j = 1;
        dialog->str += find_word(dialog->str, "\n\n") + 2;
        dialog->next_page = false;
        change_face_dialog(dialog);
    }
    dialog_str(dialog, game);
    seconds = get_seconds(dialog->clock, dialog->time);
    if (seconds > 0.005 && !(dialog->str[j] == '\n'
    && dialog->str[j + 1] == '\n')) {
        anim_dialog = my_strncpy(anim_dialog, dialog->str, j++);
        sfText_setString(dialog->text, anim_dialog);
        sfClock_restart(dialog->clock);
    }
    free(anim_dialog);
}
