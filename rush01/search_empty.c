#include "header.h"

int	empty_cell (int **tab, int *line, int *col)
{
	*line = 0;
	*col = 0;
	while (*line < 4)
	{
		while (*col < 4)
		{
			if (tab[*line][*col] == 0)
			{
				return (1);
			}
			*col += 1;
		}
		*line += 1;
		*col = 0;
	}
	return (0);
}

int	there_is_zero (int **tab)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (tab[line])
	{
		while (tab[line][col])
		{
			if (tab[line][col] == 0)
				return (0);
			col += 1;
		}
		line += 1;
	}
	return (1);
}
