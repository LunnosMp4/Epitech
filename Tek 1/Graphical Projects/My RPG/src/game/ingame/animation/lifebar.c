/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** lifebar.c
*/

#include "my_rpg.h"

static void lifebar_xp_lvl(game_t *game, lnk_ltype_t *ltype, text_t *text)
{
    if (text->utils.type == TEXT_XP) {
        sfText_setPosition(text->text, (sfVector2f) {
        sfView_getCenter(game->player).x - WIDTH / 2 + 200,
        sfView_getCenter(game->player).y + HEIGHT / 2 - 50});
        sfRenderWindow_drawText(game->window, text->text, NULL);
        char *str_xp = convert_int_to_text(ltype->chr->stats->xp, " / 1000\n");
        sfText_setString(text->text, str_xp);
    }
    if (text->utils.type == TEXT_LVL) {
        sfText_setPosition(text->text, (sfVector2f) {
        sfView_getCenter(game->player).x - WIDTH / 2 + 120,
        sfView_getCenter(game->player).y + HEIGHT / 2 - 25});
        sfRenderWindow_drawText(game->window, text->text, NULL);
        char *str_lvl = convert_int_to_text(ltype->chr->stats->lvl,
        " LEVEL\n");
        sfText_setString(text->text, str_lvl);
    }
}

static void lifebar_texts_start(game_t *game, lnk_ltype_t *ltype)
{
    if (game->xp >= 1000) {
        game->xp = 1000;
        game->xp = 0;
        ltype->chr->stats->lvl += 1;
        ltype->chr->stats->max_hp += 5;
        ltype->chr->stats->hp = ltype->chr->stats->max_hp;
    }
    ltype->chr->stats->xp = game->xp;
}

void lifebar_texts(game_t *game, lnk_ltype_t *ltype, text_t *text)
{
    char *str_life = NULL;
    char *str_life_max = malloc(sizeof(char) * 100);

    lifebar_texts_start(game, ltype);
    if (text->utils.type == TEXT_LIFE) {
        sfText_setPosition(text->text, (sfVector2f) {
        sfView_getCenter(game->player).x - WIDTH / 2 + 200,
        sfView_getCenter(game->player).y + HEIGHT / 2 - 82});
        sfRenderWindow_drawText(game->window, text->text, NULL);
        str_life =
        convert_int_to_text(ltype->chr->stats->hp, " / ");
        str_life_max = convert_int(ltype->chr->stats->max_hp,
        "0123456789", str_life_max);
        sfText_setString(text->text, strcat_alloc(str_life, str_life_max));
    }
    lifebar_xp_lvl(game, ltype, text);
}

void lifebar_xp(game_t *game, lnk_ltype_t *ltype, sfVector2f size2)
{
    sfRectangleShape_setPosition(game->progress_bar->xp, (sfVector2f)
    {sfView_getCenter(game->player).x - WIDTH / 2 + 128,
    sfView_getCenter(game->player).y + HEIGHT / 2 - 55});
    size2 = (sfVector2f) {(ltype->chr->stats->xp / 10) * 2.25, 25};
    sfRectangleShape_setSize(game->progress_bar->xp, size2);
    sfRenderWindow_drawRectangleShape(game->window,
    game->progress_bar->xp, NULL);
}

void lifebar(game_t *game, lnk_ltype_t *ltype)
{
    float life = ltype->chr->stats->hp;
    sfVector2f size2;

    if (life > 100)
        life = 101;
    if (life < 0)
        life = 0;
    ltype->chr->stats->hp = life;
    sfRectangleShape_setPosition(game->progress_bar->health, (sfVector2f)
    {sfView_getCenter(game->player).x - WIDTH / 2 + 128,
    sfView_getCenter(game->player).y + HEIGHT / 2 - 80});
    sfVector2f size = {life * 2.25, 25};
    sfRectangleShape_setSize(game->progress_bar->health, size);
    sfRenderWindow_drawRectangleShape(game->window,
    game->progress_bar->health, NULL);
    lifebar_xp(game, ltype, size2);
}
