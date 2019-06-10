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
#include "struct.h"

// -- SRC -- //
char **my_str_to_word_array(char const *str);
command_t *parsing_command(char *const *av);

#endif /* !SBML_PARSER_H_ */
