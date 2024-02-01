/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:07:51 by amakela           #+#    #+#             */
/*   Updated: 2024/02/01 17:34:13 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort(t_node **a, t_node **b)
{
	t_node	*smallest;

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
