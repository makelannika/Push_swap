/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:44:50 by amakela           #+#    #+#             */
/*   Updated: 2024/02/22 15:44:54 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swaps(char *instruction, t_node **a, t_node *b)
{
	if (ft_strncmp(instruction, "sa", 2) == 0)
		swap(*a);
	else if (ft_strncmp(instruction, "sb", 2) == 0)
		swap(b);
	else if (ft_strncmp(instruction, "ss", 2) == 0)
	{
		swap(*a);
		swap(b);
	}
}

void	pushes(char *instruction, t_node **a, t_node **b)
{
	if (ft_strncmp(instruction, "pa", 2) == 0)
		push(b, a);
	else if (ft_strncmp(instruction, "pb", 2) == 0)
		push(a, b);
}

void	rotations(char *instruction, t_node **a, t_node **b)
{
	if (ft_strncmp(instruction, "ra", 2) == 0)
		rotate(a);
	else if (ft_strncmp(instruction, "rb", 2) == 0)
		rotate(b);
	else if (ft_strncmp(instruction, "rr", 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(instruction, "rra", 3) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(instruction, "rrb", 3) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(instruction, "rrr", 3) == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}
