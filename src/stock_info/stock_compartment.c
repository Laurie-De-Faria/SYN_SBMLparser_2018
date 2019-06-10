/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Stock compartment info - Laurie De Faria
*/

#include <stdlib.h>
#include "sbml_parser.h"
#include "my.h"

static compartment_t *stock_compartment_info(char *const *code)
{
    compartment_t *info = malloc(sizeof(compartment_t));

    if (!info)
        return (NULL);
    for (int i = 0; code[i]; i++) {
        if (my_strncmp("name", code[i], 4) == 1)
            info->name = stock_one_tag(code[i]);
        else if (my_strncmp("id", code[i], 2) == 1)
            info->id = stock_one_tag(code[i]);
    }
    return (info);
}

int stock_compartment(file_t *file, char **tag)
{
    char **code = NULL;
    chainlist_t *save = file->compartments;
    chainlist_t *new = malloc(sizeof(chainlist_t));

    if (!new)
        return (ERROR);
    new->ob = stock_compartment_info(tag);
    if (!new->ob) {
        free(new);
        return (ERROR);
    }
    file->compartments = new;
    file->compartments->next = save;
    printf("COMPARTMENT-> Name:%s, Id:%s\n", ((compartment_t *)file->compartments->ob)->name, ((compartment_t *)file->compartments->ob)->id);//eff
    return (0);
}