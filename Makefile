NAME = push_swap.a

CFILES = main.c		input_utils.c		split_to_ints.c		stack_utils.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

run: $(OFILES)
	gcc -g $(CFLAGS) $(OFILES) libft/libft.a
	./a.out "1 2 3 4"

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
