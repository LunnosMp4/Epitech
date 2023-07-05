/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** init_type.c
*/

#include "my_rpg.h"

static void create_heal(lnk_ltype_t *ltype)
{
    for (int i = 0; i != 30; i++)
        create_object((utils_t) {{710, 70, 18, 14}, {rand() % 6400,
        rand() % 6400}, HEALTH_RD}, &ltype->interface, ltype->entities);
}

static void init_third_ukr(lnk_ltype_t *ltype)
{
    create_object((utils_t) {{0, 0, 513, 120}, {0, 0},
    QUEST_1}, &ltype->interface, ltype->quest_1);
    create_object((utils_t) {{0, 0, 513, 120}, {0, 0},
    QUEST_2}, &ltype->interface, ltype->quest_2);
    create_object((utils_t) {{0, 0, 46, 55}, {1303, 2200},
    NPC}, &ltype->interface, ltype->icone_quest);
    create_object((utils_t) {{668, 0, 25, 15}, {1503, 2260},
    WPN}, &ltype->interface, ltype->entities);
    create_object((utils_t) {{710, 70, 18, 14}, {300, 300},
    HEALTH}, &ltype->interface, ltype->entities);
    create_heal(ltype);
    create_object((utils_t) {{735, 69, 12, 14},
    {rand() % (4150 - 3625) + 3625, rand() % (3815 - 3300) + 3300},
    HONEY}, &ltype->interface, ltype->entities);
    create_object((utils_t) {{0, 0, 251, 238}, {0, 0},
    POPUP_INV}, &ltype->interface, ltype->lcorner);
    create_object((utils_t) {{0, 0, 216, 208}, {300, 300},
    EXPL}, &ltype->effects, ltype->explosion);
    ltype->map = create_object((utils_t) {{0, 0, 6400, 6400},
    {0, 0}, MAP}, NULL, ltype->map_ukr);
    ltype->ovcoat = create_object((utils_t) {{0, 0, 6400, 6400}, {0, 0},
    MAP}, NULL, ltype->ovcoat_ukr);
}

static void init_second_ukr(lnk_ltype_t *ltype)
{
    create_object((utils_t) {{0, 224, RES, RES},
    {4426, 2920}, HEROES}, &ltype->enemy, ltype->entities);
    create_object((utils_t) {{256, 32, RES, RES}, {5443, 5500},
    HEROES}, &ltype->allies, ltype->entities);
    create_object((utils_t) {{128, 32, RES, RES}, {5185, 5600},
    HEROES}, &ltype->allies, ltype->entities);
    create_object((utils_t) {{384, 64, RES, RES}, {5300, 5500},
    HEROES}, &ltype->allies, ltype->entities);
    create_object((utils_t) {{0, 0, 95, 95},
    {5500, 5450}, IMG}, &ltype->interface, ltype->faces);
    create_object((utils_t) {{0, 0, 190, 61}, {0, 0},
    POPUP_BARS}, &ltype->interface, ltype->bar_player);
    create_object((utils_t) {{0, 0, 480, 240}, {825, 20},
    POPUP_MAP}, &ltype->interface, ltype->popup);
    init_third_ukr(ltype);
}

void init_ukr_extra(lnk_ltype_t *ltype)
{
    ltype->chr = create_object((utils_t) {{0, 0, RES, RES},
    {955, 6055}, CHR}, NULL, ltype->entities);
    create_text((utils_txt_t) {{0, 0}, TEXT_DEAD,
    100, "VOUS ETES MORT", {255, 0, 0, 255}}, &ltype->interface);
    create_text((utils_txt_t) {{0, 0}, TEXT_DEAD2,
    50, "Appuyez sur Echap pour quitter", {200, 0, 0, 255}}, &ltype->interface);
    ltype->npc = create_object((utils_t) {{512, 128, RES, RES},
    {1310, 2260}, NPC}, NULL, ltype->entities);
    ltype->poutine = create_object((utils_t)
    {{128, 160, RES, RES}, {1650, 3240},
    ENEMY}, NULL, ltype->entities);
    ltype->poutine->stats->hp = 10000;
    ltype->poutine->stats->atk = 70;
    for (int i = 0; i != 800; i++)
        create_particles((sfVector2f) {3, 30}, &ltype->particles);
    init_second_ukr(ltype);
}

void init_ukr(lnk_ltype_t *ltype)
{
    create_object((utils_t) {{0, 0, 480, 240}, {825, 20},
    POPUP_MAP}, &ltype->interface, ltype->popup);
    create_text((utils_txt_t) {{830, 4740}, TEXT_MAP,
    90, "BASE UKRAINIENNE", {255, 255, 80, 255}}, &ltype->text);
    create_text((utils_txt_t) {{465, 3217}, TEXT_MAP,
    90, "EMBLEME UKRAINIEN", {255, 255, 255, 80}}, &ltype->text);
    create_text((utils_txt_t) {{4480, 5600}, TEXT_MAP,
    90, "LAC SYNEVYR", {255, 255, 255, 80}}, &ltype->text);
    create_text((utils_txt_t) {{2667, 3090}, TEXT_MAP,
    90, "PONT PIVDENNYI", {255, 255, 255, 80}}, &ltype->text);
    create_text((utils_txt_t) {{0, 0}, TEXT_LIFE,
    20, "100 / 100", {255, 255, 255, 255}}, &ltype->text);
    create_text((utils_txt_t) {{0, 0}, TEXT_XP,
    15, "0 / 100", {255, 255, 255, 255}}, &ltype->text);
    create_text((utils_txt_t) {{0, 0}, AMMO,
    25, "10 / 10", {255, 255, 255, 255}}, &ltype->text);
    create_text((utils_txt_t) {{0, 0}, HEALTH_TEXT,
    25, "0", {255, 255, 255, 130}}, &ltype->text);
    create_text((utils_txt_t) {{0, 0}, TEXT_LVL,
    20, "1 LEVEL", {255, 255, 255, 255}}, &ltype->text);
    init_ukr_extra(ltype);
}
