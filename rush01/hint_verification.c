#include "header.h"

void	inc_greater (int a, int b, int *target, int *highest)
{
	if (*highest == 0)
		*highest = a;
	if (*highest <= b)
		*target += 1;
	if (*highest < b)
		*highest = b;
}

int	verify_hint_h (int **tab, int **hint, int line, int col)
{
	int	highest;
	int	highest_2;
	int	count_2;
	int	count;

	highest = 0;
	highest_2 = 0;
	count_2 = 0;
	count = 0;
	if (line > 3)
		return (1);
	while (tab[line][col])
	{
		inc_greater(tab[line][0], tab[line][col], &count, &highest);
		inc_greater(tab[line][3], tab[line][3 - col], &count_2, &highest_2);
		col += 1;
	}
	if ((count == hint[2][line] && count_2 == hint[3][line]))
	{
		if (!(verify_hint_h(tab, hint, line + 1, 0)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	verify_hint_v (int **tab, int **hint, int col, int line)
{
	int	highest;
	int	highest_2;
	int	count;
	int	count_2;

	highest_2 = 0;
	highest = 0;
	count_2 = 0;
	count = 0;
	if (col > 3)
		return (1);
	while (tab [line])
	{
		inc_greater(tab[0][col], tab[line][col], &count, &highest);
		inc_greater(tab[3][col], tab[3 - line][col], &count_2, &highest_2);
		line += 1;
	}
	if (hint[0][col] == count && hint[1][col] == count_2)
	{
		if (!(verify_hint_v(tab, hint, col + 1, 0)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	solved (int **tab, int **hint)
{
	if (!(verify_hint_h(tab, hint, 0, 0)))
		return (0);
	if (!(verify_hint_v(tab, hint, 0, 0)))
		return (0);
	return (1);
}
