/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** write_exit.c
*/

#include "my_sh.h"

static void print_pwd(env_t *list)
{
    int home_loc = 3;

    if (!list)
        return;
    if (!str_isequal(list->key, "PWD", true) && list->id == ENV) {
        print_pwd(list->next);
        return;
    }
    printf("~");
    for (int i = 0; list->value[i]; i++) {
        if (list->value[i] == '/')
            home_loc -= home_loc == 0 ? 0 : 1;
        if (home_loc == 0)
            printf("%c", list->value[i]);
    }
}

static void display_username(env_t *list)
{
    if (list == NULL)
        return;
    if (!str_isequal(list->key, "USERNAME", true)) {
        display_username(list->next);
        return;
    }
    printf("%s", list->value);
    printf("\033[0;35m");
    printf(":☘ ");
}

static bool re_init(bool *go_print, char const *output)
{
    if (*go_print)
        return false;
    if (output[0] == 'i')
        *go_print = true;
    return *go_print;
}

void final_print(char const *output, env_t *list)
{
    printf("\033[0;31m");
    display_username(list);
    printf("\033[0;32m");
    print_pwd(list);
    printf("\033[0;33m");
    printf("%s", output);
    printf("\033[0m");
}

void p_ntty(char const *output, env_t *list)
{
    static bool go_print = true;

    if (re_init(&go_print, output))
        return;
    if (!go_print)
        return;
    go_print = false;
    if (output[0] == 'i')
        return;
    if (!isatty(STDIN_FILENO))
        return;
    if (str_isequal(output, "exit\n", true)) {
        printf("%s", output);
        return;
    }
    final_print(output, list);
}
