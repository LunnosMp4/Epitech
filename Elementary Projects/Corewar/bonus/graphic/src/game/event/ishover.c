/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** ishover.c
*/

#include "graphic.h"

bool ishover(sfRenderWindow *win, object_t *object)
{
    sfVector2i curs = sfMouse_getPositionRenderWindow(win);
    sfVector2f obj = sfSprite_getPosition(object->sprite);

    if (curs.x >= obj.x && curs.x <= obj.x + object->utils.rect.width
    && curs.y >= obj.y && curs.y <= obj.y + object->utils.rect.height)
        return true;
    return false;
}
