/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Main - Laurie De Faria
*/

#include <stdlib.h>
#include "sbml_parser.h"
#include "my.h"

static void display_help(void)
{
    my_putstr("USAGE\n\t./SBMLparser SBMLfile [-i ID [-e]] [-json]\n\n");
    my_putstr("DESCRIPTION\n\tSBMLfile\tSBML file\n\t-i ID\tid of the ");
    my_putstr("compartment, reaction or product to be extracted\n\t\t");
    my_putstr("(ignored if uncorrect)\n\t-e\tprint the equation if a ");
    my_putstr("reaction ID is given as argument (ignored otherwise)\n");
    my_putstr("\t-json\ttransform the file into a JSON file\n");
}

static command_t *manage_error(int ac, char *const *av)
{
    command_t *command = NULL;

    if (ac < 2)
        return (NULL);
    if (ac == 2 && my_strcmp(av[1], "-h") == 1) {
        display_help();
        command = malloc(sizeof(command_t));
        command->file = my_strdup("End");
        return (command);
    }
    command = parsing_command(av);
    if (!command)
        return (NULL);
}

int main(int ac, char *const *av)
{
    command_t *command = NULL;
    file_t *file = NULL;

    command = manage_error(ac, av);
    if (!command)
        return (ERROR);
    else if (my_strcmp(command->file, "End") == 1) {
        free(command->file), free(command);
        return (0);
    }
    file = stock_file(command->file);
    if (!file) {
        // free command
        return (ERROR);
    }
    // fonctions affichage selon les flags
}