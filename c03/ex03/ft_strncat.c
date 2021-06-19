char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	a;
	unsigned int	size;

	a = 0;
	size = 0;
	while (dest[size])
		size++;
	while (a < nb && src[a])
	{
		dest[size] = src[a];
		size++;
		a++;
	}
	dest[size] = '\0';
	return (dest);
}
