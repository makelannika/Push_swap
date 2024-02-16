/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:18:01 by amakela           #+#    #+#             */
/*   Updated: 2024/02/09 16:18:03 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void		checker(t_node **a);
void		read_instructions(int *arg_count, char ***instructions);
int			validity_check(char **instr, int arg_count);
int			execute(t_node **a, char **instructions, int arg_count);
// void 	ft_print_intlist(t_node *a, t_node *b);

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
	checker(&a);
	free_memory(input, values, &a);
	return (0);
}

void	checker(t_node **a)
{
	char	**instructions;
	int		arg_count;

	arg_count = 0;
	read_instructions(&arg_count, &instructions);
	if (instructions == NULL)
		return ;
	if (validity_check(instructions, arg_count) == -1)
		return ;
	if (execute(a, instructions, arg_count) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	freestr(instructions, arg_count);
}

void	read_instructions(int *arg_count, char ***instructions)
{
	char	*temp;
	char	*line;
	char	*all;

	all = (char *)ft_calloc(1, 1);
	if (!all)
		return ;
	line = get_next_line(0);
	if (!line)
	{
		free(all);
		return ;
	}
	while (line)
	{
		temp = all;
		all = ft_strjoin(all, line);
		(*arg_count)++;
		free(line);
		free(temp);
		if (all == NULL)
			return ;
		line = get_next_line(0);
	}
	*instructions = ft_split(all, '\n');
	free(all);
}

int	validity_check(char **instr, int arg_count)
{
	int		i;
	int		j;
	char	**valid;

	i = 0;
	j = 0;
	valid = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", 32);
	if (valid == NULL)
	{
		freestr(instr, arg_count);
		return (-1);
	}
	while (valid[j] && instr[i])
	{
		if (ft_strncmp(instr[i], valid[j], ft_strlen(instr[i])) == 0)
		{
			i++;
			j = -1;
		}
		j++;
	}
	freestr(valid, 11);
	if (j != 0)
	{
		error_message();
		freestr(instr, arg_count);
		return (-1);
	}
	return (1);
}

int	execute(t_node **a, char **instructions, int arg_count)
{
	int		i;
	t_node	*b;
	// int j = 1;
	i = 0;
	b = NULL;
	while (i < arg_count)
	{
		// ft_printf("\n this is the %i time\n", j);
		// ft_print_intlist(*a, b);
		if (instructions[i][0] == 's')
			swaps(instructions[i], a, b);
		else if (instructions[i][0] == 'p')
			pushes(instructions[i], a, &b);
		else if (instructions[i][0] == 'r')
			rotations(instructions[i], a, &b);
		i++;
		// j++;
	}
	// if (!b)
	// 	ft_printf("b is empty\n");
	if (is_sorted(*a) && b == NULL)
		return (1);
	free_stack(&b);
	return (-1);
}

// void ft_print_intlist(t_node *a, t_node *b)
// {
// 	t_node *temp;
// 	temp = a;

// 	while(a)
// 	{
// 		ft_printf("A list\nvalue:%d\n", a->value);
// 		a = a->next;
// 	}
// 	a = temp;

// 	if(!b)
// 		return;
// 	temp = b;

// 	while(b)
// 	{
// 		ft_printf("B list\nvalue:%d\n", b->value);
// 		b = b->next;
// 	}
// 	b = temp;
// }