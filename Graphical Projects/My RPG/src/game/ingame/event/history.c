/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** history.c
*/

#include "my_rpg.h"

void dialog_event(game_t *game, lnk_ltype_t *ltype, char *topic)
{
    if (game->state == INGAME) {
        ltype->dialog = create_dialog(read_file(strcat_alloc("assets/history/",
        topic)), game, ltype->bgdialog, ltype->faces);
        change_face_dialog(ltype->dialog);
        game->state = STORY;
    }
}

static void game_prologue(game_t *game, lnk_ltype_t *ltype)
{
    sfVector2f pnpc = sfSprite_getPosition(ltype->npc->sprite);

    if (game->quest == INTRO) {
        dialog_event(game, ltype, "Introduction");
        game->quest = PROLI;
    }
    if (game->event.key.code == sfKeyA &&
    entity_in_area(ltype->chr, pnpc, 100) && game->quest == PROLI) {
        game->quest = PROLII;
        dialog_event(game, ltype, "Prologue");
    }
    if (entity_in_area(ltype->chr, (sfVector2f) {5305, 5600}, 200)
    && game->quest == PROLII) {
        game->quest = PARTI;
        dialog_event(game, ltype, "Prologue II");
    }
}

void history(game_t *game, lnk_ltype_t *ltype)
{
    game_prologue(game, ltype);
    if (ltype->dialog->active && game->quest == PARTI) {
        ltype->dialog->active = false;
        game->quest = PARTII;
        dialog_event(game, ltype, "Part I");
    }
    if (game->quest == PARTII && game->is_on_map == BOSS) {
        game->quest = END;
        dialog_event(game, ltype, "Part II");
    }
    if (game->event.key.code == sfKeyA && ltype->dialog)
        ltype->dialog->next_page = true;
}
