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

CC = cc -g3

CFILES = input_utils.c		split_to_ints.c		stack_utils.c	\
		 instructions.c		sorting_utils.c		sort_three.c	\
		 values_utils.c		rotation_utils.c	sort.c			\
		 error_checks.c		

BFILES = checker_bonus.c	checker_utils_bonus.c

BOFILES = $(BFILES:.c=.o)

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o push_swap $(OFILES) $(LIBFTDIR)/$(LIBFT) push_swap.c

bonus: .bonus

.bonus: $(BOFILES) $(OFILES)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o checker $(BOFILES) $(OFILES) $(LIBFTDIR)/$(LIBFT)
	@touch .bonus

clean:
	rm -f $(OFILES)
	make -C $(LIBFTDIR) clean
	rm -f $(BOFILES)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean
	rm -f .bonus
	rm -f checker

re: fclean $(NAME)

.PHONY: all clean fclean re
