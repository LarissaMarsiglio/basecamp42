#include <unistd.h>

void	ft_putchar (char m);
int		print_a (int x, int y, int ncx, int nly);
int		print_c (int x, int y, int ncx, int nly);
int		print_b (int x, int y, int ncx, int nly);
int		g_ncx;
int		g_nly;

void	rush (int x, int y)
{
	g_nly = 1;
	while (g_nly <= y)
	{
		g_ncx = 1;
		while (g_ncx <= x)
		{
			if ((print_a (x, y, g_ncx, g_nly) == 1)
				|| (print_c (x, y, g_ncx, g_nly) == 1)
				|| (print_b (x, y, g_ncx, g_nly) == 1))
				g_ncx++;
			else
			{
				write (1, " ", 1);
				g_ncx++; 
			}
		}
		if (x > 0)
		{
			write (1, "\n", 1);
		}
		g_nly++;
	}
}

int	print_a (x, y, ncx, nly)
{
	if ((ncx == 1 && nly == 1) || (ncx == 1 && nly == y) || (x == 1 && y == 1 ))
	{
		ft_putchar ('A');
		return (1);
	}
	else
		return (0);
}

int	print_c (x, y, ncx, nly)
{
	if ((ncx == x && nly == 1) || (ncx == x && nly == y))
	{
		ft_putchar ('C');
		return (1);
	}
	else
		return (0);
}

int	print_b (x, y, ncx, nly)
{
	if ((ncx > 1 && ncx < x && nly == 1)
		|| (nly > 1 && nly < y && ncx == 1)
		|| (nly > 1 && nly < y && ncx == x)
		|| (ncx > 1 && ncx < x && nly == y))
	{
		ft_putchar ('B');
		return (1);
	}
	else
		return (0);
}
