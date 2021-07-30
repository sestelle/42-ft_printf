# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 13:35:21 by sestelle          #+#    #+#              #
#    Updated: 2021/01/19 12:41:43 by sestelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		libft.a
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra -I ./
SRC=		ft_atoi.c			ft_isdigit.c		ft_itoa.c \
			ft_putchar.c		ft_strchr.c			ft_strlen.c \
			ft_strdup.c			ft_putstr.c			ft_strjoin.c \
			ft_memset.c			ft_uitoa.c
OBJ=		$(SRC:.c=.o)

$(NAME): libft.h
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
