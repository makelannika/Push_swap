/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:52:34 by amakela           #+#    #+#             */
/*   Updated: 2024/01/24 18:28:31 by amakela          ###   ########.fr       */
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

int	get_target_idx(t_stack_node *dest, int value)
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
	int index = 0;
	int ops = node->total_ops;
	t_stack_node *curr;

	curr = node;
	while(curr != NULL)
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

void	rotation(t_stack_node **src, t_stack_node **dst, char s, char d)
{
	t_stack_node *to_push;
	t_stack_node *target;
	int	times;

	to_push = get_node_to_push(*src);
	if (to_push == NULL)
		ft_printf("here");
	target = get_target_node(*dst, to_push->target);
	if (to_push->rot_count < target->rot_count)
		times = to_push->rot_count;
	else
		times = target->rot_count;
	if (to_push->above_median == target->above_median)
	{
		rotate_two(src, dst,to_push->above_median, times);
		if (to_push->rot_count > target->rot_count)
			rotate_one(src, to_push->above_median, to_push->rot_count - times, s);
		else
			rotate_one(dst, target->above_median, target->rot_count - times, d);
	}
	else
	{
		rotate_one(src, to_push->above_median, to_push->rot_count, s);
		rotate_one(dst, target->above_median, target->rot_count, d);
	}
}

void	rotate_two(t_stack_node **src, t_stack_node **dst, int above, int times)
{
	while (times--)
	{
		if (above)
		{
			rotate(src);
			rotate(dst);
			ft_printf("rr\n");
		}
		else
		{
			reverse_rotate(src);
			reverse_rotate(dst);
			ft_printf("rrr\n");
		}
	}
}

void	rotate_one(t_stack_node **node, int above, int times, char stack)
{
	while (times--)
	{
		if (above)
		{
			rotate(node);
			ft_printf("r%c\n", stack);
		}
		else
		{
			reverse_rotate(node);
			ft_printf("rr%c\n", stack);
		}
	}
}
