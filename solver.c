#include "fillit.h"

static int check_if_valid(t_data *data, int *indexes, char *map, int size)
{
	int block;
	int next;
	int i;
	int m_len;

	i = data->current->start;
	block = 0;
	m_len = (size * size) + size + 1;
	while (block < BLOCKS)
	{
		next = indexes[block];
		if (next == 4)
			next = size;
		else if (next == 5)
			next = size + 1;
		else if (next == 3)
			next = size - 1;
		i += next;
		if ((i >= 0) && (i < m_len) && map[i] == '.')
			block++;
		else if ((i >= m_len) || ((i >= 0) && (i < m_len) && map[i] != '.'))
			return (-1);
	}
	return (1);
}

static int find_correct_pattern(t_data *data, int len)
{
	while ((data->current) && (data->current->start < len - 2))
	{	 
		if ((check_if_valid(data, data->current->indexes, data->map, data->map_size) == 1)
			&& (change_map_state(data->map, data->current, data->current->c, data->map_size)) == 1)
		{
			if (data->current->next == NULL)
				return (1);
			data->current = data->current->next;
			data->current->start = 0;
		}
		else
			data->current->start++;
		
	}
	if (data->current->start >= len - 2 && data->current->prev)
	{
		data->current = data->current->prev;
		change_map_state(data->map, data->current, data->map_char, data->map_size);
		data->current->start++;
	}
	else if (!data->current->prev)
		return (0);
	return (find_correct_pattern(data, len));
}

int 		fillit(t_data *data, int map_size)
{
	int		map_len;

	data->current = data->head;
	data->current->start = 0;
	data->map_size = map_size;
	map_len = map_size * map_size + map_size;
	data->map = ft_strnew(map_len);
	create_map(data->map, map_size, map_len, data->map_char);
	if (find_correct_pattern(data, map_len))
	{
		ft_putstr(data->map);
		return (1);
	}
	ft_strdel(&(data->map));
	data->map = NULL;
	return (fillit(data, data->map_size + 1));
}
