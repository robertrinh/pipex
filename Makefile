# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/01 15:08:12 by qtrinh        #+#    #+#                  #
#    Updated: 2023/03/16 15:42:44 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := pipex

CC := gcc
CFLAGS := -Wall -Werror -Wextra -g #delete -g?
# AR := ar -src

SRCS := pipex.c \
		error.c \

OBJ := $(SRCS:.c=.o)

#COLORS SHOW
BOLD_GREEN=\033[1;92m
BOLD_RED=\033[1;91m
RED=\033[0;31m
PURPLE=\033[0;35m
YELLOW=\033[0;33m
INTENSE_CYAN=\033[0;96m
END_COLOUR=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && (MAKE)
	@$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@echo "${RED}compiling? ${BOLD_GREEN} Completed it mate ${END_COLOUR}"

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft
	@echo "${INTENSE_CYAN}library..? ${BOLD_GREEN}LIBRARY..? ${BOLD_RED}LIBRARY!!!"

re: fclean all

.PHONY: all clean fclean re
