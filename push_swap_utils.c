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
