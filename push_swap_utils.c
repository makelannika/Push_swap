/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:52:34 by amakela           #+#    #+#             */
/*   Updated: 2024/01/19 18:44:15 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	set_index(t_stack_node *node)
{
	int	index;

	index = 0;
	while (node != NULL)
	{
		node->index = index;
		node = node->next;
		index++;
	}
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

int	compare_two(t_stack_node *node)
{
	if (node->value > node->next->value)
		return (0);
	return (1);
}
