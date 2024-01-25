# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 20:06:32 by amakela           #+#    #+#              #
#    Updated: 2024/01/25 17:42:47 by amakela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

LIBFTDIR = libft

CC = gcc -g

CFILES = main.c				input_utils.c		split_to_ints.c		stack_utils.c	\
		 instructions.c		push_swap.c			push_swap_utils.c	sort_three.c	\
		 sort_five.c		values_utils.c		rotation_utils.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o push_swap $(OFILES) $(LIBFTDIR)/$(LIBFT)
	./push_swap -7 -8 -6 -5 -4

clean:
	rm -f $(OFILES)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
