/*
** EPITECH PROJECT, 2019
** SYN_SBML_parser_2018
** File description:
** stock file content into array
*/

#include <stdlib.h>
#include "sbml_parser.h"
#include "my.h"

static char **stock_line(char *line)
{
    char *sbml = NULL;

    if (!line)
        return (NULL);
    sbml = my_str_to_word_array(line);
    free(line);
    line = NULL;
    return (sbml);
}

file_t *stock_file(char *name_file)
{
    char **sbml = NULL;
    file_t *file = malloc(sizeof(file_t));
    char *line = NULL;

    if (!file)
        return (NULL);
    //open file
    //première ligne
    while (getline() > 0) {
        sbml = stock_line(line);
        if (!sbml) {
            // free file and line
            return (ERROR);
        }
        //stock dans file l'element de la ligne et ses attributs
    }
}