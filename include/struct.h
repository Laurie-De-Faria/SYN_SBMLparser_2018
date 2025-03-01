/*
** EPITECH PROJECT, 2019
** SYN_SBML_parser_2018
** File description:
** Structures - Laurie De Faria
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct command_s
{
    int flag_i;
    int flag_e;
    int flag_json;
    char *id;
    char *file;
}command_t;

typedef struct sbml_s
{
    char *xmlns;
    char *version;
    char *level;
}sbml_t;

typedef struct model_s
{
    char *id;
    char *name;
}model_t;

typedef struct chainlist_s
{
    void *ob;
    struct chainlist_s *next;
}chainlist_t;

typedef struct compartment_s
{
    char *name;
    char *id;
}compartment_t;

typedef struct specie_s
{
    char *compartment;
    char *name;
    char *id;
}specie_t;

typedef struct reac_specie_s
{
    char *nb;
    char *specie;
}reac_specie_t;

typedef struct reaction_s
{
    char *reversible;
    char *name;
    char *id;
    chainlist_t *reactants;
    chainlist_t *products;
}reaction_t;

typedef struct file_s
{
    chainlist_t *compartments;
    chainlist_t *species;
    chainlist_t *reactions;
    model_t *model;
    sbml_t *sbml;
}file_t;

#endif /* !STRUCT_H_ */
