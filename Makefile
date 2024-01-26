# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 20:06:32 by amakela           #+#    #+#              #
#    Updated: 2024/01/26 16:19:21 by amakela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

LIBFTDIR = libft

CC = gcc -g

CFILES = main.c				input_utils.c		split_to_ints.c		stack_utils.c	\
		 instructions.c		push_swap.c			push_swap_utils.c	sort_three.c	\
		 sort_five.c		values_utils.c		rotation_utils.c	sort.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o push_swap $(OFILES) $(LIBFTDIR)/$(LIBFT)
	./push_swap -94837269 -98437 9249327 -29183 -231 -7 2147483647 -824  5 5453 68 685  -6 -2147483648 -95 0 286

clean:
	rm -f $(OFILES)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
