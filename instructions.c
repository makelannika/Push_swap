/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:35:43 by amakela           #+#    #+#             */
/*   Updated: 2024/01/19 12:20:29 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(stack_node *node)
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

void	rotate(stack_node **node)
{
	if (*node == NULL)
		return ;
	stack_node *current;
	stack_node *second;

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

void	reverse_rotate(stack_node **node)
{
	if (*node == NULL)
		return ;
	stack_node *current;

	current = *node;
	while (current->next != NULL)
		current = current->next;
	current->next = *node;
	current->prev->next = NULL;
	current->prev = NULL;
	*node = current;
}

void	push(stack_node **src, stack_node **dest)
{
	stack_node *first;
	stack_node *second;
	
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

