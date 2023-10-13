# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/01 15:08:12 by qtrinh        #+#    #+#                  #
#    Updated: 2023/10/13 14:49:05 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := pipex

CC := gcc
CFLAGS := -Wall -Werror -Wextra -g #gflag for debug
HEADER := include/pipex.h
INCLUDE := -I include
OBJDIR = objects

SRC := error.c \
		main.c \
		parse.c \
		pipex.c \
		utils.c \

vpath %.c	src
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

#COLORS SHOW
BOLD_GREEN=\033[1;92m
BOLD_RED=\033[1;91m
RED=\033[0;31m
PURPLE=\033[0;35m
YELLOW=\033[0;33m
GRAY=\033[0;37m
INTENSE_CYAN=\033[0;96m
END_COLOUR=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && $(MAKE)
	@$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@echo "${RED}compiling? ${BOLD_GREEN}completed it mate ${END_COLOUR}"

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJDIR)
	@echo "${RED} assembling ${GRAY}pijpen..${INTENSE_CYAN}$<${YELLOW}ccccc ${END_COLOUR}"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft
	@echo "${BOLD_GREEN}we out here ${END_COLOUR}"

re: fclean all

.PHONY: all clean fclean re
