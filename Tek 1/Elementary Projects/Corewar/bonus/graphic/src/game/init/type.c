/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** type.c
*/

#include "graphic.h"

type_t *create_type(void)
{
    type_t *type = malloc(sizeof(type_t));

    type->buttons = NULL;
    type->bg = NULL;
    type->texts = NULL;
    return type;
}
