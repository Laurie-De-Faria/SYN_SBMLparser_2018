/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Stock specie info - Laurie De Faria
*/

#include <stdlib.h>
#include "sbml_parser.h"
#include "my.h"

static specie_t *stock_specie_info(char *const *code)
{
    specie_t *info = malloc(sizeof(specie_t));

    if (!info)
        return (NULL);
    for (int i = 0; code[i]; i++) {
        if (my_strncmp("name", code[i], 4) == 1)
            info->name = stock_one_tag(code[i]);
        else if (my_strncmp("id", code[i], 2) == 1)
            info->id = stock_one_tag(code[i]);
        else if (my_strncmp("compartment", code[i], 11) == 1)
            info->compartment = stock_one_tag(code[i]);
    }
    return (info);
}

int stock_specie(file_t *file, char **tag)
{
    char **code = NULL;
    chainlist_t *save = file->species;
    chainlist_t *new = malloc(sizeof(chainlist_t));

    if (!new)
        return (ERROR);
    new->ob = stock_specie_info(tag);
    if (!new->ob) {
        free(new);
        return (ERROR);
    }
    file->species = new;
    file->species->next = save;
    printf("SPECIES-> Name:%s, Id:%s\nCompartment:%s\n", ((specie_t *)file->species->ob)->name, ((specie_t *)file->species->ob)->id,((specie_t *)file->species->ob)->compartment);//eff
    return (0);
}