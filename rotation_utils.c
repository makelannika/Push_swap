/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:33:16 by amakela           #+#    #+#             */
/*   Updated: 2024/01/31 17:13:01 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rotation(t_node **src, t_node **dst, char s, char d)
{
	t_node	*to_push;
	t_node	*target;
	int		times;

	to_push = get_node_to_push(*src);
	target = get_target_node(*dst, to_push->target);
	if (to_push->rot_count < target->rot_count)
		times = to_push->rot_count;
	else
		times = target->rot_count;
	if (to_push->above_median == target->above_median)
	{
		rot_two(src, dst, to_push->above_median, times);
		if (to_push->rot_count > target->rot_count)
			rot_one(src, to_push->above_median, to_push->rot_count - times, s);
		else
			rot_one(dst, target->above_median, target->rot_count - times, d);
	}
	else
	{
		rot_one(src, to_push->above_median, to_push->rot_count, s);
		rot_one(dst, target->above_median, target->rot_count, d);
	}
}

t_node	*get_node_to_push(t_node *node)
{
	int		ops;
	int		index;
	t_node	*curr;

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

t_node	*get_target_node(t_node *target, int index)
{
	while (index > 0)
	{
		target = target->next;
		index--;
	}
	return (target);
}

void	rot_one(t_node **node, int above, int times, char stack)
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

void	rot_two(t_node **src, t_node **dst, int above, int times)
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
