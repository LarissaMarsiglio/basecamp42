#include "header.h"

int	greater_than_zero (int i)
{
	if (i > 0)
		return (-1);
	else
		return (1);
}

void	filler_h_exp (int *tab_line, int range, int index)
{
	int	i;
	int	p;
	int	direction;

	i = index;
	p = 0;
	direction = greater_than_zero (i);
	if (range == 4)
	{
		while (p < range)
		{
			tab_line[i] = p + 1;
			i += 1 * direction;
			p += 1;
		}
	}
	else
	{
		tab_line[index] = 4;
	}
}

void	filler_v_exp (int **tab_col, int range, int index, int col)
{
	int	i;
	int	number;
	int	direction;

	number = 0;
	i = index;
	direction = greater_than_zero (i);
	if (range == 4)
	{
		while (number < range)
		{
			number += 1;
			tab_col[i][col] = number;
			i += 1 * direction;
		}
	}
	else
	{
		tab_col[index][col] = 4;
	}
}
