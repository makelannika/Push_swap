/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:38:24 by amakela           #+#    #+#             */
/*   Updated: 2024/01/20 19:55:36 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void rotation(int index, t_stack_node **a);

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
			rotation(target_index, a);
		}
		push(b, a);
		ft_printf("pa\n");
	}
	if (!is_sorted(*a))
	{
		set_indices(*a);
		smallest = find_smallest(*a);
		rotation(smallest, a);
	}
}

static void	rotation(int index, t_stack_node **a)
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
}
