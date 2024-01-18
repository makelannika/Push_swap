/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:24:18 by amakela           #+#    #+#             */
/*   Updated: 2024/01/18 22:57:47 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

static int  free_memory(char *str, stack_node *a, int flag);

int	main(int argc, char **argv)
{
	stack_node	*a;
	char		*input;
	int         *values;
	int			flag = 0;

	a = NULL;
	if (argc == 1)
		return (0);
	if (argc > 2)
	{
		input = args_to_str(argc, argv);
		flag = 1;
	}
	else
		input = argv[1];
	values = split_to_ints(input, 32);
	if (!values)
		return (free_memory(input, a, flag));
	create_stack(&a, values, num_count(input, 32));
	push_swap(a);
	free_memory(input, a, flag);
	return (0);
}

static int	free_memory(char *str, stack_node *a, int flag)
{
	if (flag == 1)
		free(str);
	free_stack(a);
	return (0);
}

// MAIN 
// takes input as one string or multiple arguments
// checks input is valid = only integers, no overflow, no duplicates
// formats the input ready for push swap to handle
//
// PUSH_SWAP
// takes as an input stack a
// sorts stack a 
// with sa, sb, ss,  ra, rb rr,  rra rrb rrr, pa, pb
// prints out commands executed with \n
