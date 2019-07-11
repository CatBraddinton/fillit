#include "fillit.h"

void	error_case(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	arr_zero(int *arr)
{
	int block;

	block = 0;
	while (block < BLOCKS)
	{
		arr[block] = 0;
		block++;
	}
}

void	free_list(t_tetr **tetriminos)
{
	t_tetr *node;

	node = NULL;
	if ((*tetriminos) && tetriminos)
	{
		node = (*tetriminos);
		while (node)
		{
			(*tetriminos) = node->next;
			free(node);
			node = (*tetriminos);
		}
		tetriminos = NULL;
	}
}

void	init_current_data(t_data *data)
{
	data->list_size = 0;
	data->map_size = 0;
	data->map_char = '.';
	data->map_size = 0;
	data->tetr_char = 'A';
}
