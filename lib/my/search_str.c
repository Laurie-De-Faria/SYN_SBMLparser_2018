/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Search if a string is in another - Laurie De Faria
*/

int search_str(char const *str, char const *find)
{
    char const *save = find;

    while (*str != '\0')
    {
        if (*str == *find)
            find++;
        str++;
        if (*find == '\0')
            return (1);
    }
    return (0);
}
