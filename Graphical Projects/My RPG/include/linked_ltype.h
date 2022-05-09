/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** linked_ltype.h
*/

#ifndef LINKED_LTYPE_H_
    #define LINKED_LTYPE_H_
    #include "my_rpg.h"

typedef struct lnk_ltype_s {
    lnk_list_t *enemy;
    lnk_list_t *allies;
    object_t *chr;
    object_t *npc;
    object_t *poutine;
    lnk_list_t *text;
    lnk_list_t *interface;
    lnk_list_t *effects;
    lnk_list_t *particles;
    lnk_list_t *dead;
    object_t *map;
    object_t *ovcoat;
    dialog_t *dialog;
    sfTexture *warzone;
    sfTexture *lcorner;
    sfTexture *entities;
    sfTexture *explosion;
    sfTexture *faces;
    sfTexture *map_ukr;
    sfTexture *map_russ;
    sfTexture *map_boss;
    sfTexture *ovcoat_ukr;
    sfTexture *ovcoat_war;
    sfTexture *ovcoat_russ;
    sfTexture *bar_player;
    sfTexture *popup;
    sfTexture *bgdialog;
    sfTexture *quest_1;
    sfTexture *quest_2;
    sfTexture *icone_quest;
} lnk_ltype_t;

lnk_ltype_t *create_ltype(void);

#endif /* LINKED_LTYPE_H_ */
