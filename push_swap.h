/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:19:21 by amakela           #+#    #+#             */
/*   Updated: 2024/01/26 16:46:49 by amakela          ###   ########.fr       */
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
	int					rot_count;
	int					above_median;
	int					target;
	int					total_ops;
	struct stack_node	*next;
	struct stack_node	*prev;
}	t_stack_node;

char			*args_to_str(int argc, char **argv);
int				digit_check(char *str);
int				*split_to_ints(char *str, char delimiter);
int				num_count(char const *str, char delimiter);
long			ft_atol(char *str);
int				find_duplicates(int *array, int count);
int				overflow_check(long nbr, int *array);
int				*free_array(int *array);
int				*error_message(void);
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
void			sort_three(t_stack_node **node, char stack);
void			sort_five(t_stack_node **a, t_stack_node **b);
void			sort(t_stack_node **a, t_stack_node **b);
int				find_smallest(t_stack_node *node);
int				find_greatest(t_stack_node *node);
int				target_idx_a(t_stack_node *node, int value);
int				target_idx_b(t_stack_node *dest, int value);
void			set_values(t_stack_node *node);
void			set_indices(t_stack_node *node);
void			set_position(t_stack_node *node);
void			set_target_a(t_stack_node *src, t_stack_node *dst);
void			set_target_b(t_stack_node *src, t_stack_node *dst);
void			set_total_ops(t_stack_node *src, t_stack_node *target);
t_stack_node	*get_target_node(t_stack_node *target, int index);
t_stack_node	*get_node_to_push(t_stack_node *node);
void			rotation(t_stack_node **src, t_stack_node **dst, char s, char d);
void			rot_one(t_stack_node **node, int above, int times, char stack);
void			rot_two(t_stack_node **src, t_stack_node **dst, int above, int times);
void			count_and_push(t_stack_node **src, t_stack_node **dst, char s, char d);

#endif
