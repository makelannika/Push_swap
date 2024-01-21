/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:26:42 by amakela           #+#    #+#             */
/*   Updated: 2024/01/21 16:54:06 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack_node **a, int *values, int count)
{
	t_stack_node	*node;

	node = NULL;
	while (count > 0)
	{
		node = create_node(values[count - 1]);
		if (!node)
		{
			free_stack(*a);
			return ;
		}
		add_front(a, node);
		count--;
	}
}

t_stack_node	*create_node(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->value = value;
	return (new_node);
}

void	add_front(t_stack_node **a, t_stack_node *node)
{
	if (*a != NULL)
	{
		node->next = *a;
		node->next->prev = node;
	}
	*a = node;
}

int	stack_length(t_stack_node *a)
{
	int	length;

	length = 0;
	while (a)
	{
		length++;
		a = a->next;
	}
	return (length);
}

void	free_stack(t_stack_node *a)
{
	if (a == NULL)
		return ;
	while (a->next != NULL)
	{
		a = a->next;
		free(a->prev);
	}
	free(a);
}
