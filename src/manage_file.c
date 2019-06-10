/*
** EPITECH PROJECT, 2019
** SYN_SBML_parser_2018
** File description:
** stock file content into array
*/

#include <stdlib.h>
#include "sbml_parser.h"
#include "my.h"

static int find_element2(file_t *file, char const *line, char **tag)
{
    static int product = -1;

    while (*line == ' ' || *line == '\t')
            line++;
    if (my_strncmp("<listOfReactants>", line, 17) == 1) {
        product = 0;
    } else if (my_strncmp("<listOfProducts>", line, 16) == 1)
        product = 1;
    if (my_strncmp("<speciesReference ", line, 18) == 1) {
        return (stock_specieref(file, tag, product));
    }
}

static int find_element(file_t *file, char const *line, char **tag)
{
    char *elements[6] = {"<sbml ", "<model ", "<compartment ", "<species ",\
                        "<reaction ", NULL};
    int (*listFunctions[5])(file_t *, char **) = {stock_sbml, stock_model,
        stock_compartment, stock_specie, stock_reaction};
    int return_value = 0;

    for (int i = 0; elements[i]; i++) {
        while (*line == ' ' || *line == '\t')
            line++;
        if (my_strncmp(elements[i], line, my_strlen(elements[i])) == 1)
            return_value = listFunctions[i](file, tag);
        if (return_value == ERROR) {
            //free file
            return (ERROR);
        }
    }
    find_element2(file, line, tag);
    return (0);
}

// ATTENTION : TOO LONG FUNCTION
static file_t *stock_file(FILE *fd)
{
    file_t *file = malloc(sizeof(file_t));
    char **tags = NULL;
    char *line = NULL;
    size_t useless = 0;

    if (!file)
        return (NULL);
    while (getline(&line, &useless, fd) > 0) {
        line[my_strlen(line) - 1] = '\0';
        tags = parsing_tag(line);
        printf("--------Line:%s\n", line);//eff
        if (!tags) {
            // free file and line + close fd
            return (NULL);
        }
        if (find_element(file, line, tags) == ERROR) {
            //free tag + line
            return (NULL);
        }
        //free tag
    }
    free(line);
    return (file);
}

static int verif_line_one(FILE *fd)
{
    if (verif_first_line(fd) == ERROR) {
        fclose(fd);
        return (ERROR);
    }
    return (0);
}

file_t *manage_file(char *name_file)
{
    file_t *file = NULL;
    FILE *fd = 0;

    fd = fopen(name_file, "r");
    if (!fd)
        return (NULL);
    if (verif_line_one(fd) == ERROR)
        return (NULL);
    file = stock_file(fd);
    printf("File compartment id:%s\n", ((compartment_t *)file->compartments)->id);//eff
    if (!file) {
        fclose(fd);
        return (NULL);
    }
    fclose(fd);
    return (file);
}