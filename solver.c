#include "fillit.h"
#include <stdio.h>

static int	find_empty_point(char *map, int i)
{
	while (map[i] != '\0' && map[i] != '.')
		i++;
	return (i);
}

static int	put_tetro_on_map(t_data *data, int *indexes, int len, int i)
{
	int block;
	int next;

	block = 0;
	while (block < BLOCKS)
	{
		next = indexes[block];
		if (next == 4)
			next = data->map_size;
		else if (next == 5)
			next = data->map_size + 1;
		else if (next == 3)
			next = data->map_size - 1;
		i += next;
		if ((i >= 0) && (i < len) && data->map[i] == '.')
			block++;
		else if ((i >= len) || ((i >= 0) && (i < len) && data->map[i] != '.'))
			return (0);
	}
	if (block == BLOCKS)
		return (1);
	return (0);
}

static int	find_correct_pattern(t_data *data, int len)
{
	int empty;

	while (data->current)
	{
		empty = find_empty_point(data->map, data->current->start);
		while (empty >= 0 && empty < len)
		{
			if (put_tetro_on_map(data, data->current->indexes,len, empty))
			{
				data->current->start = empty;
				change_map_state(data->map, data->current, data->current->c, data->map_size);
				data->current = data->current->next;
				if (data->current)
					data->current->start = 0;
				break ;
			}
			empty++;
		}
		if (empty >= len)
		{
			if (data->current->prev == NULL)
				return (0);
			data->current = data->current->prev;
			data->current->start++;
		}
	}
	return (1);
}

int			fillit(t_data *data, int map_size)
{
	int		map_len;
	int		i;

	i = 0;
	data->current = data->head;
	data->current->start = 0;
	data->map_size = map_size;
	map_len = map_size * map_size + map_size;
	data->map = (char *)malloc((map_len + 1) * sizeof(char));
	create_map(data->map, map_size, map_len, data->map_char);
	if ((find_correct_pattern(data, map_len) == 1))
	{
		while (data->map[i])
			write(1, &data->map[i++], 1);
		return (1);
	}
	free(data->map);
	data->map = NULL;
	return (fillit(data, data->map_size + 1));
}
