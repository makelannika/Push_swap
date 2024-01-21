/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:13:34 by amakela           #+#    #+#             */
/*   Updated: 2024/01/21 11:35:52 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	push_swap(t_stack_node **a)
{
	t_stack_node	*b;

	b = NULL;
	if (is_sorted(*a))
		return ;
	set_indices(*a);
	if (stack_length(*a) <= 3)
		sort_three(a, 'a');
	if (stack_length(*a) <= 5)
		sort_five(a, &b);
	ft_printf("\n");
}
