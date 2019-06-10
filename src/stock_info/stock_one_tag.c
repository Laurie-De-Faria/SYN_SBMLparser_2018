/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** Stock one tag in line - Laurie De Faria
*/

#include <stdlib.h>

static int determine_len(char *tag)
{
    int len = 0;
    int ref = 0;

    while (tag[ref] != '=')
        ref++;
    ref++;
    while (tag[ref] != '\0') {
        ref++;
        len++;
    }
    return (len);
}

char *stock_one_tag(char *tag)
{
    int len = determine_len(tag);
    char *result = malloc(sizeof(char) * (len + 1));

    if (!result)
        return (NULL);
    for (; *tag != '='; tag++);
    tag++;
    for (int i = 0; i < len; i++, tag++)
        result[i] = *tag;
    result[len] = '\0';
    return (result);
}