/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Verification if line is correct - Laurie De Faria
*/

#include <stdlib.h>
#include "my.h"
static const int ERROR = 84;

static int verif_elements(char const *line, char *const *elements)
{
    for (int i = 0; elements[i]; i++) {
        if (search_str(line, elements) != 1)
            return (0);
    }
    return (1);
}

int verif_first_line(char const *line)
{
    int len = my_strlen(line);
    char **elements = {"version=", "encoding=", "standalone=", NULL};

    if (my_strncmp("<?xml ", line, 6) != 1)
        return (ERROR);
    else if (line[len - 2] != '?' || line[len - 1] != '>')
        return (ERROR);
    if (verif_elements(line, elements) != 1)
        return (ERROR);
    return (0);
}

int verif_second_line(char const *line)
{
    int len = my_strlen(line);
    char **elements = {"version=", "xmlns=", "level=", NULL};

    if (my_strncmp("<sbml ", line, 6) != 1)
        return (ERROR);
    else if (line[len - 1] != '>' || line[len - 2] != ' ')
        return (ERROR);
    if (verif_elements(line, elements) != 1)
        return (ERROR);
    return (0);
}

int verif_model(char const *line)
{
    int len = my_strlen(line);
    char **elements = {"name=", "id=", NULL};

    if (my_strncmp("<model ", line, 7) != 1)
        return (ERROR);
    else if (line[len - 2] != ' ' || line[len - 1] != '>')
        return (ERROR);
    if (verif_elements(line, elements) != 1)
        return (ERROR);
    return (0);
}