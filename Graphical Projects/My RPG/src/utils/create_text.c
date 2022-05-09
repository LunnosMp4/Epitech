/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** create_text.c
*/

#include "my_rpg.h"

text_t *create_text(utils_txt_t utils, lnk_list_t **objects)
{
    text_t *text = malloc(sizeof(text_t));

    text->text = sfText_create();
    text->utils = utils;
    text->font = sfFont_createFromFile("assets/arcade.ttf");
    sfText_setString(text->text, text->utils.string);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, text->utils.size);
    sfText_setPosition(text->text, text->utils.pos);
    sfText_setColor(text->text, text->utils.color);
    sfText_setString(text->text, text->utils.string);
    if (objects)
        add_node(text, objects);
    return text;
}
