# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 20:06:32 by amakela           #+#    #+#              #
#    Updated: 2024/02/01 19:47:58 by amakela          ###   ########.fr        #
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
	./push_swap -50-	123

clean:
	rm -f $(OFILES)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
