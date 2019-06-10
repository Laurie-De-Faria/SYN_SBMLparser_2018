/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Stock specie info - Laurie De Faria
*/

#include <stdlib.h>
#include "sbml_parser.h"
#include "my.h"

static reaction_t *stock_reaction_info(char *const *code)
{
    reaction_t *info = malloc(sizeof(specie_t));

    if (!info)
        return (NULL);
    for (int i = 0; code[i]; i++) {
        if (my_strncmp("name", code[i], 4) == 1)
            info->name = stock_one_tag(code[i]);
        else if (my_strncmp("id", code[i], 2) == 1)
            info->id = stock_one_tag(code[i]);
        else if (my_strncmp("reversible", code[i], 10) == 1)
            info->reversible = stock_one_tag(code[i]);
    }
    return (info);
}

int stock_reaction(file_t *file, char **tag)
{
    char **code = NULL;
    chainlist_t *save = file->reactions;
    chainlist_t *new = malloc(sizeof(chainlist_t));

    if (!new)
        return (ERROR);
    new->ob = stock_reaction_info(tag);
    if (!new->ob) {
        free(new);
        return (ERROR);
    }
    file->reactions = new;
    file->reactions->next = save;
    printf("REACTION-> Name:%s, Id:%s, Reversible:%s\n", ((reaction_t *)file->reactions->ob)->name, ((reaction_t *)file->reactions->ob)->id,((reaction_t *)file->reactions->ob)->reversible);//eff
    return (0);
}