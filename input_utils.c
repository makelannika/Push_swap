#include "push_swap.h"

int	digit_check(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != ' ')
				&& (str[i] != '+') && (str[i] != '-'))
			return (-1);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	int	i;
	long	nbr;
	long	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
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

int	find_duplicates(int *array, int num_count)
{
	int	i;
	int j;

	i = 0;
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

