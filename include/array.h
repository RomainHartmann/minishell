/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** array
*/

#ifndef ARRAY_H_
    #define ARRAY_H_
    #include "functions.h"
    #include <stddef.h>

typedef struct builtin_s {
    char *cmd;
    int (*function)(char **args, mshell_t *mshell);
} builtin_t;

static const builtin_t ARRAY_BUILTIN[] = {
    {"env", &cmd_env},
    {"cd", &cmd_cd},
    {"exit", &cmd_exit},
    {"setenv", &cmd_setenv},
    {"unsetenv", &cmd_unsetenv},
    {NULL, NULL}
};

#endif /* !ARRAY_H_ */
