/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:55:16 by amakela           #+#    #+#             */
/*   Updated: 2024/02/07 19:55:21 by amakela          ###   ########.fr       */
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
		if (!ft_isdigit(str[i]) && str[i] != ' '
			&& str[i] != '+' && str[i] != '-')
			return (error_message());
		if ((ft_isdigit(str[i])) && (!ft_isdigit(str[i + 1])
				&& str[i + 1] != ' ' && str[i + 1] != '\0'))
			return (error_message());
		if ((str[i] == '+' || str[i] == '-')
			&& (!(ft_isdigit(str[i + 1]))))
			return (error_message());
		i++;
	}
	return (1);
}

int	overflow_check(long nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
	{
		error_message();
		return (-1);
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
				return (-1);
			}
		}
		i++;
		j = i + 1;
	}
	return (1);
}
