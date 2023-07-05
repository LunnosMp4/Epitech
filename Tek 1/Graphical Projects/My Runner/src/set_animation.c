/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-loic.tisseyre
** File description:
** set_animation.c
*/

#include "../include/my_runner.h"
#include "../include/object.h"

void set_repeated(object_t *object, fond_t *fond)
{
    sfTexture_setRepeated(fond->object0->texture, sfTrue);
    sfTexture_setRepeated(fond->object1->texture, sfTrue);
    sfTexture_setRepeated(fond->object2->texture, sfTrue);
    sfTexture_setRepeated(fond->object3->texture, sfTrue);
    sfTexture_setRepeated(fond->object4->texture, sfTrue);
    sfTexture_setRepeated(fond->object5->texture, sfTrue);
    sfTexture_setRepeated(fond->object6->texture, sfTrue);
    sfTexture_setRepeated(fond->object7->texture, sfTrue);
    sfTexture_setRepeated(fond->object8->texture, sfTrue);
}

void set_texturerect(object_t *object, fond_t *fond)
{
    sfSprite_setTextureRect(fond->object1->sprite, fond->rect);
    sfSprite_setTextureRect(fond->object0->sprite, fond->rect1);
    sfSprite_setTextureRect(fond->object2->sprite, fond->rect2);
    sfSprite_setTextureRect(fond->object3->sprite, fond->rect3);
    sfSprite_setTextureRect(fond->object4->sprite, fond->rect4);
    sfSprite_setTextureRect(fond->object5->sprite, fond->rect5);
    sfSprite_setTextureRect(fond->object6->sprite, fond->rect6);
    sfSprite_setTextureRect(fond->object7->sprite, fond->rect7);
    sfSprite_setTextureRect(fond->object8->sprite, fond->rect8);
}

void set_speed(object_t *object, fond_t *fond)
{
    fond->rect.left = fond->rect.left + 1;
    fond->rect1.left = fond->rect1.left + 1;
    fond->rect2.left = fond->rect2.left + 2;
    fond->rect3.left = fond->rect3.left + 3;
    fond->rect4.left = fond->rect4.left + 4;
    fond->rect5.left = fond->rect5.left + 5;
    fond->rect7.left = fond->rect7.left + 7.5;
    fond->rect6.left = fond->rect6.left + 8;
    fond->rect8.left = fond->rect8.left + 10;
}