int	main(int argc, char **argv)
{
	if (argc == 1)
		return (-1);
	if (argc == 2)
	{
		if (!digit_check(argv[1]))
			return (-1);
		// int_split(argv[1]); uses atol, checks overflow &  creates array of ints
		// duplicate_check(int *array), free array and quit if necessary
	}
	else
	{
		// loop digit_check()
		// atol, overflow check & create array of ints
		// duplicate_check(int *array), free array & quit if necessary 
	}

	return (0);
}
