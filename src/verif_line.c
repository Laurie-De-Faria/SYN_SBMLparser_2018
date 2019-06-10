/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Verification if line is correct - Laurie De Faria
*/

#include "my.h"
static const int ERROR = 84;

int verif_first_line(char const *line)
{
    int len = my_strlen(line);

    if (my_strncmp("<?xml ", line, 6) != 1)
        return (ERROR);
    else if (line[len - 2] != '?' || line[len - 1] != '>')
        return (ERROR);
    //verif version, encoding, standalone présents
}

int verif_second_line(char const *line)
{
    int len = my_strlen(line);

    if (my_strncmp("<sbml ", line, 6) != 1)
        return (ERROR);
    else if (line[len - 1] != '>' || line[len - 2] != ' ')
        return (ERROR);
    //verif version, level, xmlns présents
}