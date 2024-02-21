/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:35:29 by amakela           #+#    #+#             */
/*   Updated: 2024/02/09 15:35:31 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	digit_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (error_message());
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] != ' ' && str[i] != '\0')
			return (error_message());
	}
	return (1);
}

int	overflow_check(long nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
	{
		error_message();
		return (0);
	}
	return (1);
}

int	duplicate_check(int *array, int count)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < count -1)
	{
		while (j < count)
		{
			if (array[i] == array[j++])
			{
				free(array);
				error_message();
				return (0);
			}
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	error_message(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	free_memory(char *input, int *values, t_node **a)
{
	free(input);
	free(values);
	free_stack(a);
	return (0);
}
