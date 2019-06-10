/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** stock model - Laurie De Faria
*/

#include <stdlib.h>
#include "sbml_parser.h"
#include "my.h"

static model_t *stock_model_info(char *const *code)
{
    model_t *info = malloc(sizeof(model_t));

    if (!info)
        return (NULL);
    for (int i = 0; code[i]; i++) {
        if (my_strncmp("name", code[i], 4) == 1)
            info->name = stock_one_tag(code[i]);
        else if (my_strncmp("id", code[i], 2) == 1)
            info->id = stock_one_tag(code[i]);
    }
    return (info);
}

int stock_model(file_t *file, char **tag)
{
    char **code = NULL;

    file->model = stock_model_info(tag);
    if (!file->model)
        return (ERROR);
    printf("Model-> name:%s, id:%s\n", file->model->name, file->model->id);//eff
    return (0);
}