/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:29:41 by amakela           #+#    #+#             */
/*   Updated: 2024/02/09 15:29:45 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smallest_first(t_node **node);
static void	smallest_second(t_node **node, int greatest);
static void	smallest_last(t_node **node, int greatest);

void	sort_three(t_node **node)
{
	int	smallest;
	int	greatest;

	if (is_sorted(*node))
		return ;
	if (stack_length(*node) == 2)
	{
		swap(*node);
		ft_printf("sa\n");
		return ;
	}
	set_indices(*node);
	smallest = find_smallest(*node);
	greatest = find_greatest(*node);
	if (smallest == 0)
		smallest_first(node);
	else if (smallest == 1)
		smallest_second(node, greatest);
	else
		smallest_last(node, greatest);
}

static void	smallest_first(t_node **node)
{
	swap(*node);
	rotate(node);
	ft_printf("sa\nra\n");
}

static void	smallest_second(t_node **node, int greatest)
{
	if (greatest == 0)
	{
		rotate(node);
		ft_printf("ra\n");
	}
	else if (greatest == 2)
	{
		swap(*node);
		ft_printf("sa\n");
	}
}

static void	smallest_last(t_node **node, int greatest)
{
	if (greatest == 0)
	{
		swap(*node);
		reverse_rotate(node);
		ft_printf("sa\nrra\n");
	}
	else if (greatest == 1)
	{
		reverse_rotate(node);
		ft_printf("rra\n");
	}
}
