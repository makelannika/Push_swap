# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 20:06:32 by amakela           #+#    #+#              #
#    Updated: 2024/01/19 18:21:01 by amakela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CFILES = main.c		input_utils.c		split_to_ints.c		stack_utils.c \
		 instructions.c		push_swap.c			push_swap_utils.c	sort_three.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

run: $(NAME)
	gcc -g $(NAME) libft/libft.a
	./a.out 3 2 1

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
