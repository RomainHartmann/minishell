/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** main
*/

#include "macros.h"
#include "functions.h"
#include "structures.h"
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int const argc, char *const *argv, char *const *envp)
{
    mshell_t *mshell = malloc(sizeof(mshell_t));
    int rv = DEFAULT_SUCCESS;
    int tmp = 0;

    (void)argv;
    (void)argc;
    if (mshell == NULL)
        return DEFAULT_ERROR;
    init_structs(&mshell, envp);
    while (mshell->exit == false) {
        print_prompt();
        tmp = shell(mshell);
        if (rv == DEFAULT_SUCCESS)
            rv = tmp;
    }
    free_end(mshell);
    return rv != DEFAULT_ERROR ? rv : DEFAULT_SUCCESS;
}
