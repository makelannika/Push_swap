/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:19:21 by amakela           #+#    #+#             */
/*   Updated: 2024/01/17 15:24:37 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct stack_node
{
	int					value;
	struct	stack_node	*next;
	struct  stack_node	*prev;
} stack_node;

int			digit_check(char *str);
int			*split_to_ints(char *str, char delimiter);
int			num_count(char const *str, char delimiter);
long		ft_atol(char *str);
int			find_duplicates(int *array, int count);
void		create_stack(stack_node **a, int *values, int size);
stack_node	*create_node(int value);
void		add_front(stack_node **a, stack_node *node);
int			stack_length(stack_node *a);
void		free_stack(stack_node *a);

#endif
