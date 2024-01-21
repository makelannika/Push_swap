/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:35:45 by amakela           #+#    #+#             */
/*   Updated: 2024/01/21 17:57:33 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	set_values(t_stack_node *node)
{
	set_indices(node);
	set_position(node);
}

void	set_indices(t_stack_node *node)
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

void	set_position(t_stack_node *node)
{
	int	length;

	length = stack_length(node);
	while (node != NULL)
	{
		if ((length % 2 != 0 && node->index <= length / 2)
	   		|| (length % 2 == 0 && node->index < length / 2))
		{
			node->above_median = 1;
			node->rot_count = node->index;
		}
		else
		{
			node->above_median = 0;
			node->rot_count = length - node->index;
		}
		node = node->next;
	}
}

void	set_target(t_stack_node *src, t_stack_node *dst)
{
	while (src != NULL)
	{
		src->target = find_target(dst, src->value);
		src = src->next;
	}
}

void	set_total_ops(t_stack_node *node, t_stack_node *target)
{
	while (node != NULL)
	{
		if (node->above_median != target->above_median)
			node->total_ops = node->rot_count + target->rot_count;
		else
		{
			if (node->rot_count > target->rot_count)
				node->total_ops = node->rot_count;
			else
				node->total_ops = target->rot_count;
		}
		node = node->next;
	}
}

