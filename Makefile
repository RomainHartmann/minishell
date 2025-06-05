##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC ?= gcc

BUILTINS_PATH	=	src/builtins/

SEPARATORS_PATH	=	src/separators/

UTILS_PATH		=	src/utils/

SRC             =   src/main.c								\
					$(UTILS_PATH)/is_letter.c				\
					$(UTILS_PATH)mini_printf.c				\
					$(UTILS_PATH)my_put_nbr_length.c		\
					$(UTILS_PATH)my_putstr.c				\
					$(UTILS_PATH)my_strlen.c				\
					$(UTILS_PATH)my_str_to_word_array.c		\
					$(UTILS_PATH)my_strcmp.c				\
					$(UTILS_PATH)my_strdup.c				\
					$(UTILS_PATH)my_strcpy.c				\
					$(UTILS_PATH)my_strcat.c				\
					$(UTILS_PATH)is_alpha.c					\
					$(UTILS_PATH)contain.c					\
					$(BUILTINS_PATH)cmd_env.c				\
					$(BUILTINS_PATH)cmd_exit.c				\
					$(BUILTINS_PATH)cmd_cd.c				\
					$(BUILTINS_PATH)cmd_setenv.c			\
					$(BUILTINS_PATH)cmd_unsetenv.c			\
					$(SEPARATORS_PATH)my_pipe.c				\
					$(SEPARATORS_PATH)my_semicolon.c		\
					$(SEPARATORS_PATH)my_redirect_here.c	\
					$(SEPARATORS_PATH)my_redirect_append.c	\
					$(SEPARATORS_PATH)my_redirect_out.c		\
					$(SEPARATORS_PATH)my_redirect_in.c		\
					src/error_messages.c					\
					src/command.c							\
					src/pwd_and_oldpwd.c					\
					src/init_structs.c						\
					src/my_env_array.c						\
					src/search_cmds.c						\
					src/list.c								\
					src/free_all.c							\
					src/prompt.c							\
					src/input.c								\
					src/signals.c							\
					src/shell.c

NAME = mysh

CPPFLAGS = -iquote include

CFLAGS += -Wall -Wextra -Werror

OBJDIR = build

OBJ = $(SRC:src/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)
clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: re

.PHONY: all clean fclean re debug \
