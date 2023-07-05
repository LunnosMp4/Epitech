/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** inhibitors.h
*/

#ifndef INHIBITORS_H
    #define INHIBITORS_H

typedef struct inhibitors_s {
    char *new_str;
    int nb;
    int i;
    int j;
} inhibitors_t;

void fix_space_inhibitors(inhibitors_t *ibt, int i);
char *process_inhibitors(char *str);

#endif
