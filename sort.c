/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:07:51 by amakela           #+#    #+#             */
/*   Updated: 2024/01/30 12:41:08 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;

	smallest = NULL;
	push(a, b);
	push(a, b);
	ft_printf("pb\npb\n");
	while (stack_length(*a) > 3)
		count_and_push(a, b, 'a', 'b');
	sort_three(a, 'a');
	while (*b)
		count_and_push(b, a, 'b', 'a');
	if (!is_sorted(*a))
	{
		set_values(*a);
		smallest = get_target_node(*a, find_smallest(*a));
		rot_one(a, smallest->above_median, smallest->rot_count, 'a');
	}
}

void	count_and_push(t_stack_node **src, t_stack_node **dst, char s, char d)
{
	set_values(*src);
	set_values(*dst);
	if (s == 'a')
		set_target_b(*src, *dst);
	else
		set_target_a(*src, *dst);
	rotation(src, dst, s, d);
	push(src, dst);
	ft_printf("p%c\n", d);
}
