/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:44:25 by amakela           #+#    #+#             */
/*   Updated: 2024/02/22 22:11:36 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	checker(t_node **a);
char	**read_instructions(int *arg_count, char ***instructions);
int		validity_check(char *line, char *all);
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
		input = multiple_args(argc, argv);
	else
		input = single_arg(argv);
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
		if (*a && is_sorted(*a))
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
		if (!validity_check(line, all))
			return (NULL);
		temp = all;
		all = ft_strjoin(all, line);
		(*arg_count)++;
		free(line);
		free(temp);
		if (!all)
			return (NULL);
		line = get_next_line(0);
	}
	*instructions = ft_split(all, '\n');
	free(all);
	return (*instructions);
}

int	validity_check(char *line, char *all)
{
	if (ft_strncmp(line, "sa\n", 3) == 0
		|| ft_strncmp(line, "sb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "pa\n", 3) == 0
		|| ft_strncmp(line, "pb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "ra\n", 3) == 0
		|| ft_strncmp(line, "rb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "rra\n", 4) == 0
		|| ft_strncmp(line, "rrb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "ss\n", 3) == 0
		|| ft_strncmp(line, "rr\n", 3) == 0
		|| ft_strncmp(line, "rrr\n", 4) == 0)
		return (1);
	else
	{
		free(line);
		free(all);
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
