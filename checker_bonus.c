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
void		read_instructions(int *count, char ***instructions);
int			validity_check(char **instr);
int			execute(t_node **a, char **instructions, int arg_count);

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
	if (validity_check(instructions) == -1)
	{
		error_message();
		return ;
	}
	if (execute(a, instructions, arg_count) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	read_instructions(int *count, char ***instructions)
{
	char	*temp;
	char	*line;
	char	*all;

	all = ft_calloc(1, 1);
	line = get_next_line(0);
	while (line)
	{
		temp = all;
		all = ft_strjoin(all, line);
		(*count)++;
		free(line);
		free(temp);
		line = get_next_line(0);
	}
	*instructions = ft_split(all, '\n');
	free(all);
}

int	validity_check(char **instr)
{
	int		i;
	int		j;
	char	**valid;

	i = 0;
	j = 0;
	valid = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", 32);
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
		return (-1);
	return (1);
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
			pushes(instructions[i], a, b);
		else if (instructions[i][0] == 'r')
			rotations(instructions[i], a, b);
		i++;
	}
	if (is_sorted(*a) && b == NULL)
		return (1);
	return (-1);
}
