/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** functions
*/

#ifndef FUNCTIONS_H_
    #define FUNCTIONS_H_
    #include "structures.h"
    #include <stdbool.h>
    #include <stddef.h>

int shell(mshell_t *mshell);
char *my_strcpy(char *dest, char const *src);
int srch_cmd(char **, mshell_t *, char *, bool);
int mini_printf(int fd, const char *format, ...);
char *set_path(char *cmd, char *prefix_path);
bool is_alpha(char c);
env_list_t *search_name(char *name, mshell_t *mshell);
int free_input(char **args, char *alloc_path);
bool is_valid_path(char *path);
bool first_contain_char(char const *str, char const c);
bool contain_char(char const *str, char const c);
size_t exec_path(char *cmd, char **args, int child_pid, mshell_t *);
void display_my_env(mshell_t *mshell);
void update_my_env(mshell_t **mshell);
int msg_cmd_not_found(char *cmd);
void free_array(char **args);
char **get_path_array(mshell_t *mshell);
int init_structs(mshell_t **mshell, char *const *envp);
bool edit_in_list(env_list_t *begin, char *name, char *new_value);
int single_command(char *input, mshell_t *mshell);
size_t len_array(char **array);
int my_pipe(char *input, mshell_t *mshell);
int my_semicolon(char *input, mshell_t *mshell);
int my_redirect_out(char *input, mshell_t *mshell);
int my_redirect_in(char *input, mshell_t *mshell);
int my_redirect_here(char *input, mshell_t *mshell);
int my_redirect_append(char *input, mshell_t *mshell);
int cmd_env(char **args, mshell_t *mshell);
int cmd_exit(char **args, mshell_t *mshell);
int cmd_cd(char **args, mshell_t *mshell);
int cmd_setenv(char **args, mshell_t *mshell);
int cmd_unsetenv(char **args, mshell_t *mshell);
void delete_node(env_list_t **list, env_list_t *tmp);
void update_oldpwd(mshell_t *, char *);
void update_pwd(mshell_t *, char *);
void display_list(env_list_t *begin);
void push_to_list(env_list_t **begin, char *name, char *value);
void free_end(mshell_t *mshell);
bool check_error(int status);
bool my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
void print_prompt(void);
int manage_signals(void);
bool is_letter(char c);
char **my_str_to_word_array(char const *str, char const *delims);
bool is_last_char(char const *str, char const c);
int my_put_nbr_length(int fd, int nb, int length);
int manage_input(char *input, mshell_t *mshell);
int my_putstr(int fd, char const *str);
int my_strlen(char const *str);
void my_putchar(int fd, char c);

#endif /* !FUNCTIONS_H_ */
