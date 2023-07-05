/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** create_particules.c
*/

#include "my_rpg.h"

particles_t *create_particles(sfVector2f size, lnk_list_t **list)
{
    particles_t *particles = malloc(sizeof(particles_t));

    particles->shape = sfRectangleShape_create();
    sfRectangleShape_setFillColor(particles->shape,
    sfColor_fromRGBA(0, 30, 200, 60));
    sfRectangleShape_setSize(particles->shape, size);
    particles->clock = sfClock_create();
    sfRectangleShape_setPosition(particles->shape,
    (sfVector2f) {rand() % 6500, rand() % 6500});
    if (list)
        add_node(particles, list);
    return particles;
}
