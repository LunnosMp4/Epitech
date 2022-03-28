/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** build_tower.c
*/

#include "my_defender.h"

static void create_turret(game_t *game,
lnk_ltype_t *ltype, int tex, sfVector2i pos)
{
    create_objects((utils_t) {{RES * tex, 0, RES, RES},
    {pos.x - RES, pos.y - RES}, game->id, BUILDING},
    &ltype->bulding, ltype->objects);
    create_objects((utils_t) {{RES * 2, 0, RES, RES},
    {pos.x - RES, pos.y + 5 - RES}, game->id, BUILDING},
    &ltype->bulding, ltype->objects);
    game->id++;
}

void turret_isclicked(game_t *game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    square_is_hover(game, 20, 580))
        game->grab = MINI_TURRET;
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    square_is_hover(game, 150, 580))
        game->grab = MEDIUM_TURRET;
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    square_is_hover(game, 270, 580))
        game->grab = LARGE_TURRET;
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    square_is_hover(game, 1065, 580))
        game->state = MENU;
}

void turret_isreleased(game_t *game, lnk_ltype_t *ltype)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(game->window);
    int tex = 0;
    (void) ltype;

    if (game->conf->map[p_mouse.y / RES][p_mouse.x / RES] != 26) {
        sfMusic_play(game->sounds->music[3]);
        return;
    }
    sfMusic_play(game->sounds->music[2]);
    if (game->grab == MINI_TURRET)
        tex = 6;
    if (game->grab == MEDIUM_TURRET)
        tex = 17;
    if (game->grab == LARGE_TURRET)
        tex = 18;
    create_turret(game, ltype, tex, p_mouse);
    game->grab = 0;
}

void replace_turret_btn(game_t *game, object_t *object)
{
    if (game->grab == 0 && object->utils.type == BUTTON) {
        sfSprite_setColor(object->sprite,
        sfColor_fromRGBA(255, 255, 255, 255));
        if (object->utils.id == MINI_TURRET)
            sfSprite_setPosition(object->sprite, (sfVector2f) {40, 590});
        if (object->utils.id == MEDIUM_TURRET)
            sfSprite_setPosition(object->sprite, (sfVector2f) {155, 590});
        if (object->utils.id == LARGE_TURRET)
            sfSprite_setPosition(object->sprite, (sfVector2f) {275, 590});
    }
}
