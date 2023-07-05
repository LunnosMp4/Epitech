/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-enzo.daumalle
** File description:
** signal_handler.c
*/

#include "my_sh.h"

void sign_handler(int sign_num)
{
    if (WIFSIGNALED(sign_num)) {
        if (WTERMSIG(sign_num) == SIGFPE)
            fprintf(stderr, "%s", "Floating exception");
        else
            fprintf(stderr, "%s", strsignal(sign_num));
        if (WCOREDUMP(sign_num))
            fprintf(stderr, " (core dumped)\n");
        else
            my_putchar('\n');
    }
    if (sign_num == SIGTSTP)
        my_putstr(HEADER);
    if (sign_num == SIGINT)
        my_putstr(HEADER);
}
