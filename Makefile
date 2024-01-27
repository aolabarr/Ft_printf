# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 13:37:39 by aolabarr          #+#    #+#              #
#    Updated: 2024/01/27 13:53:53 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rc

SRC =	ft_printf.c \
		funcs_manager.c funcs_aux_1.c funcs_aux_2.c \
		ft_itoa.c ft_itoahex.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) *.out

re: fclean all

.PHONY: all clean fclean re
