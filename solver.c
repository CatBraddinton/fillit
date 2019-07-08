#include "fillit.h"

int find_emty_point(t_map *map, int i, int len)
{
	while (i < len && map->map_arr[i] != '.')
		i++;
	if (i >= len)
		return (-1);
	return (i);
}

int check_if_valid(t_data *data, int *indexes, char **map, int *all_fit)
{
	int block;
	int next;
	int i;
	int m_len;

	i = data->temp;
	block = 0;
	m_len = data->p_map.len;
	arr_zero(&all_fit);
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
			all_fit[block] = i;
		else if ((i >= m_len) || ((i >= 0) && (i < m_len) && (*map)[i] != '.'))
			return (-1);
		block++;
	}
	return (1);
}

int find_correct_pattern(t_data *data, t_map *map, int len)
{
	int i;
	int ret;

	i = data->temp;
	ret = 0;
	if ((i >= 0) && (i < len))
	{
		if (map->map_arr[i] == '.')
		{
			ret = check_if_valid(data, data->current->indexes, &(map->map_arr), data->current->all_fit);
			if (ret == 1 && (change_map_state(map, data->current->all_fit, data->current->c)) == 1)
			{
				if (data->current->next == NULL)
					return (1);
				data->current = data->current->next;
				data->temp = 0;
				return (find_correct_pattern(data, map, map->len));
			}
		}
		if ((ret == -1) || (map->map_arr[i] != '.'))
		{
			data->temp = find_emty_point(map, i + 1, len);
			return (find_correct_pattern(data, map, map->len));
		}
	}
	else if (data->current->prev == NULL)
		return (0);
	else if(data->current->prev)
	{
		data->current = data->current->prev;
		change_map_state(map, data->current->all_fit, '.');
		data->temp = data->current->all_fit[0] + 1;
	}
	return (find_correct_pattern(data, map, map->len));
	
}

int fillit(t_data *data, int map_size)
{
	t_map	map;
	int 	ret;

	map = init_new_map(map_size);
	data->p_map = map;
	data->current = data->head;
	data->temp = 0;
	if ((ret = find_correct_pattern(data, &map, map.len)) == 1)
	{
		ft_putendl(map.map_arr);
		free(map.map_arr);
		return (1);
	}
	if (ret == 0)
	{
		free(map.map_arr);
		return (fillit(data, map_size + 1));
	}
	ft_putstr(map.map_arr);
	free(map.map_arr);
	return (0);
}
