/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-loic.tisseyre
** File description:
** my_flags.c
*/

int my_get_octal(unsigned int arg)
{
    int oct = 0;
    int i = 1;

    for (arg; arg != 0; arg /= 8) {
        oct = oct + (arg % 8) * i;
        i = i* 10;
    }
    return oct;
}
