# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 15:44:50 by akremer           #+#    #+#              #
#    Updated: 2019/06/20 15:49:33 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

LIB = libft/libftprintf.a

SRC = src/main.c

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) lib
	@gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

lib:
	@make -C ./libft/
