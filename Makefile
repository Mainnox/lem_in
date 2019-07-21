# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 15:44:50 by akremer           #+#    #+#              #
#    Updated: 2019/07/21 09:36:29 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

LIB = libft/libftprintf.a

SRC = src/main.c					\
	  src/lst_room.c				\
	  src/verif.c					\
	  src/test.c

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) lib
	@gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

lib:
	@make -C ./libft/

clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft/

fclean: clean
	@rm -rf ./$(NAME)
	@make fclean -C ./libft/

re: fclean all

save: fclean
	@rm -rf *.swp
	@git add *
	@git commit -m "Auto-save"
	@git push
