/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** dialog.h
*/

#ifndef DIALOG_H_
    #define DIALOG_H_
    #include "my_rpg.h"

typedef struct dialog_s {
    sfFont *font;
    sfText *text;
    char *str;
    bool next_page;
    bool active;
    bool end;
    sfTime time;
    sfClock *clock;
    object_t *background;
    object_t *faces;
} dialog_t;

dialog_t *create_dialog(char *text, game_t *game, sfTexture *bg,
sfTexture *faces);

#endif /* DIALOG_H_ */
