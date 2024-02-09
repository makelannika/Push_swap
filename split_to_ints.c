/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:27:27 by amakela           #+#    #+#             */
/*   Updated: 2024/02/09 15:27:30 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*fill_array(int *array, char *str, char delimiter);
static int	*add_value(int *array, char *str, int strl, int i);

int	*split_to_ints(char *str, char delimiter)
{
	int	count;
	int	*array;

	if (!str)
		return (NULL);
	if (digit_check(str) == -1)
		return (NULL);
	count = num_count(str, delimiter);
	array = malloc(sizeof(int) * count);
	if (!array)
		return (NULL);
	if (!fill_array(array, str, delimiter))
		return (NULL);
	if (count == 1)
		return (free_array(array));
	if (duplicate_check(array, count) == -1)
		return (NULL);
	return (array);
}

int	num_count(char *str, char delimiter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == delimiter)
			i++;
		if (str[i] && str[i] != delimiter)
			count++;
		while (str[i] && str[i] != delimiter)
			i++;
	}
	return (count);
}

static int	*fill_array(int *array, char *str, char delimiter)
{
	int		i;
	int		j;
	int		strl;

	i = 0;
	j = 0;
	while (str[i])
	{
		strl = 0;
		while (str[i] && str[i] != delimiter)
		{
			strl++;
			i++;
		}
		if (strl != 0)
		{
			if (!add_value(array, str, strl, i))
				return (NULL);
		}
		while (str[i] && str[i] == delimiter)
			i++;
	}
	return (array);
}

static int	*add_value(int *array, char *str, int strl, int i)
{
	static int	j = 0;
	char		*nbr_str;
	long		nbr;

	nbr_str = ft_substr(str, i - strl, strl);
	if (nbr_str == NULL)
		return (free_array(array));
	nbr = ft_atol(nbr_str);
	free(nbr_str);
	if (overflow_check(nbr) == -1)
		return (free_array(array));
	array[j++] = (int)nbr;
	return (array);
}

int	*free_array(int *array)
{
	free(array);
	return (NULL);
}
