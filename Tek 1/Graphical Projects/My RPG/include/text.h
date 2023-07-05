/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** text.h
*/

#ifndef TEXT_H_
    #define TEXT_H_
    #include "my_rpg.h"

typedef struct text_s {
    sfFont *font;
    sfText *text;
    sfTime time;
    utils_txt_t utils;
} text_t;

text_t *create_text(utils_txt_t utils, lnk_list_t **objects);

#endif /* TEXT_H_ */
