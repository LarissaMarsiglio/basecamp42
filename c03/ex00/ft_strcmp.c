int	ft_strcmp(char *s1, char *s2)
{
	 int	x;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0')
	{
		if (s1[x] != s2[x])
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		x++;
	}
	if ((s1[x] == '\0' && s2[x] != '\0') || (s1[x] != '\0' && s2[x] == '\0'))
		return (s1[x] - s2[x]);
	return (0);
}
