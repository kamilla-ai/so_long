# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 17:38:34 by kamillarazi       #+#    #+#              #
#    Updated: 2024/07/04 15:49:44 by krazikho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit
MAIN = *.c
MINILIBX = minilibx
LIBRARY = -Lminilibx -lmlx
GNL = gnl/*.c
PRINTF = ft_printf/*.c

all: $(NAME)

$(NAME):
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(MAIN) $(GNL) $(PRINTF) $(LIBRARY) $(MLXFLAGS) -o $(NAME)

clean:
	make clean -C $(MINILIBX)

fclean: clean
	rm -rf $(NAME)

re: fclean all
