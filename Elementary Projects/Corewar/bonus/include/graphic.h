/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** graphic.h
*/

#ifndef GRAPHIC_H
    #define GRAPHIC_H
    #define UNUSED __attribute__((unused))
    #define WIDTH  1980
    #define HEIGHT 1066
    #define TEXTURE(file, intrect) sfTexture_createFromFile(file, intrect);

    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>

    #include "corewar.h"
    #include "game.h"
    #include "linked_list.h"
    #include "animation.h"
    #include "utils.h"
    #include "type.h"
    #include "object.h"
    #include "text.h"

int graphic(corewar_t *corewar);
//INIT
void init_objects(type_t *type, corewar_t *corewar);
//PROCESS
void process_graphic(game_t *game, type_t *type);
void process_list(game_t *game, type_t *type, lnk_tlist_t **list,
void (*pointer)(game_t *, type_t *, lnk_tlist_t *));
void process_events(game_t *game);
//DESTROY
void destroy_game(game_t *game);
void destroy_objects(game_t *game, type_t *type,
lnk_tlist_t *list);
//ANIMATION
void anim_button_pressed(object_t *btn);
//UTILS
bool ishover(sfRenderWindow *win, object_t *object);
char *itoa(int nb);
//Linked list
void add_type_node(void *data, lnk_tlist_t **head);

#endif /* GRAPHIC_H */
