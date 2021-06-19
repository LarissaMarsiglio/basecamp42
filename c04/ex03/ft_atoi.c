int	ft_atoi(char *str)
{
	int	b;
	int	c;

	b = 0;
	c = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			c = c * (-1);
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		b = b * 10;
		b += *str - '0';
		str++;
	}
	return (b * c);
}
