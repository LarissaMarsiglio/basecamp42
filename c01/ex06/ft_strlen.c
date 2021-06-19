#include <unistd.h>

int	ft_strlen(char *str)
{
	int	string;

	string = 0;
	while (str[string])
		string++
	return (string);
}
