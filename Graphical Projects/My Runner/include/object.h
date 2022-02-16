/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myrunner-loic.tisseyre
** File description:
** object.h
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct object {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} object_t;

typedef struct fond {
    sfMusic *MainMusic;
    object_t *object0;
    object_t *object1;
    object_t *object2;
    object_t *object3;
    object_t *object4;
    object_t *object5;
    object_t *object6;
    object_t *object7;
    object_t *object8;
    object_t *fox;
    object_t *log;
    object_t *log2;
    object_t *start;
    sfIntRect rect;
    sfIntRect rect1;
    sfIntRect rect2;
    sfIntRect rect3;
    sfIntRect rect4;
    sfIntRect rect5;
    sfIntRect rect6;
    sfIntRect rect7;
    sfIntRect rect8;
    sfIntRect rectfox;
    sfIntRect rectlog;
    sfClock *clock;
    float seconds;
    sfTime time;
    int max;
    sfClock *clock2;
    float seconds2;
    sfTime time2;
    int nb;
    int nb2;
} fond_t;

object_t *create_object (const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect);

game_t *create_game(sfVideoMode mode, game_t *game, sfColor clear_color);
void run_game(game_t *game, fond_t *fond, char *buffer);
int my_getnbr(char const *str);
void destroy_game(game_t *game, object_t *object, fond_t *fond);
void draw_gameloose(game_t *game, object_t *object, fond_t *fond);
void draw_gamewin(game_t *game, object_t *object, fond_t *fond);
void draw_game2(game_t *game, object_t *object, fond_t *fond);
void process_game(sfEvent event, game_t *game,
object_t *object, fond_t *fond);
int analyse_events(game_t *game, sfEvent event,
object_t *object, fond_t *fond);
void run_animations(game_t *game, object_t *object, fond_t *fond);
void detect_collision(game_t *game, object_t *object,
fond_t *fond, sfVector2f origin);
void draw_game(game_t *game, object_t *object, fond_t *fond);
void init_game(game_t *game, object_t *object, fond_t *fond);
void set_object(object_t *object, fond_t *fond,
char **av, int ac);
void reset_movement(game_t *game);
void set_movement(game_t *game);
void init(fond_t *fond);
void text_init(game_t *game);
int my_putstr(char const *str);
int my_put_nbr(int nb);