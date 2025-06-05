/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** desc
*/

#include "functions.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *res = NULL;

    if (src == NULL)
        return NULL;
    res = malloc(sizeof(char) * my_strlen(src) + 1);
    if (res == NULL)
        return NULL;
    my_strcpy(res, src);
    res[my_strlen(src)] = '\0';
    return (res);
}
