/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** Print a character - Laurie De Faria
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
