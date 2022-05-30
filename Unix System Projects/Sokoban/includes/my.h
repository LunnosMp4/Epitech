/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** my_sokoban.h
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <dirent.h>
    #include <string.h>
    #include <curses.h>
    #include <sys/stat.h>

typedef struct array {
    char **oldarr;
    char **newarr;
    int lines;
} array_t;

typedef struct write_game {
    int count;
    int count2;
    int basex;
    int basey;
} write_game_t;

void my_putchar(char c);
int my_putstr(char const *str);
int error_handling(int ac, char **av);
int allocate_map(char *filepath);
void game_process(array_t *array);
int my_strlen(char const *str);
char **str_to_wordarray(char *buffer, char **arr, array_t *array);
void check_exit(void);
void check_keybinds(array_t *array);
void catch_map(array_t *array, int i, int j);
int movement_up(array_t *array);
int movement_down(array_t *array);
int movement_right(array_t *array);
int movement_left(array_t *array);
int win_check(array_t *array);
int loose_check(array_t *array);
void check_invalid_map(char *buffer);
void write_map(array_t *array, int i, write_game_t *write_game);
void exit_sokoban(int return_value);
void exit_print_sokoban(array_t *array,
write_game_t *write_game, int return_value);
#endif
