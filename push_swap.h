/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:19:21 by amakela           #+#    #+#             */
/*   Updated: 2024/01/19 20:46:29 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct stack_node
{
	int					value;
	int					index;
	struct stack_node	*next;
	struct stack_node	*prev;
}	t_stack_node;

char			*args_to_str(int argc, char **argv);
int				digit_check(char *str);
int				*split_to_ints(char *str, char delimiter);
int				num_count(char const *str, char delimiter);
long			ft_atol(char *str);
int				find_duplicates(int *array, int count);
void			create_stack(t_stack_node **a, int *values, int size);
t_stack_node	*create_node(int value);
void			add_front(t_stack_node **a, t_stack_node *node);
int				stack_length(t_stack_node *a);
void			free_stack(t_stack_node *a);
void			swap(t_stack_node *node);
void			rotate(t_stack_node **node);
void			reverse_rotate(t_stack_node **node);
void			push(t_stack_node **src, t_stack_node **dest);
void			push_swap(t_stack_node **a);
int				is_sorted(t_stack_node *a);
int				overflow_check(long nbr, int *array);
int				*free_array(int *array);
int				*error_message(void);
void			set_index(t_stack_node *node);
void			sort_three(t_stack_node **node, char stack);
int				find_smallest(t_stack_node *node);
int				find_greatest(t_stack_node *node);
int				find_target(t_stack_node *node, int value);

#endif
