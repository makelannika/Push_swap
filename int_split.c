/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:43:41 by amakela           #+#    #+#             */
/*   Updated: 2023/11/16 15:57:19 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int		word_count(char const *str, char delimiter);
static int		*free_array(int *array);
static int		*fill_array(int *array, char const *str, char delimiter);

int	*int_split(char const *str, char delimiter)
{
	int	*array;

	if (!s)
		return (0);
	array = malloc(sizeof(int) * (word_count(str, delimiter));
	if (!array)
		return (NULL);
	return (fill_array(array, str, delimiter));
}

static int	word_count(char const *str, char delimiter)
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
	long		nbr;
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

static int	*free_array(int *array)
{
	free(array);
	return (NULL);
}

long	ft_atol()
{
}
