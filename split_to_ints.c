/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:43:41 by amakela           #+#    #+#             */
/*   Updated: 2024/02/03 21:14:31 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

static int	*fill_array(int *array, char const *str, char delimiter);
// long		get_number(char const *str, int i, int strl);

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
		return (NULL);
	if (duplicate_check(array, count) == -1)
		return (NULL);
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

static int	*fill_array(int *array, char const *str, char delimiter)
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
			if (string == NULL)
				return (free_array(array));
			nbr = ft_atol(string);
			free(string);
			if (overflow_check(nbr) == -1)
				return (free_array(array));
			array[j++] = (int)nbr;
		}
		while (str[i] && str[i] == delimiter)
			i++;
	}
	return (array);
}

// long	get_number(char const *str, int i, int strl)
// {
// 	long	nbr;
// 	char	*string;

// 	string = ft_substr(str, i - strl, strl);
// 	nbr = ft_atol(string);
// 	free(string);
// 	return (nbr);
// }

int	*free_array(int *array)
{
	free(array);
	return (NULL);
}
