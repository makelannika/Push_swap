/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:43:41 by amakela           #+#    #+#             */
/*   Updated: 2024/02/01 22:49:34 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

static void	fill_array(int *array, char const *str, char delimiter);

int	*split_to_ints(char *str, char delimiter)
{
	int	count;
	int	*array;

	if (!str)
		return (NULL);
	if (!digit_check(str))
		return (error_message());
	count = num_count(str, delimiter);
	array = malloc(sizeof(int) * count);
	if (!array)
		return (NULL);
	fill_array(array, str, delimiter);
	if (!array)
		return (NULL);
	if (find_duplicates(array, count))
	{
		free_array(array);
		return (error_message());
	}
	return (array);
}

int	num_count(char const *str, char delimiter)
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

static void	fill_array(int *array, char const *str, char delimiter)
{
	int		i;
	int		j;
	int		strl;
	long	nbr;
	char	*string;

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
			string = ft_substr(str, i - strl, strl);
			nbr = ft_atol(string);
			free(string);
			if (!overflow_check(nbr, array))
				exit(0);
			array[j++] = (int)nbr;
		}
		while (str[i] && str[i] == delimiter)
			i++;
	}
}

int	*free_array(int *array)
{
	free(array);
	return (NULL);
}
