/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:26:42 by amakela           #+#    #+#             */
/*   Updated: 2024/01/17 15:30:59 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(stack_node **a, int *values, int count)
{
	stack_node	*node;
	
	node = NULL;
	while (count > 0)
	{
	node = create_node(values[count - 1]);
	if (!node)
	{
		free_stack(*a);
		return;
	}
	add_front(a, node);
	count--;
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

int	stack_length(stack_node *a)
{
	int length;

	length = 0;
	while (a)
	{
		length++;
		a = a->next;
	}
	return (length);
}

void	free_stack(stack_node *a)
{
	while (a->next != NULL)
	{
		a = a->next;
		free(a->prev);
	}
	free(a);
}

