/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** game.h
*/

#ifndef GAME_H
    #define GAME_H
    #include "my_rpg.h"
    #define WIDTH 1200
    #define HEIGHT 680
    #define RES 32
    #define ENTW entity->utils.rect.width
    #define ENTH entity->utils.rect.height
    #define TEXTURE(file, intrect) sfTexture_createFromFile(file, intrect)
    #define CYCLE 4

    #define NB_MUSIC    4
    #define MMENU       0
    #define MBASE       1
    #define MFIGHT      2
    #define MBOSS       3

    #define NB_SOUND    6
    #define RELOAD      0
    #define SHOOT       1
    #define CLICK       2
    #define BOMB        3
    #define PLANE       4
    #define ROAR        5

    #define UKR        0
    #define FRONT      1
    #define RUS        2
    #define BOSS       3

    #define INTRO   0
    #define PROLI   1
    #define PROLII  2
    #define PARTI   3
    #define PARTII  4
    #define END     5

typedef enum {MENU, INGAME, PAUSE, STORY, GAME_OVER, SETTINGS, WIN} GAME;
typedef enum {ALLIES, ENEMY, HEROES, CAR, CHR, BTN_PLAY, BTN_EXIT,
BTN_SETTINGS, MAP, IMG, TEXT, TEXT_MAP, TEXT_P, TEXT_LIFE, TEXT_XP,
NB_VOL, TEXT_LVL, BG, POPUP, POPUP_MAP, POPUP_P, POPUP_BARS, BTN_VOL_P,
POPUP_INV, BTN_VOL_M, BTN_SIZE_M, BTN_SIZE_P, DIALOG, BULLET, AMMO,
AK47, SNIPER, GLOCK, NPC, QUEST_1, QUEST_2, EXPL, WPN, HEALTH, HEALTH_TEXT,
HEALTH_RD, TEXT_DEAD, TEXT_DEAD2, HONEY, INVISIBLE, DEAD} TYPE;

typedef struct game {
    sfRenderWindow *window;
    sfColor clear_color;
    sfEvent event;
    sfView *player;
    sfView *minimap;
    sfMusic **music;
    sfSound **sounds;
    float volume;
    progress_bar_t *progress_bar;
    GAME state;
    bool state_change;
    sfClock *clock;
    sfTime time;
    int chr;
    bool move;
    bool is_alive;
    sfVector2f entity;
    int change_weap;
    int direc_weap;
    int is_on_map;
    char **map_cols;
    int quest;
    bool honney;
    float xp;
} game_t;

game_t *create_game(sfVideoMode mode, sfColor clear_color);

#endif /* GAME_H_ */
