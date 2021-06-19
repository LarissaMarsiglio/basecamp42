#include "header.h"

//Traduz os caracteres para int e para de acordo com o delimitador(delim)
int	translate_char_int (char *p_c, char delim, int *index)
{
	int	result;

	result = 0;
	while (p_c[*index] != '\0')
	{
		if (p_c[*index] >= '0' && p_c[*index] <= '9')
			result = result * 10 + (p_c[*index] - '0');
		if (p_c[*index] == delim)
			break ;
		*index += 1;
	}
	if (p_c[*index - 2] == '-')
		result *= -1;
	return (result);
}

//Responsavel por construir o numero e coloca-los no array 1d "matrix"
void	string_treatment(char *argv, int **matrix, int size)
{
	int	i;
	int	k;
	int	index_access;

	i = 0;
	k = 0;
	index_access = 0;
	while (i < size)
	{
		while (k < size && argv[index_access] != 0)
		{
			if (argv[index_access] >= '0' && argv[index_access] <= '9')
			{
				matrix[i][k] = translate_char_int(argv, ' ', &index_access);
				k += 1;
			}
			index_access++;
		}
		i += 1;
		k = 0;
	}
}

//Nao pode ter caracteres proibidos
int	forbidden_chars(char *args)
{
	int	i;

	i = 0;
	while (args[i] != 0)
	{
		if (args[i] == '-' && (args[i + 1] < '0' || args[i + 1] > '9'))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (args[i] == '.' || args[i] == '/')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if ((args[i] < '-' || args[i] > '9') && args[i] != ' ')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i += 1;
	}
	return (1);
}

//Funcao responsavel para verificar os inputs do usuario
int	check (int **int_arr, int size)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		while (k < size)
		{
			if (int_arr[i][k] == 0 || int_arr[i][k] < 0 || int_arr[i][k] > size)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			k += 1;
		}
		i += 1;
		k = 0;
	}
	return (1);
}
