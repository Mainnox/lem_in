# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 15:44:50 by akremer           #+#    #+#              #
#    Updated: 2019/11/11 01:56:09 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra

LD_LIBS = -lftprintf -L libft/

MLX_LD_LIBS = -lmlx -L minilibx_macos/ -framework AppKit -framework OpenGl

HEADER = include/lem_in.h
INCLUDE = -I include -I libft/includes/ -I minilibx_macos/

SRC_PATH = src/
SRC_NAME = test.c main.c parsing.c pars_room.c pars_edge.c graph.c tools.c \
		   algo.c combo.c combo2.c best.c set_print.c output.c free.c visu.c \
		   bresenham.c left_octant_bresenham.c right_octant_bresenham.c \
		   pannel.c init_visu.c background.c ants_movement.c push_swap.c 

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = .obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LIBFT_A = libft/libft.a

LIBMLX_A = minilibx_macos/libmlx.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(FLAGS) $(INCLUDE) $(MLX_LD_LIBS) $(LD_LIBS) $(OBJ) -o $(NAME)

$(LIBMLX_A):
	make -C minilibx_macos/

$(LIBFT_A):
	mkdir -p $(OBJ_PATH)
	make -C libft/

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)
	$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) -rf $(OBJ_PATH)
	make clean -C ./libft/
	#make clean ./minilibx_macos/

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
