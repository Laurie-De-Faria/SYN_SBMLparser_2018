/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Verification if line is correct - Laurie De Faria
*/

#include <stdlib.h>
#include "my.h"
#include "sbml_parser.h"

static int verif_elements(char const *line, char *const *elements)
{
    if (!line || !elements)
        return (ERROR);
    for (int i = 0; elements[i]; i++) {
        if (search_str(line, elements[i]) != 1)
            return (0);
    }
    return (1);
}

static char *read_line(FILE *fd)
{
    char *line = NULL;
    size_t useless = 0;

    if (getline(&line, &useless, fd) == 0)
            return (NULL);
    line[my_strlen(line) - 1] = '\0';
    return (line);
}

int verif_first_line(FILE *fd)
{
    char **elements = malloc(sizeof(char *) * 4);
    char *line = NULL;
    int len = 0;

    elements[0] = "version=";
    elements[1] = "encoding=";
    elements[2] = "standalone=";
    elements[3] = NULL;
    line = read_line(fd);
    if (!line)
        return (ERROR);
    len = my_strlen(line);
    if (my_strncmp("<?xml ", line, 6) != 1) {
        return (ERROR);
    } else if (line[len - 2] != '?' || line[len - 1] != '>')
        return (ERROR);
    if (verif_elements(line, elements) != 1)
        return (ERROR);
    free(elements);
    return (0);
}
