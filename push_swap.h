#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct stack_node
{
	int			value;
	struct	stack_node	*next;
	struct  stack_node	*prev;
} stack_node;

int		digit_check(char *str);
int		*split_to_ints(char *str, char delimiter);
int		count_numbers(char const *str, char delimiter);
long		ft_atol(char *str);
int		find_duplicates(int *array, int num_count);
void		create_stack(stack_node **a, int *values, int size);
stack_node      *create_node(int value);
void		add_front(stack_node **a, stack_node *node);

#endif
