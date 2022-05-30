/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** text.h
*/

#ifndef TEXT_H_
    #define TEXT_H_
    #include "graphic.h"

typedef struct text_s {
    sfFont *font;
    sfText *text;
    sfTime time;
    utils_txt_t utils;
} text_t;

text_t *create_text(utils_txt_t utils, lnk_tlist_t **objects);

#endif /* TEXT_H_ */
