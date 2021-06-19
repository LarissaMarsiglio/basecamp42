#include "header.h"

/*
O '+' e considerado um caractere proibido, alem dos outros 
como alfabetos, simbolos, etc.
*/
int	main (int argc, char **argv)
{
	int	**hints;
	int	**tab;
	int	size;
	int	i;

	i = 0;
	size = 4;
	tab = create_int_matrix(size, size);
	hints = create_int_matrix(size, size);
	if (argc == 2 && forbidden_chars(argv[1]))
	{
		string_treatment(argv[1], hints, size);
		if (check (hints, size))
		{
			solver (tab, hints, 0);
		}
	}
	free_all(hints);
	free_all(tab);
	return (0);
}
