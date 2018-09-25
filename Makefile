# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmotala <pmotala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/06 16:47:52 by pmotala           #+#    #+#              #
#    Updated: 2018/08/30 15:17:19 by pmotala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
PATH_SRC = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = rtv1.h

SRC =	main.c \
		vector_math.c \
		vector_math2.c \
		store_scene.c \
		get_scene.c \
		keyboard.c \
		functions.c \
		raytracing.c \
		intersections.c \
		tools.c \
		lighting.c \

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	make clean

.PHONY: clean fclean

norme:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(HEAD)
	make -C libft/ norme

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	
re: fclean all
