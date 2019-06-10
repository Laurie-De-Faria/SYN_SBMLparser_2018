/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Split a string -> put words into an array - Laurie De Faria
*/

#include <stdlib.h>

static int my_char_is_alphanum(char c)
{
    int result = 0;

    if (c >= '0' && c <= '9')
        return (1);
    else if (c >=  'a' && c <= 'z')
        return (1);
    else if (c >=  'A' && c <= 'Z')
        return (1);
    else
        return (0);
}

static int determine_number_lines(char const *str)
{
    int count = 0;
    int serie_separator = 0;

    if (!str)
        return (-1);
    if (str[0] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_is_alphanum(str[i]) != 1 && serie_separator == 0) {
            count++;
            serie_separator = 1;
        } else if (my_char_is_alphanum(str[i]) == 1)
            serie_separator = 0;
    }
    return (count + 1);
}

static int determine_nb_column(char const *str)
{
    int nb_column = 0;

    if (!str)
        return (-1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_is_alphanum(str[i]) != 1)
            return (nb_column);
        else
            nb_column++;
    }
    return (nb_column);
}

static char *stock_word(char const *str, int index)
{
    int column = 0;
    char *result = NULL;

    if (index == 0)
        while (my_char_is_alphanum(*str) != 1)
            str++;
    for (int count = 0; count < index; str++) {
        if (my_char_is_alphanum(*str) != 1)
            count++;
    }
    column = determine_nb_column(str);
    if (column <= 0)
        return (NULL);
    result = malloc(sizeof(char) * (column + 1));
    for (int i = 0; i < column; i++) {
        result[i] = *str;
        str++;
    }
    return (result);
}

char **my_str_to_word_array_synthesis(char const *str)
{
    int nb_line = 0;
    char **result = NULL;
    int index = 0;

    if (!str)
        return (NULL);
    nb_line = determine_number_lines(str);
    if (nb_line <= 0)
        return (NULL);
    result = malloc(sizeof(char *) * (nb_line + 1));
    if (!result)
        return (NULL);
    for (int i = 0; i < nb_line; i++) {
        result[i] = stock_word(str, index);
        index++;
    }
    result[nb_line] = NULL;
    return (result);
}
