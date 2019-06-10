/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** Duplicate a string - Laurie De Faria
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int count = 0;
    char *dup = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (!dup)
        return (NULL);
    for (count = 0; src[count] != '\0'; count++) {
        dup[count] = src[count];
    }
    dup[count] = '\0';
    return (dup);
}
