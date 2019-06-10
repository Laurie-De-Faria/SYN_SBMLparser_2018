/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** Determine lenght of a string - Laurie De Faria
*/

int my_strlen(char const *str)
{
    int count = 0;

    if (!str)
        return (-1);
    while (*str && *str != '\0') {
        count = count + 1;
        str++;
    }
    return (count);
}
