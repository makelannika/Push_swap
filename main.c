/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:24:18 by amakela           #+#    #+#             */
/*   Updated: 2024/01/09 20:46:16 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	int	*array;
	char	*str;
	
	if (argc == 1)
		return (0);
	if (argc > 2)
		str = args_to_str(argv);
	else
		str = argv[1];
	if (!digit_check(str))
		return (error_message(str)); // remember to free str
	array = split_to_ints(str); // uses atol, checks overflow & creates array of ints
	if (!array)
		return (error_message(str)); 
		// push_swap(array);
	free(str);
	return (0);
}

char	*args_to_str(char **argv)
{
	int	i;
	char	str[1];
	char	*temp;

	i = 1;
	str[0] = 0;
	while(i < argc)
	{
		temp = str;
		str = ft_strjoin(str, argv[i++]);
		free(temp);
		if (!str)
			return (-1);
	}
	return (str);
}

int	error_message(char *str)
{
	free(str);
	write(2, "Error\n", 6);
	return (-1);
}

