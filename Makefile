# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 15:14:41 by sestelle          #+#    #+#              #
#    Updated: 2021/01/19 12:33:56 by sestelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		libftprintf.a
INCLUDES=	includes
PARSERDIR=	ft_read_args
PUTDIR=		ft_conversion
LIBFTDIR=	libft
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra -I ./includes
SRC=		ft_printf.c			$(PUTDIR)/ft_conversion.c		$(PUTDIR)/ft_put_char.c		$(PUTDIR)/ft_put_percentage.c \
								$(PUTDIR)/ft_conversion_utils.c $(PUTDIR)/ft_put_str.c		$(PUTDIR)/ft_put_int.c \
								$(PUTDIR)/ft_put_x.c $(PUTDIR)/ft_put_pointer.c $(PUTDIR)/ft_put_uint.c \
								$(PARSERDIR)/ft_read_args.c		$(PARSERDIR)/ft_read_args_utils.c
OBJ=		$(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/libft.a libftprintf.a
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	make -C $(LIBFTDIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
