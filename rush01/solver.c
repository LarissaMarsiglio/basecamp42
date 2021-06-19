#include "header.h"

//Funcao que vai resolver o resto
int	fill_the_tab (int **tab, int **hint)
{
	int	index[2];
	int	n;

	n = 1;
	index[0] = 0;
	index[1] = 0;
	if (empty_cell (tab, &index[0], &index[1]))
	{
		while (n <= 4)
		{
			if (verify(index, n, tab))
			{
				tab[index[0]][index[1]] = n;
				if (fill_the_tab (tab, hint))
					return (1);
				tab[index[0]][index[1]] = 0;
			}
			n += 1;
		}
	}
	else
		if (solved(tab, hint))
			return (1);
	return (0);
}

//Funcao auxiliar para chamar as outras 
//funcoes porque passava do limite de linha
void	filler_caller (int line, int col, int **tab, int **hint)
{
	if (line < 2 && (hint[line][col] == 1 || hint[line][col] == 4))
	{
		if (line == 0)
			filler_v_exp (tab, hint[line][col], 0, col);
		else
			filler_v_exp (tab, hint[line][col], 4 - 1, col);
	}
	if (line >= 2 && (hint[line][col] == 1 || hint[line][col] == 4))
	{
		if (line == 2)
			filler_h_exp (tab[col], hint[line][col], 0);
		else
			filler_h_exp (tab[col], hint[line][col], 4 - 1);
	}
}

//Funcao que vai preencher o caso excepcional: 4 -> 1, 1 <- 4 e 1
void	fill_exceptional (int **tab, int **hint)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (hint[line])
	{
		while (hint[line][col])
		{
			filler_caller (line, col, tab, hint);
			col += 1;
		}
		line += 1;
		col = 0;
	}
}

//Print na tela
void	show(int **show_tab)
{
	int		i;
	int		k;
	char	aux;

	i = 0;
	k = 0;
	while (i < 4)
	{
		while (k < 4)
		{
			aux = '0' + show_tab[i][k];
			write(1, &aux, 1);
			k += 1;
		}
		write(1, "\n", 1);
		i += 1;
		k = 0;
	}
}

//Funcao que vai chamar as outras
void	solver (int **tab, int **hint_tab, int flag)
{
	if (flag == 0)
	{
		fill_exceptional(tab, hint_tab);
		flag = 1;
	}
	if (fill_the_tab (tab, hint_tab))
	{
		show(tab);
	}
	else
	{
		write (1, "Error\n", 6);
	}
}
