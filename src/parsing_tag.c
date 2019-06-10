/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Parsing line SBML - Laurie De Faria
*/

#include <stdlib.h>
int my_strlen(char const *str);

static int determine_len_tag(char const *line, int index)
{
    int len = 1;
    int separator = 0;
    int max = my_strlen(line);

    for (int i = index - 1; line[i] != ' ' && i >= 0; i--) {
        len++;
    }
    for (int i = index + 1; line[i] != '"' || separator != 1 && i < max; i++) {
        if (line[i] == '"')
            separator = 1;
        len++;
    }
    return (len);
}

static char *stock_tag(char const *line, int index)
{
    int len = determine_len_tag(line, index);
    char *tag = malloc(sizeof(char) * (len + 1));
    int ref = index;
    int count = 0;
    int separator = 0;
    int max = my_strlen(line);

    if (!tag)
        return (NULL);
    for (ref = index; line[ref] != ' ' && ref >= 0; ref--);
    if (ref != 0)
        ref++;
    for (count = 0; (line[ref] != '"' || separator != 1) && ref < max; ref++) {
        if (line[ref] == '"')
            separator++;
        else {
            tag[count] = line[ref];
            count++;
        }
    }
    tag[len] = '\0';
    return (tag);
}

static int determine_nb_lines(char const *str)
{
    int nb_tag = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '=')
            nb_tag++;
    }
    return (nb_tag);
}

char **parsing_tag(char const *str)
{
    char **result = NULL;
    int nb_line = determine_nb_lines(str);
    int count = 0;

    result = malloc(sizeof(char *) * (nb_line + 1));
    for (int i = 0; str[i] != '\0' && count < nb_line; i++) {
        if (str[i] == '=') {
            result[count] = stock_tag(str, i);
            count++;
        }
        if (count > 0 && !result[count - 1])
            return (NULL);
    }
    result[nb_line] = NULL;
    return (result);
}
