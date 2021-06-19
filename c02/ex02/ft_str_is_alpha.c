int	ft_str_is_alpha(char *str)
{
	int	x;
	int	aux;

	x = 0;
	while (str[x] != '\0')
	{
		aux = 1;
		if (str[x] >= 'a' && str[x] <= 'z')
			aux = 0;
		if (str[x] >= 'A' && str[x] <= 'Z')
			aux = 0;
		if (aux == 1)
			return (0);
		x++;
	}
	return (1);
}
