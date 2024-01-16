#include "push_swap.h"

void	create_stack(stack_node **a, int *values, int size)
{
	stack_node	*node;
	
	node = NULL;
	while (size > 0)
	{
	node = create_node(values[size - 1]);
//	if (!node)
//		return (NULL); // free stack
	add_front(a, node);
	size--;
	}
	
}

stack_node	*create_node(int value)
{
	stack_node	*new_node;

	new_node = malloc(sizeof(stack_node));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->value = value;
	return (new_node);
}

void	add_front(stack_node **a, stack_node *node)
{
	if (*a != NULL)
	{
		node->next = *a;
		node->next->prev = node;
	}
	*a = node;
}

