/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** shell
*/

#include "macros.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static int error(char *buff, bool exit, mshell_t *mshell, int return_value)
{
    if (exit == true)
        mshell->exit = true;
    free(buff);
    return return_value;
}

int shell(mshell_t *mshell)
{
    int return_value = DEFAULT_SUCCESS;
    char *buff = NULL;
    size_t len = 0;

    manage_signals();
    if (getline(&buff, &len, stdin) == -1) {
        if (errno == 0)
            write(1, "\n", 1);
        return error(buff, true, mshell, return_value);
    }
    return_value = manage_input(buff, mshell);
    if (return_value == DEFAULT_ERROR)
        return error(buff, false, NULL, return_value);
    free(buff);
    return return_value;
}
