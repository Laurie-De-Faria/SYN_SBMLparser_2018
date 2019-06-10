/*
** EPITECH PROJECT, 2019
** SYN_SBML_parser_2018
** File description:
** parsing command - Laurie De Faria
*/

#include <stdlib.h>
#include "sbml_parser.h"
#include "my.h"

static int name_file(char const *file)
{
    int count = 0;
    int result = 0;

    while (file[count] != '.')
        count++;
    count++;
    if (file[count] == 's' && file[count + 1] =='b')
        if (file[count + 2] == 'm' && file[count + 3] =='l')
            result = 1;
    if (result == 1 && file[count + 4] == '\0')
        return (1);
    else
        return (0);
}

static int stock_flag_i(char const *id, command_t *action)
{
    action->flag_i = 1;
    if (!id)
        return (ERROR);
    else if (id[0] == '\0' || id[0] == '-')
        return (ERROR);
    action->id = my_strdup(id);
    return (0);
}

static int parsing_command2(command_t *action, char const *actual,
char const *next, int *count)
{
    if (my_strcmp(actual, "-i") == 1) {
        if (stock_flag_i(next, action) == ERROR) {
            free(action->file);
            free(action);
            return (ERROR);
        }
        (*count)++;
    } else if (my_strcmp(actual, "-json") == 1)
        action->flag_json = 1;
    else if (my_strcmp(actual, "-e") == 1)
        action->flag_e = 1;
    else 
        return (ERROR);
}

command_t *parsing_command(char *const *av)
{
    command_t *action = malloc(sizeof(command_t));
    int error = 0;

    if (!action || name_file(av[1]) != 1)
        return (NULL);
    action->file = my_strdup(av[1]);
    for (int i = 2; av[i]; i++) {
        if (parsing_command2(action, av[i], av[i + 1], &i) == ERROR)
            return (NULL);
    }
    return (action);
}
