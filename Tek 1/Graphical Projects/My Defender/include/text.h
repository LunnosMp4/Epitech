/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** game.h
*/

#ifndef TEXT_H
    #define TEXT_H
    #include "my_defender.h"

typedef struct text {
    sfFont *font;
    sfText *level;
    sfText *popup;
    sfText *paused;
} text_t;


#endif /* TEXT_H_ */
