/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** input
*/

#include "macros.h"
#include "array.h"
#include "functions.h"
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

static bool valid_str(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (is_letter(str[i]) == true)
            return true;
    return false;
}

static void remove_last_char(char *str)
{
    if (str[my_strlen(str) - 1] == '\n')
        str[my_strlen(str) - 1] = '\0';
}

int manage_input(char *input, mshell_t *mshell)
{
    if (valid_str(input) == false)
        return DEFAULT_SUCCESS;
    remove_last_char(input);
    if (contain_char(input, ';') == true)
        return my_semicolon(input, mshell);
    if (contain_char(input, '|') == true)
        return my_pipe(input, mshell);
    return single_command(input, mshell);
}
