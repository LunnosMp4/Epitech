/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** create_type.c
*/

#include "my_rpg.h"

static void init_texture(lnk_ltype_t *ltype)
{
    ltype->entities = TEXTURE("assets/img/Entities.png", NULL);
    ltype->map_ukr = TEXTURE("assets/img/map/AlliesBase.png", NULL);
    ltype->ovcoat_ukr = TEXTURE("assets/img/map/AlliesBase_l2.png", NULL);
    ltype->warzone = TEXTURE("assets/img/map/Warzone.png", NULL);
    ltype->ovcoat_war = TEXTURE("assets/img/map/Warzone_l2.png", NULL);
    ltype->map_russ = TEXTURE("assets/img/map/EnemyBase.png", NULL);
    ltype->ovcoat_russ = TEXTURE("assets/img/map/EnemyBase_l2.png", NULL);
    ltype->map_boss = TEXTURE("assets/img/map/InsideEnemy.png", NULL);
    ltype->faces = TEXTURE("assets/img/gui/Faces.png", NULL);
    ltype->bar_player = TEXTURE("assets/img/gui/BarPlayer.png", NULL);
    ltype->popup = TEXTURE("assets/img/gui/BackgroundPopUp.png", NULL);
    ltype->lcorner = TEXTURE("assets/img/gui/Bottom-left-inventory.png", NULL);
    ltype->bgdialog = TEXTURE("assets/img/gui/BackgroundDialog.png", NULL);
    ltype->quest_1 = TEXTURE("assets/img/gui/UiQuete1.png", NULL);
    ltype->quest_2 = TEXTURE("assets/img/gui/UiQuete2.png", NULL);
    ltype->icone_quest = TEXTURE("assets/img/QuestIcone.png", NULL);
    ltype->explosion = TEXTURE("assets/img/Explosion.png", NULL);
}

lnk_ltype_t *create_ltype(void)
{
    lnk_ltype_t *ltype = malloc(sizeof(lnk_ltype_t));

    ltype->enemy = NULL;
    ltype->allies = NULL;
    ltype->chr = NULL;
    ltype->text = NULL;
    ltype->map = NULL;
    ltype->interface = NULL;
    ltype->dialog = NULL;
    ltype->particles = NULL;
    ltype->effects = NULL;
    init_texture(ltype);
    return ltype;
}
