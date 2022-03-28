/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** init_object.c
*/

#include "my_defender.h"

lnk_ltype_t *init_lnk_ltype(void)
{
    lnk_ltype_t *ltype = malloc(sizeof(lnk_ltype_t));

    ltype->mobs = NULL;
    ltype->bulding = NULL;
    ltype->entities = NULL;
    ltype->textures = NULL;
    ltype->texture = sfTexture_createFromFile("assets/img/Textures.png", NULL);
    ltype->objects = sfTexture_createFromFile("assets/img/Objects.png", NULL);
    return ltype;
}

void create_objects(utils_t utils, lnk_list_t **type, sfTexture *objects)
{
    object_t *object = malloc(sizeof(object_t));

    object->sprite = sfSprite_create();
    object->utils.rect = utils.rect;
    object->utils.pos = utils.pos;
    object->utils.type = utils.type;
    object->utils.id = utils.id;
    object->step = 1;
    sfSprite_setPosition(object->sprite, object->utils.pos);
    sfSprite_setTexture(object->sprite, objects, sfTrue);
    sfSprite_setTextureRect(object->sprite, object->utils.rect);
    add_node(object, type);
}

void create_texture(utils_t utils, lnk_list_t **textures, sfTexture *map)
{
    texture_t *texture = malloc(sizeof(texture_t));

    texture->sprite = sfSprite_create();
    texture->utils.rect = utils.rect;
    texture->utils.pos = utils.pos;
    texture->utils.id = utils.id;
    texture->utils.type = utils.type;
    sfSprite_setPosition(texture->sprite, texture->utils.pos);
    sfSprite_setTexture(texture->sprite, map, sfTrue);
    sfSprite_setTextureRect(texture->sprite, texture->utils.rect);
    add_node(texture, textures);
}
