/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-loic.tisseyre
** File description:
** convert_int_to_string.c
*/

char *convert_int_to_string(int str, char tot[])
{
    char digit[] = "0123456789";
    char *arg = tot;
    int string = str;
    if (str < 0) {
        *arg++ = '-';
        str = str * -1;
    }
    while (string) {
        arg++;
        string = string / 10;
    }
    *arg = '\0';
    while (str) {
        *--arg = digit[str % 10];
        str = str / 10;
    }
    return tot;
}