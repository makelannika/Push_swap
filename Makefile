# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 20:06:32 by amakela           #+#    #+#              #
#    Updated: 2024/01/21 17:56:11 by amakela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CFILES = main.c				input_utils.c		split_to_ints.c		stack_utils.c	\
		 instructions.c		push_swap.c			push_swap_utils.c	sort_three.c	\
		 sort_five.c		values_utils.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

run: $(NAME)
	gcc -g $(NAME) libft/libft.a
	./a.out 214 11 2 4235 4 3 10 7 13553 53 2164 643 1243

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)
	rm -f a.out

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
