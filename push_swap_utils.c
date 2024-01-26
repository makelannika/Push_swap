/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:52:34 by amakela           #+#    #+#             */
/*   Updated: 2024/01/26 16:38:36 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

int	is_sorted(t_stack_node *a)
{
	while (a->next != NULL)
	{
		if (a->value < a->next->value)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int	find_smallest(t_stack_node *node)
{
	int	index;
	int	smallest;

	index = 0;
	smallest = node->value;
	while (node != NULL)
	{
		if (node->value < smallest)
		{
			index = node->index;
			smallest = node->value;
		}
		node = node->next;
	}
	return (index);
}

int	find_greatest(t_stack_node *node)
{
	int	index;
	int	greatest;

	index = 0;
	greatest = node->value;
	while (node != NULL)
	{
		if (node->value > greatest)
		{
			index = node->index;
			greatest = node->value;
		}
		node = node->next;
	}
	return (index);
}

int	target_idx_a(t_stack_node *dest, int value)
{
	t_stack_node	*curr;
	unsigned int	difference;
	int				index;

	index = 0;
	difference = UINT_MAX;
	curr = dest;
	while (curr != NULL)
	{
		if ((curr->value > value)
			&& ((unsigned int)(curr->value - value) < difference))
		{
			difference = curr->value - value;
			index = curr->index;
		}
		curr = curr->next;
	}
	if (difference == UINT_MAX)
		index = find_smallest(dest);
	return (index);
}

int	target_idx_b(t_stack_node *dest, int value)
{
	t_stack_node	*curr;
	unsigned int	difference;
	int				index;

	index = 0;
	difference = UINT_MAX;
	curr = dest;
	while (curr != NULL)
	{
		if ((curr->value < value)
			&& ((unsigned int)(value - curr->value) < difference))
		{
			difference = curr->value - value;
			index = curr->index;
		}
		curr = curr->next;
	}
	if (difference == UINT_MAX)
		index = find_greatest(dest);
	return (index);
}

t_stack_node	*get_target_node(t_stack_node *target, int index)
{
	while (index > 0)
	{
		target = target->next;
		index--;
	}
	return (target);
}

t_stack_node	*get_node_to_push(t_stack_node *node)
{
	int				index;
	int				ops;
	t_stack_node	*curr;

	index = 0;
	curr = node;
	ops = node->total_ops;
	while (curr != NULL)
	{
		if (curr->total_ops < ops)
		{
			index = curr->index;
			ops = curr->total_ops;
		}
		curr = curr->next;
	}
	return (get_target_node(node, index));
}
