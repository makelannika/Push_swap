/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:24:18 by amakela           #+#    #+#             */
/*   Updated: 2024/01/09 20:46:16 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

static char    *args_to_str(int argc, char **argv);
static int     error_message(char *str);

int	main(int argc, char **argv)
{
	stack_node	**a;
	int		*array;
	char		*str;

	a = NULL;	
	if (argc == 1)
		return (0);
	if (argc > 2)
		str = args_to_str(argc, argv);
	else
		str = argv[1];
	if (!digit_check(str))
		return (error_message(str));
	array = split_to_ints(str, 32);
	if (!array)
		return (error_message(str));
	create_stack(a, array, count_numbers(str, 32));
	// push_swap(array);
	free(str);
	return (0);
}

static char	*args_to_str(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*temp;

	i = 1;
	str = 0;
	while(i < argc)
	{
		temp = str;
		str = ft_strjoin(str, argv[i++]);
		free(temp);
		if (!str)
			return (NULL);
	}
	return (str);
}

static int	error_message(char *str)
{
	free(str);
	write(2, "Error\n", 6);
	return (0);
}


// MAIN 
// takes input as one string or multiple arguments
// checks input is valid = only integers, no overflow, no duplicates
// formats the input ready for push swap to handle
//
// PUSH_SWAP
// sorts stack A 
// with sa, sb, ss,  ra, rb rr,  rra rrb rrr, pa, pb
// prints out commands executed with \n
