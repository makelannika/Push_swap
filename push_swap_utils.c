int	digit_check(char *str)
{
	while(*str)
	{
		if (!(*str >= '0' && *str <= '9') && (*str != ' ')
				&& (*str != '+') && (*str != '-'))
			return (-1);
		*str++;
	}
	return (1);
}

int	duplicate_check(int *array)
{
}
