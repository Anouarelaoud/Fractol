# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 21:33:47 by aait-el-          #+#    #+#              #
#    Updated: 2019/07/24 19:09:38 by aait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIB = libft/libft.a
OBJ = src/get_next_line.o src/main.o src/atoi_base.o src/draw.o src/gestion.o 
OBJ += src/mouse_key.o src/type_fract_1.o src/type_fract_2.o src/win_img.o
FLAG = -Wall -Wextra -Werror
MLX_LIB = -lmlx -framework OpenGL -framework AppKit

LIB_PATH = libft
INC_DIR = inc
SRC_DIR = src

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@gcc $(FLAG) -I $(INC_DIR) $(OBJ) $(LIB) $(MLX_LIB) -o $(NAME)

$(OBJ): %.o : %.c
	@gcc $(FLAG) -I $(INC_DIR) -c $< -o $@
$(LIB):
	@make -C $(LIB_PATH)
clean:
	@make clean -C $(LIB_PATH)
	@rm -f $(SRC_DIR)/*.o

fclean: clean
	@make fclean -C $(LIB_PATH)
	@/bin/rm -f $(NAME)

re: fclean all
