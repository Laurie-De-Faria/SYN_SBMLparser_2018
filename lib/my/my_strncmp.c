/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** Compare n character of two strings - Laurie De Faria
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int count = 0; count < n; count++) {
        if (*s1 == '\0' || *s2 == '\0')
            count = n;
        if (*s1 == *s2)
            s1++, s2++;
        else
            return (0);
    }
    if ((*s1 == '\0' && *s2 != '\0') || (*s1 != '\0' && *s2 == '\0'))
        return (0);
    else
        return (1);
}
