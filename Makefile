# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 20:06:32 by amakela           #+#    #+#              #
#    Updated: 2024/01/18 22:53:28 by amakela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CFILES = main.c				input_utils.c		split_to_ints.c		stack_utils.c \
		 instructions.c		push_swap.c			push_swap_utils.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

run: $(OFILES)
	gcc -g $(CFLAGS) $(OFILES) libft/libft.a
	./a.out 1 2 3 4 5

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
clean:
	rm -f $(OFILES)
	rm -f a.out

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
