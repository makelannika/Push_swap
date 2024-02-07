/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:52:05 by amakela           #+#    #+#             */
/*   Updated: 2024/02/03 21:14:33 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

char	*args_to_str(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*temp;

	i = 1;
	str = ft_strjoin("", argv[i++]);
	while (i < argc)
	{
		temp = str;
		str = ft_strjoin(str, argv[i++]);
		free(temp);
		if (!str)
			return (NULL);
	}
	return (str);
}

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

long	ft_atol(char *str)
{
	int		i;
	long	nbr;
	long	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == 32)
		i ++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = 10 * nbr + str[i++] - '0';
	return (nbr * sign);
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
