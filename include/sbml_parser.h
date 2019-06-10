/*
** EPITECH PROJECT, 2019
** SYN_SBML_parser_2018
** File description:
** Main header - Laurie De Faria
*/

#ifndef SBML_PARSER_H_
#define SBML_PARSER_H_

// -- VARIABLE -- //
static const int ERROR = 84;

// -- INCLUDE -- //
#include <stdio.h>
#include "struct.h"

// -- SRC -- //
char **my_str_to_word_array(char const *str);
command_t *parsing_command(char *const *av);
file_t *manage_file(char *name_file);

// -- VERIF LINES -- //
int verif_first_line(FILE *fd);
sbml_t *verif_second_line(FILE *fd);
model_t *verif_model(FILE *fd);

// -- STOCKAGE INFORMATIONS -- //
int stock_compartment(file_t *file, char **tag);
int stock_model(file_t *file, char **tag);
int stock_reaction(file_t *file, char **tag);
int stock_sbml(file_t *file, char **tag);
int stock_specie(file_t *file, char **tag);
int stock_specieref(file_t *file, char **tag);
char *stock_one_tag(char *tag);

// -- PARSING -- //
char **parsing_tag(char const *str);

#endif /* !SBML_PARSER_H_ */
