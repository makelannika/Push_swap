/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:38:24 by amakela           #+#    #+#             */
/*   Updated: 2024/01/20 19:31:27 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int	target_index;
	int	smallest;

	if (stack_length(*a) == 5)
	{
		push(a, b);
		ft_printf("pb\n");
	}
	push(a, b);
	ft_printf("pb\n");
	set_indices(*a);
	sort_three(a, 'a');
	while (stack_length(*b))
	{
		set_indices(*a);
		target_index = find_target(*a, (*b)->value);
		if (target_index != 0)
		{
			if ((stack_length(*a) % 2 != 0 && target_index <= stack_length(*a) / 2)
					|| (stack_length(*a) % 2 == 0 && target_index < stack_length(*a) / 2))
				{
					while (target_index > 0)
					{
						rotate(a);
						ft_printf("ra\n");
						target_index--;
					}
				}
			else
			{
				while (target_index < stack_length(*a))
				{
					reverse_rotate(a);
					ft_printf("rra\n");
					target_index++;
				}
			}
		}
		push(b, a);
		ft_printf("pa\n");
	}
	if (!is_sorted(*a))
	{
		set_indices(*a);
		smallest = find_smallest(*a);
		if ((stack_length(*a) % 2 != 0 && smallest <= stack_length(*a) / 2)
				|| (stack_length(*a) % 2 == 0 && smallest < stack_length(*a) / 2))
		{
			while (smallest > 0)
			{
				rotate(a);
				ft_printf("ra\n");
				smallest--;
			}
		}
		else
		{
			while (smallest < stack_length(*a))
			{
				reverse_rotate(a);
				ft_printf("rra\n");
				smallest++;
			}
		}
	}
}
