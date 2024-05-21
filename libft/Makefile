# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 12:09:25 by paribeir          #+#    #+#              #
#    Updated: 2024/02/02 14:21:58 by paribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
ft_substr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
ft_putendl_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
ft_if.c ft_mapping.c ft_print_char.c ft_printf.c ft_putchar.c \
ft_setflags.c ft_isdigit_int.c ft_print_string.c ft_putstr.c \
ft_strlen_int.c ft_print_pointer.c ft_print_int.c ft_itoa_printf.c \
ft_sign.c ft_minus.c ft_zero.c ft_width.c ft_precision.c ft_print_unsigned.c \
ft_print_hexlow.c ft_print_hexup.c ft_hex.c ft_strlcpy_int.c \
get_next_line.c get_next_line_utils.c 


OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
OPTIONS = -c

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(FLAGS) $(OPTIONS) $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

bonus: $(NAME)
	ar rc $(NAME)
	
re: fclean all

.PHONY: all clean fclean re 
