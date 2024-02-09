/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:28:58 by amakela           #+#    #+#             */
/*   Updated: 2024/02/09 15:29:01 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_and_push(t_node **src, t_node **dst, char s, char d);
static void	final_rotation(t_node **a);

void	sort(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
		return ;
	if (stack_length(*a) == 4)
	{
		push(a, &b);
		ft_printf("pb\n");
	}
	else if (stack_length(*a) > 4)
	{
		push(a, &b);
		push(a, &b);
		ft_printf("pb\npb\n");
		while (stack_length(*a) > 3)
			count_and_push(a, &b, 'a', 'b');
	}
	sort_three(a);
	while (b)
		count_and_push(&b, a, 'b', 'a');
	final_rotation(a);
}

static void	count_and_push(t_node **src, t_node **dst, char s, char d)
{
	set_values(*src);
	set_values(*dst);
	set_targets(*src, *dst, d);
	set_total_ops(*src, *dst);
	rotation(src, dst, s, d);
	push(src, dst);
	ft_printf("p%c\n", d);
}

static void	final_rotation(t_node **a)
{
	t_node	*smallest;

	smallest = NULL;
	if (!is_sorted(*a))
	{
		set_values(*a);
		smallest = get_target_node(*a, find_smallest(*a));
		rot_one(a, smallest->above_median, smallest->rot_count, 'a');
	}
}
