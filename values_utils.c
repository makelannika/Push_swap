/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:35:45 by amakela           #+#    #+#             */
/*   Updated: 2024/01/26 16:46:56 by amakela          ###   ########.fr       */
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

void	set_target_a(t_stack_node *src, t_stack_node *dst)
{
	while (src != NULL)
	{
		src->target = target_idx_a(dst, src->value);
		src = src->next;
	}
}

void	set_target_b(t_stack_node *src, t_stack_node *dst)
{
	while (src != NULL)
	{
		src->target = target_idx_b(dst, src->value);
		src = src->next;
	}
}

void	set_total_ops(t_stack_node *src, t_stack_node *dst)
{
	t_stack_node	*target;

	target = NULL;
	while (src != NULL)
	{
		target = get_target_node(dst, src->target);
		if (src->above_median != target->above_median)
			src->total_ops = src->rot_count + target->rot_count;
		else
		{
			if (src->rot_count > target->rot_count)
				src->total_ops = src->rot_count;
			else
				src->total_ops = target->rot_count;
		}
		src = src->next;
	}
}
