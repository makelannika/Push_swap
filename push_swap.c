/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:13:34 by amakela           #+#    #+#             */
/*   Updated: 2024/01/19 18:18:26 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	push_swap(t_stack_node **a)
{
	t_stack_node	*b;

	b = NULL;
	if (is_sorted(*a))
		ft_printf("sorted");
	set_index(*a);
	sort_three(a, 'a');
	ft_printf("\n");
/*	while (a != NULL)
	{
		ft_printf("%d\n", a->value);
		a = a->next;
	}*/
}
