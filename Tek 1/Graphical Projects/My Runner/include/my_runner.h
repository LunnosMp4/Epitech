/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myrunner-loic.tisseyre
** File description:
** my_runner.h
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>


typedef struct game {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfColor clear_color;
    sfEvent event;
    sfMusic *jump;
    sfFont *font;
    sfText *text;
    sfText *textwin;
    sfText *textloose;
    sfText *textpause;
    float x;
    float y;
    float velocityY;
    float accelerationY;
    float gravity;
    int score;
    int pause;
    int start;
    char *buff;
    int spd;
    int n1;
    int n2;
    int n3;
    int i;
    int c;
} game_t;
