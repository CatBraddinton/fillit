#include "fillit.h"
#include <stdio.h>

int check_if_valid(t_data *data, int *indexes, char **map)
{
	int block;
	int next;
	int i;
	int m_len;

	i = data->current->start;
	block = 0;
	m_len = data->p_map.len - 1;
	while (block < BLOCKS)
	{
		next = indexes[block];
		if (next == 4)
			next = data->p_map.case_four;
		else if (next == 5)
			next = data->p_map.case_five;
		else if (next == 3)
			next = data->p_map.case_three;
		i += next;
		if ((i >= 0) && (i < m_len) && (*map)[i] == '.')
			block++;
		else if ((i >= m_len) || ((i >= 0) && (i < m_len) && (*map)[i] != '.'))
			return (-1);
	}
	return (1);
}

int find_correct_pattern(t_data *data, char **map, int len)
{
	while ((data->current) && (data->current->start < len - 1))
	{	 
		if ((check_if_valid(data, data->current->indexes, map) == 1)
			&& (change_map_state(map, data, data->current->c)) == 1)
		{
			if (data->current->next == NULL)
				return (1);
			data->current = data->current->next;
			data->current->start = 0;
		}
		else
			data->current->start++;
	}
	if (data->current->prev)
	{
		data->current = data->current->prev;
		change_map_state(map, data, '.');
		data->current->start++;
		find_correct_pattern(data, map, len);
	}
	return (0);
}

int 		fillit(t_data *data, int map_size)
{
	t_map	map_data;
	char 	*map;

	map = NULL;
	init_new_map(&map_data, map_size);
	data->p_map = map_data;
	data->current = data->head;
	data->current->start = 0;
	map = ft_strnew(map_data.len);
	create_map(&map, map_data.size, map_data.len);
	if ((find_correct_pattern(data, &map, map_data.len)) == 0)
	{
		ft_strdel(&map);
		map = NULL;
		return (fillit(data, map_data.size + 1));
	}
	ft_putendl(map);
	ft_strdel(&map);
	map = NULL;
	return (1);
}
