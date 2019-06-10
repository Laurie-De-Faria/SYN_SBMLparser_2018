/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Structures - Laurie De Faria
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct command_s
{
    int flag_i;
    int flag_json;
    int flag_e;
    char *name;
    char *id;
}command_t;

typedef struct compartment_s
{
    char *name;
    char *id;
}compartment_t;

typedef struct chainlist_s
{
    void *obj;
    struct chainlist_s *next;
}chainlist_t;

typedef struct file_s
{
    chainlist_t *compartments;
    chainlist_t *species;
    chainlist_t *reactions;
}file_t;

#endif /* !STRUCT_H_ */
