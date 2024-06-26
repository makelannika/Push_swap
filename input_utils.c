/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:24:43 by amakela           #+#    #+#             */
/*   Updated: 2024/02/09 15:24:47 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*multiple_args(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*temp;

	i = 1;
	if (!check_multiple(argc, argv))
	{
		error_message();
		return (NULL);
	}
	str = space_join("", argv[i++]);
	while (i < argc)
	{
		if (!str)
			return (NULL);
		temp = str;
		str = space_join(str, argv[i++]);
		free(temp);
	}
	return (str);
}

char	*single_arg(char **argv)
{
	char	*str;

	str = ft_strdup(argv[1]);
	if (!str)
		return (NULL);
	if (!check_single(str))
	{
		error_message();
		return (NULL);
	}
	return (str);
}

char	*space_join(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == 0 && s2 == 0)
		return (ft_strdup(""));
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	str = malloc (ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	while (s1[i])
		str[i++] = s1[j++];
	j = 0;
	str[i++] = 32;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
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

int	free_memory(char *input, int *values, t_node **a)
{
	free(input);
	free(values);
	free_stack(a);
	return (0);
}
