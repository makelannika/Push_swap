# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 20:06:32 by amakela           #+#    #+#              #
#    Updated: 2024/02/27 19:05:49 by amakela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

BONUS		= checker

LIBFT		= libft.a
LIBFTDIR	= libft

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

MAINC		= push_swap.c
MAINO		= $(MAINC:.c=.o)

CFILES		= input_utils.c			split_to_ints.c		stack_utils.c	\
			  instructions.c		sorting_utils.c		sort_three.c	\
			  values_utils.c		rotation_utils.c	sort.c			\
			  error_checks.c		

BCFILES		= checker_bonus.c	checker_utils_bonus.c

BOFILES		= $(BCFILES:.c=.o)

OFILES		= $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) $(MAINO)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o push_swap $(OFILES) $(MAINO) $(LIBFTDIR)/$(LIBFT)

bonus: $(BONUS)

$(BONUS): $(BOFILES) $(OFILES)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o checker $(BOFILES) $(OFILES) $(LIBFTDIR)/$(LIBFT)

clean:
	rm -f $(OFILES) $(MAINO)
	make -C $(LIBFTDIR) clean
	rm -f $(BOFILES)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean
	rm -f checker

re: fclean $(NAME)

.PHONY: all clean fclean re
