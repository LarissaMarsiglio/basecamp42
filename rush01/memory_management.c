#include "header.h"

//Libera a memoria que foi alocada para os vetores
void	free_all (int **target)
{
	int	i;

	i = 0;
	while (target[i] != 0)
	{
		free(target[i]);
		i += 1;
	}
	free(target);
}

//Aloca uma x * y de memoria do tipo int* e int**
int	**create_int_matrix (int size, int size_y)
{
	int		i;
	int		**matrix;
	void	*void_ptr;

	i = 0;
	void_ptr = 0;
	matrix = (int **)malloc(size_y * 8);
	if (matrix == void_ptr)
		write(1, "Error\n", 6);
	while (i < size_y)
	{
		matrix[i] = (int *)malloc(size * 8);
		if (matrix[i] == void_ptr)
			write(1, "Error\n", 6);
		i++;
	}
	return (matrix);
}
