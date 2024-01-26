/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:38:24 by amakela           #+#    #+#             */
/*   Updated: 2024/01/26 16:35:38 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*target;
	t_stack_node	*smallest;

	smallest = NULL;
	while (stack_length(*a) > 3)
	{
		push(a, b);
		ft_printf("pb\n");
	}
	sort_three(a, 'a');
	if (stack_length(*b) > 1)
		count_and_push(b, a, 'b', 'a');
	set_values(*a);
	set_target_a(*b, *a);
	target = get_target_node(*a, (*b)->target);
	rot_one(a, target->above_median, target->rot_count, 'a');
	push(b, a);
	ft_printf("pa\n");
	if (!is_sorted(*a))
	{
		set_values(*a);
		smallest = get_target_node(*a, find_smallest(*a));
		rot_one(a, smallest->above_median, smallest->rot_count, 'a');
	}
}
