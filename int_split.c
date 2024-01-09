/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:43:41 by amakela           #+#    #+#             */
/*   Updated: 2024/01/09 20:46:18 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int      *free_array(int *array);
static int      count_numbers(char const *str, char delimiter);
static int		*fill_array(int *array, char const *str, char delimiter);
int             find_duplicates(int *array, int num_count);

int	*int_split(char const *str, char delimiter)
{
	int	num_count;
	int	*array;

	if (!s)
		return (NULL);
	num_count = count_numbers(str, delimiter);
	array = malloc(sizeof(int) * num_count);
	if (!array)
		return (NULL);
	array = fill_array(array, str, delimiter);
	if (!array)
		return (NULL);
	if (find_duplicates(array, num_count))
		return  (free_array(array));
	return (array);
}

static int	count_numbers(char const *str, char delimiter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == delimiter)
			i ++;
		if (str[i] && str[i] != delimiter)
			count ++;
		while (str[i] && str[i] != delimiter)
			i ++;
	}
	return (count);
}

static int	*fill_array(int *array, char const *str, char delimiter)
{
	long			nbr;
	unsigned int	strl;
	unsigned int	i;

	i = 0;
	nbr = 0,
	while (str[i])
	{
		strl = 0;
		while (str[i] && str[i] != delimiter)
		{
			strl ++;
			i ++;
		}
		if (strl != 0)
		{
			nbr = ft_atol(ft_substr(str, i - strl, strl));
			if (nbr > INT_MAX || nbr < INT_MIN)
				return (free_array(array));
			array[i++] = nbr;
		}
		while (str[i] && str[i] == delimiter)
			i ++;
	}
	return (array);
}

int	find_duplicates(int *array, int num_count)
{
	int	i;
	int j;

	i = 0
	j = i + 1;
	while (i < num_count)
	{
		while (j <= num_count)
		{
			if (array[i] == array[j++])
				return (1);
		}
		i++;
		j = i + 1;
	}
	return (0);
}

static int	*free_array(int *array)
{
	free(array);
	return (NULL);
}

