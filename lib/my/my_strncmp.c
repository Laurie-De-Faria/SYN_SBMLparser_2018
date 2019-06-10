/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** Compare n character of two strings - Laurie De Faria
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (!s1 || !s2 || n <= 0) {
        return (84);
    } else if (my_strlen(s1) < n || my_strlen(s2) < n) {
        return (84);
    }
    for (int count = 0; count < n; count++) {
        if (*s1 == *s2)
            s1++, s2++;
        else
            return (0);
    }
    return (1);
}
