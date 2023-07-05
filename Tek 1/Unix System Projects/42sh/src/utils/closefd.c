/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-enzo.daumalle
** File description:
** closefd.c
*/

#include "my_sh.h"

void closefd(int fd[2])
{
    if (fd[IN] != STDIN_FILENO)
        close(fd[IN]);
    if (fd[OUT] != STDOUT_FILENO)
        close(fd[OUT]);
}
