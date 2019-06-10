/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Stock specieref info - Laurie De Faria
*/

#include <stdlib.h>
#include "sbml_parser.h"
#include "my.h"

static reac_specie_t *stock_specieref_info(char *const *code)
{
    reac_specie_t *info = malloc(sizeof(reac_specie_t));

    if (!info)
        return (NULL);
    for (int i = 0; code[i]; i++) {
        if (my_strncmp("stoichiometry", code[i], 13) == 1)
            info->nb = stock_one_tag(code[i]);
        else if (my_strncmp("species", code[i], 7) == 1)
            info->specie = stock_one_tag(code[i]);
    }
    return (info);
}

int stock_specieref(file_t *file, char **tag, int product)
{
    char **code = NULL;
    chainlist_t *save = NULL;
    chainlist_t *new = malloc(sizeof(chainlist_t *));

    if (!new)
        return (ERROR);
    if (product == 1) {
        save = ((reaction_t *)file->reactions->ob)->products;
        new->ob = stock_specieref_info(tag);
        ((reaction_t *)file->reactions->ob)->products = new;
        ((reaction_t *)file->reactions->ob)->products->next = save;
        //printf("SPEREF-> Nb:%s, Specie:%s\n", ((reac_specie_t *)((reaction_t *)file->reactions->ob)->products)->nb, ((reac_specie_t *)((reaction_t *)file->reactions->ob)->products)->specie);//eff
    } else {
        save = ((reaction_t *)file->reactions->ob)->reactants;
        new->ob = stock_specieref_info(tag);
        ((reaction_t *)file->reactions->ob)->reactants = new;
        ((reaction_t *)file->reactions->ob)->reactants->next = save;
        //printf("SPEREF-> Nb:%s, Specie:%s\n", ((reac_specie_t *)((reaction_t *)file->reactions->ob)->reactants)->nb, ((reac_specie_t *)((reaction_t *)file->reactions->ob)->reactants)->specie);//eff
    }
    return (0);
}