/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Stock info about sbml - Laurie De Faria
*/

#include <stdlib.h>
#include "sbml_parser.h"
#include "my.h"

static sbml_t *stock_sbml_info(char *const *code)
{
    sbml_t *info = malloc(sizeof(sbml_t));

    if (!info)
        return (NULL);
    for (int i = 0; code[i]; i++) {
        if (my_strncmp("xmlns", code[i], 5) == 1)
            info->xmlns = stock_one_tag(code[i]);
        else if (my_strncmp("level", code[i], 5) == 1)
            info->level = stock_one_tag(code[i]);
        else if (my_strncmp("version", code[i], 7) == 1)
            info->version = stock_one_tag(code[i]);
    }
    return (info);
}

int stock_sbml(file_t *file, char **tag)
{
    char **code = NULL;

    file->sbml = stock_sbml_info(tag);
    if (!file->sbml)
        return (ERROR);
    printf("SBML-> level:%s, version:%s\nxmls:%s\n", file->sbml->level, file->sbml->version, file->sbml->xmlns);//eff
    return (0);
}