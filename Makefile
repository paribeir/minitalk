# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paribeir <paribeir@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 14:52:47 by paribeir          #+#    #+#              #
#    Updated: 2024/03/03 20:35:47 by paribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

LIBFT = ../libft/libft.a
CC = cc
FLAGS = -Wall -Werror -Wextra
OPTIONS = -c -g
RM = rm -f

all: $(NAME)

$(NAME): server client

server: $(SERVER_OBJ)
	$(CC) $(FLAGS) $(OPTIONS) $(SERVER_OBJ) -o $(SERVER) -Llibft -lft

client: $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(OPTIONS) $(CLIENT_OBJ) -o $(CLIENT) -Llibft -lft

%.o : %.c
	$(CC) $(FLAGS) $(OPTIONS) $< -o $@

libft:
	@make -C ./libft

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
	@make clean -C ./libft

fclean: clean
	@make fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re server client