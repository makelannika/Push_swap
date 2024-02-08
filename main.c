/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:24:18 by amakela           #+#    #+#             */
/*   Updated: 2024/02/03 21:12:54 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	free_memory(char *input, int *values, t_node **a);

int	main(int argc, char **argv)
{
	t_node	*a;
	char	*input;
	int		*values;

	a = NULL;
	if (argc == 1)
		return (0);
	if (argv[1][0] == '\0')
		return (error_message());
	if (argc > 2)
		input = args_to_str(argc, argv);
	else
		input = ft_strdup(argv[1]);
	values = split_to_ints(input, 32);
	if (!values)
	{
		free(input);
		return (0);
	}
	create_stack(&a, values, num_count(input, 32));
	sort(&a);
	free_memory(input, values, &a);
	return (0);
}

int	error_message(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

static int	free_memory(char *input, int *values, t_node **a)
{
	free(input);
	free(values);
	free_stack(a);
	return (0);
}
