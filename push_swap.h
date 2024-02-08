/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:19:21 by amakela           #+#    #+#             */
/*   Updated: 2024/01/31 17:13:04 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct node
{
	int			value;
	int			index;
	int			rot_count;
	int			above_median;
	int			target;
	int			total_ops;
	struct node	*next;
	struct node	*prev;
}	t_node;

char		*args_to_str(int argc, char **argv);
char		*space_join(char const *s1, char const *s2);
int			digit_check(char *str);
int			*split_to_ints(char *str, char delimiter);
int			num_count(char *str, char delimiter);
long		ft_atol(char *str);
int			duplicate_check(int *array, int count);
int			overflow_check(long nbr);
int			*free_array(int *array);
int			error_message(void);
void		create_stack(t_node **a, int *values, int size);
t_node		*create_node(int value);
void		add_front(t_node **a, t_node *node);
int			stack_length(t_node *a);
void		free_stack(t_node **a);
void		swap(t_node *node);
void		rotate(t_node **node);
void		reverse_rotate(t_node **node);
void		push(t_node **src, t_node **dest);
// void		push_swap(t_node **a);
int			is_sorted(t_node *a);
void		sort_three(t_node **node);
// void		sort_five(t_node **a, t_node **b);
void		sort(t_node **a);
int			find_smallest(t_node *node);
int			find_greatest(t_node *node);
int			target_idx_a(t_node *node, int value);
int			target_idx_b(t_node *dest, int value);
void		set_values(t_node *node);
void		set_indices(t_node *node);
void		set_position(t_node *node);
void		set_targets(t_node *src, t_node *dst, char d);
void		set_total_ops(t_node *src, t_node *target);
t_node		*get_target_node(t_node *dst, int index);
t_node		*get_node_to_push(t_node *node);
void		rotation(t_node **src, t_node **dst, char s, char d);
void		rot_one(t_node **node, int above, int times, char stack);
void		rot_two(t_node **src, t_node **dst, int above, int times);

#endif
