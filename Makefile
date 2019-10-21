# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 15:44:50 by akremer           #+#    #+#              #
#    Updated: 2019/10/21 01:32:45 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra

LD_LIBS = -lftprintf -L libft/

HEADER = include/lem_in.h
INCLUDE = -I include -I libft/includes/

SRC_PATH = src/
SRC_NAME = algo.c combo.c free.c hashtag_parsing.c main.c set_print.c \
		   using_gnl.c best.c combo2.c graph.c lst_room.c output.c test.c \
		   verif.c tools.c
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = .obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LIBFT_A = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(FLAGS) $(INCLUDE) $(LD_LIBS) $(OBJ) -o $(NAME)

$(LIBFT_A):
	mkdir -p $(OBJ_PATH)
	make -C ./libft/

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)
	$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) -rf $(OBJ_PATH)
	make clean -C ./libft/

fclean: clean
	$(RM) -rf $(NAME)
	make fclean -C ./libft/

re: fclean all

one: all
	@sh tests/one.sh

ten: all
	@sh tests/ten.sh

thousand: all
	@sh tests/thousand.sh

big: all
	@sh tests/big.sh

big_sup: all
	@sh tests/big_sup.sh

save: fclean
	@rm -rf *.swp
	@git add .
	@git commit -m "Auto-save"
	@git push

penis:
	@sh map/penis.sh

.PHONY: all clean $(NAME) fclean re save
