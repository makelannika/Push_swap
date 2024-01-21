/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:24:18 by amakela           #+#    #+#             */
/*   Updated: 2024/01/21 18:45:34 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

static int	free_memory(char *str, t_stack_node *a, int flag);

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*input;
	int				*values;
	int				flag;

	a = NULL;
	flag = 0;
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
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	set_values(a);
	set_values(b);
	set_target(b, a);
	set_total_ops(b, a);
	//	push_swap(&a);
	while (b != NULL)
	{
		ft_printf("%d\n", b->target);
		b = b->next;
	}
	free_memory(input, a, flag);
	return (0);
}

int	*error_message(void)
{
	write(2, "Error\n", 6);
	return (NULL);
}

static int	free_memory(char *str, t_stack_node *a, int flag)
{
	if (flag == 1)
		free(str);
	free_stack(a);
	return (0);
}
