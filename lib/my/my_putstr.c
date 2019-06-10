/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** Print a string - Laurie De Faria
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    char a;
    int c = 0;

    a = str[c];
    while ( a != '\0') {
        my_putchar(a);
        c = c + 1;
        a = str[c];
    }
}
