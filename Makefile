# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 20:06:32 by amakela           #+#    #+#              #
#    Updated: 2024/02/03 21:14:22 by amakela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

LIBFTDIR = libft

CC = cc

CFILES = push_swap.c		input_utils.c		split_to_ints.c		stack_utils.c	\
		 instructions.c		sorting_utils.c		sort_three.c		values_utils.c	\
		 rotation_utils.c	sort.c				error_checks.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o push_swap $(OFILES) $(LIBFTDIR)/$(LIBFT)

clean:
	rm -f $(OFILES)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
