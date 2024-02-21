/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:33:09 by amakela           #+#    #+#             */
/*   Updated: 2024/02/09 15:33:12 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	is_sorted(t_node *a)
{
	if (a == NULL)
		return (1);
	while (a->next != NULL)
	{
		if (a->value < a->next->value)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int	find_smallest(t_node *node)
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

int	find_greatest(t_node *node)
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

int	target_idx_a(t_node *dest, int value)
{
	int				index;
	t_node			*curr;
	unsigned int	difference;

	index = 0;
	curr = dest;
	difference = UINT_MAX;
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

int	target_idx_b(t_node *dest, int value)
{
	int				index;
	t_node			*curr;
	unsigned int	difference;

	index = 0;
	curr = dest;
	difference = UINT_MAX;
	while (curr != NULL)
	{
		if ((curr->value < value)
			&& ((unsigned int)(value - curr->value) < difference))
		{
			difference = value - curr->value;
			index = curr->index;
		}
		curr = curr->next;
	}
	if (difference == UINT_MAX)
		index = find_greatest(dest);
	return (index);
}
