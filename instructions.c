/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:35:43 by amakela           #+#    #+#             */
/*   Updated: 2024/01/19 20:46:23 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node *node)
{
	int	temp;

	temp = 0;
	if (stack_length(node) > 1)
	{
		temp = node->value;
		node->value = node->next->value;
		node->next->value = temp;
	}
}

void	rotate(t_stack_node **node)
{
	t_stack_node	*current;
	t_stack_node	*second;

	if (*node == NULL)
		return ;
	current = *node;
	second = current->next;
	while (current->next != NULL)
		current = current->next;
	current->next = *node;
	(*node)->prev = current;
	(*node)->next = NULL;
	second->prev = NULL;
	*node = second;
}

void	reverse_rotate(t_stack_node **node)
{
	t_stack_node	*current;

	if (*node == NULL)
		return ;
	current = *node;
	while (current->next != NULL)
		current = current->next;
	current->next = *node;
	current->prev->next = NULL;
	current->prev = NULL;
	*node = current;
}

void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (*src == NULL)
		return ;
	first = *src;
	second = NULL;
	if (stack_length(*src) > 1)
	{
		second = first->next;
		second->prev = NULL;
		*src = second;
	}
	else
		*src = NULL;
	first->next = *dest;
	if (*dest != NULL)
		(*dest)->prev = first;
	*dest = first;
}
