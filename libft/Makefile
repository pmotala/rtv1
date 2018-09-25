# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmotala <pmotala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 15:02:15 by pmotala           #+#    #+#              #
#    Updated: 2018/08/30 14:43:50 by pmotala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GCFLAGS = gcc -Wall -Wextra -Werror

INC = ./libft.h

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_fzero.c \

SRC2=	ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_sizecheck.c \
		ft_sign.c \
		ft_wdlen.c \
		ft_strcnt.c \
		ft_lstrev.c \
		ft_lst_ignorecomments.c \
		ft_rm_char.c \
		ft_atoi_n.c \
		get_next_line.c \
		ft_strjoin_free.c \

OBJ = $(SRC:%.c=%.o)

OBJ2 = $(SRC2:%.c=%.o)

all: $(NAME)

$(NAME):
	$(GCFLAGS) -c -I $(INC) $(SRC) $(SRC2)
	ar rc $(NAME) $(OBJ) $(OBJ2)
	ranlib $(NAME)

norme:
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckForbiddenSourceHeader $(SRC2)
	norminette -R CheckForbiddenSourceHeader *.h

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ2)

fclean: clean 
	rm -rf $(NAME)

re: fclean all
