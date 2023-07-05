/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** attribute.h
*/

#ifndef ATTRIBUTE_H_
    #define ATTRIBUTE_H_
    #include "my_rpg.h"
    #define ALIVE  0
    #define GOD    11

typedef struct attribute_s {
    float hp;
    float max_hp;
    float atk;
    float speed;
    float def;
    int lvl;
    float xp;
    int state;
    int mun;
    int max_mun;
    int health_nb;
    float damage;
    float duration;
    float cadency;
    float pitch;
} attribute_t;

attribute_t *set_attribute();

#endif /* ATTRIBUTE_H_ */
