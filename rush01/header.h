#ifndef HEADER_H
# define HEADER_H

// Headers permitidos
# include <stdlib.h>
# include <unistd.h>

// Tratamento de input
int		translate_char_int(char *p_c, char delim, int *index);

void	string_treatment(char *argv, int **matrix, int size);

int		forbidden_chars(char *args);

int		check(int **int_arr, int size);

// Verificador horizontar e vertical

int		check_col_lines (int i, int j, int **tab, int n);

int		verify (int *index, int n, int **tab);

//Memoria
void	free_all (int **target);

int		**create_int_matrix (int size, int size_y);

//Solucionador
void	solver (int **tab, int **hint_tab, int flag);

int		fill_the_tab (int **tab, int **hint);

void	fill_exceptional (int **tab, int **hint);

//Printer
void	show (int **tab_show);

//Filler para casos especiais
void	filler_v_exp (int **tab_line, int range, int index, int col);

void	filler_h_exp (int *tab_line, int range, int index);

// Search function
int		empty_cell (int **tab, int *line, int *col);

// Check
int		solved (int **tab, int **hint);
#endif