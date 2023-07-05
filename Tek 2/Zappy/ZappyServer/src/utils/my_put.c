/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** my_put
*/

#include "server.h"

void my_putstr(const char *str)
{
    const char* p = str;
    while (*p != '\0') {
        putchar(*p);
        p++;
    }
}
