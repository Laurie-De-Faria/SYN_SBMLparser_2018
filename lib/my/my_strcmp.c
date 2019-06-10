/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** Compare a string with another - Laurie De Faria
*/

int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return (-1);
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 == *s2)
            s1++, s2++;
        else
            return (0);
    }
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    else
        return (0);
}
