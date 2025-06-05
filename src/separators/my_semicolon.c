/*
** EPITECH PROJECT, 2025
** MiniShell2
** File description:
** my_semicolon
*/

#include <stddef.h>
#include "macros.h"
#include "structures.h"
#include "functions.h"

int my_semicolon(char *input, mshell_t *mshell)
{
    char **array = my_str_to_word_array(input, ";");

    for (size_t i = 0; array[i] != NULL; ++i)
        single_command(array[i], mshell);
    free_array(array);
    return DEFAULT_SUCCESS;
}
