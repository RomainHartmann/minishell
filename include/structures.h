/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** structures
*/

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_
    #include <stdbool.h>

typedef struct env_list_s {
    char *name;
    char *value;
    struct env_list_s *next;
    struct env_list_s *previous;
} env_list_t;

typedef struct mshell_s {
    env_list_t *env_list;
    char **my_env;
    bool exit;
} mshell_t;

#endif /* !STRUCTURES_H_ */
