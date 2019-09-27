# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 15:44:50 by akremer           #+#    #+#              #
#    Updated: 2019/09/27 18:18:10 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = libft/libftprintf.a

SRC = src/main.c					\
	  src/hashtag_parsing.c			\
	  src/best.c					\
	  src/graph.c					\
	  src/using_gnl.c				\
	  src/combo.c					\
	  src/combo2.c					\
	  src/algo.c					\
	  src/lst_room.c				\
	  src/set_print.c				\
	  src/verif.c					\
	  src/free.c					\
	  src/test.c

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra

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

debugg:  fclean $(OBJ) lib
	@gcc $(FLAGS) -g $(OBJ) $(LIB) -o $(NAME)

save: fclean
	@rm -rf *.swp
	@git add *
	@git commit -m "Auto-save"
	@git push
