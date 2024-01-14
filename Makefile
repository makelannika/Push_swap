NAME = push_swap.a

CFILES = main.c		split_to_ints.c		push_swap_utils.c

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
