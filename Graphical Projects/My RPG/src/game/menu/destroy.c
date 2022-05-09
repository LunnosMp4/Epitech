/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** destroy.c
*/

#include "my_rpg.h"

void destroy_buttons(UNUSED game_t *game, lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;

    sfSprite_destroy(object->sprite);
    sfClock_destroy(object->anim->clock);
    free(object->anim);
    free(object);
}

void destroy_texts(UNUSED game_t *game, lnk_list_t *list)
{
    text_t *text = (text_t *) list->data;

    sfText_destroy(text->text);
    sfFont_destroy(text->font);
    free(text);
}

void destroy_menu(menu_t *menu, lnk_ltype_t *ltype)
{
    static bool once = true;

    if (once == true) {
        sfTexture_destroy(menu->main->bg_menu);
        process_list(NULL, menu->settings->texts, destroy_texts);
        process_list(NULL, menu->settings->buttons, destroy_buttons);
        process_list(NULL, menu->main->texts, destroy_texts);
        process_list(NULL, menu->main->buttons, destroy_buttons);
        free(menu->main);
        free(menu->settings);
        init_ukr(ltype);
        once = false;
    }
}
