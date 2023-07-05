/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-loic.tisseyre
** File description:
** set_objects.c
*/

#include "../include/my_runner.h"
#include "../include/object.h"

void set_character(fond_t *fond, char **av, int ac);

void set_fond(object_t *object, fond_t *fond, sfVector2f pos)
{
    fond->object0 = create_object("images/0.png", pos, fond->rect);
    fond->object1 = create_object("images/1.png", pos, fond->rect);
    fond->object2 = create_object("images/2.png", pos, fond->rect);
    fond->object3 = create_object("images/3.png", pos, fond->rect);
    fond->object4 = create_object("images/4.png", pos, fond->rect);
    fond->object5 = create_object("images/5.png", pos, fond->rect);
    fond->object6 = create_object("images/6.png", pos, fond->rect);
    fond->object7 = create_object("images/7.png", pos, fond->rect);
}

void set_object(object_t *object,
fond_t *fond, char **av, int ac)
{
    sfVector2f pos = {0, 0};
    sfVector2f pos3 = {800, 450};
    sfVector2f scl = {0.4, 0.4};
    if ((ac == 3 || ac == 4) && av[2][0] == '-' && av[2][1] == 'i') {
        my_putstr("Infinite Mod\n");
        fond->max = 1000000;
    } else
        fond->max = 1000;
    set_fond(object, fond, pos);
    fond->start = create_object("images/start_game.png", pos, fond->rect);
    set_character(fond, av, ac);
    fond->log = create_object("images/log.png", pos3, fond->rectlog);
    fond->log2 = create_object("images/log.png", pos3, fond->rectlog);
    fond->object8 = create_object("images/8.png", pos, fond->rect);
    sfSprite_setScale(fond->fox->sprite, scl);
    sfSprite_setScale(fond->log->sprite, scl);
    sfSprite_setScale(fond->log2->sprite, scl);
}