#include "header.h"

//Verifica linha e coluna por numero repetidos
int	check_col_lines (int i, int j, int **tab, int n)
{
	int	aux;

	aux = 0;
	while (aux < 4)
	{
		if (tab[i][aux] == n)
			return (1);
		aux += 1;
	}
	aux = 0;
	while (aux < 4)
	{
		if (tab[aux][j] == n)
			return (1);
		aux += 1;
	}
	return (0);
}

int	verify (int *index, int n, int **tab)
{
	if (check_col_lines(index[0], index[1], tab, n))
		return (0);
	return (1);
}
