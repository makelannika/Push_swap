/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:38:24 by amakela           #+#    #+#             */
/*   Updated: 2024/01/23 17:42:22 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	rotation(int index, t_stack_node **a);

void	sort_five(t_stack_node **a, t_stack_node **b)
{
//	int	target_index;
	int	smallest;
	int rotate;
	t_stack_node *to_push;
	t_stack_node *target;

	while (stack_length(*a) > 3)
	{
		push(a, b);
		ft_printf("pb\n");
	}
	set_indices(*a);
	sort_three(a, 'a');
	to_push = *b;
	target = *a;
	rotate = 0;
	while (stack_length(*b))
	{
		set_values(*a);
		set_values(*b);
		set_target(*b, *a);
		set_total_ops(*b, *a);
		if (to_push->total_ops > to_push->next->total_ops)
			to_push = to_push->next;
		target = get_target_node(*a, to_push->target);
		if (to_push->total_ops > 0 || target->total_ops > 0)
		{
			if (to_push->above_median == target->above_median)
			{
				if (to_push->rot_count < target->rot_count)
					rotate = to_push->rot_count;
				else
					rotate = target->rot_count;
				while (rotate > 0)
				{
					if (to_push->above_median)
					{
						rotate(a);
						rotate(b);
						ft_printf("rr\n");
					}
					else
					{
						reverse_rotate(a);
						reverse_rotate(b);
						ft_printf("rrr\n");
					}
					rotate--;
				}
			}
			else
			{
				while (to_push->rot_count > 0)
				{
					if (to_push->above_median)
					{
						rotate(b);
						ft_printf("rb\n");
					}
					else
					{
						reverse_rotate(b);
						ft_printf("rrb\n");
					}
					to_push->rot_count--;
				}
				while (target->rot_count > 0)
				{
					if (target->above_median)
					{
						rotate(a);
						ft_printf("ra\n");
					}
					else
					{
						reverse_rotate(a);
						ft_printf("rra\n");
					}
					target->rot_count--;
				}

			}
		}
/*		while(*b != NULL)
		{
			ft_printf("%d\n", (*b)->total_ops);
			*b = (*b)->next;
		}*/
/*		set_indices(*a);
		target_index = get_target_idx(*a, (*b)->value);
		if (target_index != 0)
		{
			rotation(target_index, a);
		}
		push(b, a);
		ft_printf("pa\n");*/
	}
	if (!is_sorted(*a))
	{
		set_indices(*a);
		smallest = find_smallest(*a);
		rotation(smallest, a);
	}
}

/*static void	rotation(int index, t_stack_node **a)
{
	if ((stack_length(*a) % 2 != 0 && index <= stack_length(*a) / 2)
		|| (stack_length(*a) % 2 == 0 && index < stack_length(*a) / 2))
	{
		while (index > 0)
		{
			rotate(a);
			ft_printf("ra\n");
			index--;
		}
	}
	else
	{
		while (index < stack_length(*a))
		{
			reverse_rotate(a);
			ft_printf("rra\n");
			index++;
		}
	}
}*/
