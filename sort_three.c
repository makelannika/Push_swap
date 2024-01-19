/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:00:43 by amakela           #+#    #+#             */
/*   Updated: 2024/01/19 20:41:16 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void smallest_first(t_stack_node **node, char stack);
static void smallest_second(t_stack_node **node, int greatest, char stack);
static void smallest_last(t_stack_node **node, int  greatest, char stack);

void	sort_three(t_stack_node **node, char stack)
{
	int smallest;
	int	greatest;

	if (stack_length(*node) == 2)
	{
		swap(*node);
		ft_printf("s%c\n", stack);
		return ;
	}
	smallest = find_smallest(*node);
	greatest = find_greatest(*node);
	if (smallest == 0)
		smallest_first(node, stack);
	else if (smallest == 1)
		smallest_second(node, greatest, stack);
	else
		smallest_last(node, greatest, stack);
}

static void	smallest_first(t_stack_node **node, char stack)
{
		swap(*node);
		rotate(node);
		ft_printf("s%c\nr%c\n", stack, stack);
}

static void	smallest_second(t_stack_node **node, int greatest, char stack)
{
	if (greatest == 0)
	{
		rotate(node);
		ft_printf("r%c\n", stack);
	}
	else if (greatest == 2)
	{
		swap(*node);
		ft_printf("s%c\n", stack);
	}
}

static void	smallest_last(t_stack_node **node, int	greatest, char stack)
{
	if (greatest == 0)
	{
		swap(*node);
		reverse_rotate(node);
		ft_printf("s%c\nrr%c\n", stack, stack);
	}
	else if (greatest == 1)
	{
		reverse_rotate(node);
		ft_printf("rr%c\n", stack);
	}
}
