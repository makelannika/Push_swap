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

void	checker(t_node **a);
char	**read_instructions(int *arg_count, char ***instructions);
int		validity_check(char *instr);
int		execute(t_node **a, char **instructions, int arg_count);

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
	if (input == NULL)
		return (0);
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
	if (!read_instructions(&arg_count, &instructions))
	{
		if (is_sorted(*a))
			ft_printf("OK\n");
		return ;
	}
	if (execute(a, instructions, arg_count))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	freestr(instructions, arg_count);
}

char	**read_instructions(int *arg_count, char ***instructions)
{
	char	*temp;
	char	*line;
	char	*all;

	all = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!validity_check(line))
		{
			free(line);
			free(all);
			return (NULL);
		}
		temp = all;
		all = ft_strjoin(all, line);
		(*arg_count)++;
		free(line);
		free(temp);
		line = get_next_line(0);
	}
	*instructions = ft_split(all, '\n');
	free(all);
	return (*instructions);
}

int	validity_check(char *instr)
{
	if (ft_strncmp(instr, "sa\n", 3) == 0
		|| ft_strncmp(instr, "sb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(instr, "pa\n", 3) == 0
		|| ft_strncmp(instr, "pb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(instr, "ra\n", 3) == 0
		|| ft_strncmp(instr, "rb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(instr, "rra\n", 4) == 0
		|| ft_strncmp(instr, "rrb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instr, "ss\n", 3) == 0
		|| ft_strncmp(instr, "rr\n", 3) == 0
		|| ft_strncmp(instr, "rrr\n", 4) == 0)
		return (1);
	else
	{
		error_message();
		return (0);
	}
}

int	execute(t_node **a, char **instructions, int arg_count)
{
	int		i;
	t_node	*b;

	i = 0;
	b = NULL;
	while (i < arg_count)
	{
		if (instructions[i][0] == 's')
			swaps(instructions[i], a, b);
		else if (instructions[i][0] == 'p')
			pushes(instructions[i], a, &b);
		else if (instructions[i][0] == 'r')
			rotations(instructions[i], a, &b);
		i++;
	}
	if (is_sorted(*a) && b == NULL)
		return (1);
	free_stack(&b);
	return (0);
}
