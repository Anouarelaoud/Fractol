# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 20:25:21 by aait-el-          #+#    #+#              #
#    Updated: 2019/04/18 17:15:32 by aait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
		@gcc -c -Wall -Wextra -Werror *.c -I .
			@ar rc $(NAME) *.o
				@ranlib $(NAME)

clean:
		@rm -f *.o

fclean: clean
		@rm -f $(NAME)

re: fclean all
