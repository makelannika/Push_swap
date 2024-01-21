/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:52:34 by amakela           #+#    #+#             */
/*   Updated: 2024/01/21 17:57:14 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	find_target(t_stack_node *dest, int value)
{
	t_stack_node *curr;
	int	difference;
	int	index;

	index = 0;
	difference = INT_MAX;
	curr = dest;
	while (curr != NULL)
	{
		if ((curr->value > value) && (curr->value - value < difference))
		{
			difference = curr->value - value;
			index = curr->index;
		}
		curr = curr->next;
	}
	if (difference == INT_MAX)
		index = find_smallest(dest);
	return (index);
}
