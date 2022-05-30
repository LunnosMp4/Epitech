/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** my_map.c
*/

#include "my.h"

void game_process(array_t *array)
{
    write_game_t *write_game = malloc(sizeof(write_game_t));

    for (int i = 0; i < array->lines + 1; i++) {
        write_game->count = my_strlen(array->newarr[i]);
        write_game->count2 = my_strlen(array->newarr[i]);
        if (LINES < array->lines || COLS < write_game->count2) {
            clear();
            attron(COLOR_PAIR(1));
            mvprintw((LINES / 2), (COLS / 3), "Terminal too small.");
            attroff(COLOR_PAIR(1));
        }
        write_map(array, i, write_game);
    }
    if (win_check(array) == 1)
        exit_print_sokoban(array, write_game, 0);
    check_keybinds(array);
    free(write_game);
}

void init_game(void)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    use_default_colors();
    start_color();
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_CYAN, -1);
    init_pair(4, COLOR_MAGENTA, -1);
    init_pair(5, COLOR_WHITE, -1);
}

void map_process(array_t *array)
{
    init_game();
    int constx = COLS;
    int consty = LINES;
    while (TRUE) {
        if (constx != COLS || consty != LINES)
            clear();
        clear();
        game_process(array);
        refresh();
    }
    endwin();
}

char *open_folder(array_t *array, char *filepath, char *buffer, int fd)
{
    struct stat st;
    stat(filepath, &st);
    buffer = malloc(st.st_size + 1);
    read(fd, buffer, st.st_size);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            array->lines++;
    }
    close(fd);
    return buffer;
}

int allocate_map(char *filepath)
{
    array_t *array = malloc(sizeof(array_t));
    int fd = 0;
    char *buffer = NULL;
    array->oldarr = NULL;
    array->newarr = NULL;
    array->lines = 0;
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return -1;
    buffer = open_folder(array, filepath, buffer, fd);
    check_invalid_map(buffer);
    array->oldarr = str_to_wordarray(buffer, array->oldarr, array);
    array->newarr = str_to_wordarray(buffer, array->newarr, array);
    map_process(array);
    free(buffer);
    free(array);
    return 0;
}
