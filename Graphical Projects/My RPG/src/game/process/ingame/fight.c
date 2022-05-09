/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** fight.c
*/

#include "my_rpg.h"

static void explosion(game_t *game, object_t *object)
{
    sfVector2f pos;
    double rdm = 0;

    if (game->progress_bar->effect->is_bombing == true) {
        anime_sprite(object, (sfVector2f) {5, 3}, 0.1);
        if (get_seconds(game->progress_bar->effect->clock,
        game->progress_bar->effect->time) >= 1.5) {
            rdm = ((1.0 - .2) * rand()) / RAND_MAX + .2;
            sfSound_setPitch(game->sounds[BOMB], rdm);
            sfSound_play(game->sounds[BOMB]);
            pos = (sfVector2f) {sfView_getCenter(game->player).x -
            WIDTH / 2 + rand() % (WIDTH - 200),
            sfView_getCenter(game->player).y - HEIGHT / 2 +
            rand() % (HEIGHT - 200)};
            sfSprite_setPosition(object->sprite, pos);
            sfClock_restart(game->progress_bar->effect->clock);
        }
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    }
}

static void direction_bullet(object_t *bullet, lnk_ltype_t *ltype)
{
    switch (ltype->chr->utils.rect.top) {
        case 0: bullet->event->target.y = 20;
            sfSprite_rotate(bullet->sprite, 90);
            break;
        case 32: bullet->event->target.x = -20;
            sfSprite_rotate(bullet->sprite, 180);
            break;
        case 64: bullet->event->target.x = 20;
            break;
        case 96: bullet->event->target.y = -20;
            sfSprite_rotate(bullet->sprite, -90);
            break;
    }
}

static void bullet(game_t *game, object_t *bullet,
lnk_list_t *list, lnk_ltype_t *ltype)
{
    sfVector2f pbullet = sfSprite_getPosition(bullet->sprite);

    if (bullet->event->target.x != 20 && bullet->event->target.x != -20 &&
    bullet->event->target.y != 20 && bullet->event->target.y != -20)
        direction_bullet(bullet, ltype);
    if ((pbullet.x > 6367 || pbullet.x < 0 ||
    pbullet.y > 6367 || pbullet.y < 0))
        delete_node(&list);
    sfSprite_move(bullet->sprite, bullet->event->target);
    sfRenderWindow_drawSprite(game->window, bullet->sprite, NULL);
}

void process_effects(game_t *game, lnk_ltype_t *ltype, lnk_list_t *list)
{
    object_t *effect = (object_t *) list->data;

    if (effect->utils.type == BULLET)
        bullet(game, effect, list, ltype);
    if (effect->utils.type == EXPL)
        explosion(game, effect);

}
