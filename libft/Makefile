# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/04 17:09:25 by qtrinh        #+#    #+#                  #
#    Updated: 2023/03/16 16:08:56 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
NAME := libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror
AR := ar -src

SRCS := ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_printf.c \
		ft_printf_hex.c \
		ft_printf_pointer.c \
		ft_printf_stuff.c \
		ft_printf_unsigned.c \
		get_next_line.c \
		get_next_line_utils.c \

BSRCS := ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \

OBJ := $(SRCS:.c=.o)
OBJ_B := $(BSRCS:.c=.o)

ifdef WITH_BONUS
OBJ_FILES = $(OBJ) $(OBJ_B)
else
OBJ_FILES = $(OBJ)
endif

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

$(NAME): $(OBJ_FILES)
	@$(AR) $(NAME) $(OBJ_FILES)

%.o: %.c 
	@echo "${RED} compiling ${GRAY}libft.. ${PURPLE}bliep.. bloep.. ${INTENSE_CYAN}$<${YELLOW}ccccc ${END_COLOUR}"
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_B)

fclean: clean
	@rm -f $(NAME)

re: fclean all bonus

bonus:
	@$(MAKE) WITH_BONUS=1 all
