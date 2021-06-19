char	*ft_strcapitalize(char *str)
{
	int	x;
	int	aux;

	x = 0;
	aux = 0;
	while (str[x] != '\0' )
	{
		if ((str[x] >= 'a' && str[x] <= 'z') && aux == 0)
		{
			str[x] = str[x] - 32;
			aux = 1;
		}
		else if ((str[x] >= 'a' && str[x] <= 'z') && aux == 1)
			aux = 1;
		else if ((str[x] >= 'A' && str[x] <= 'Z') && aux == 1)
			aux = 1;
		else if ((str[x] >= 'A' && str[x] <= 'Z') && aux == 0)
			aux = 1;
		else if (str[x] >= '0' && str[x] <= '9')
			aux = 1;
		else
			aux = 0;
		x++;
	}
	return (str);
}
