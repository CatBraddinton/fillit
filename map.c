#include "fillit.h"

int	min_map_size(int nb)
{
	int size;
	int total_nb;

	size = 2;
	total_nb = nb * BLOCKS;
	while ((size * size) < total_nb)
		size++;
	return (size);
}

int	create_map(t_map *st_map, int size, char c)
{
	int i;
	int j;

	i = 0;
	st_map->map_size = size;
	if ((st_map->map = (char **)malloc(size * sizeof(char *))) == NULL)
		return (0);
	while (i < size)
	{
		j = 0;
		st_map->map[i] = (char *)malloc((size + 1) * sizeof(char));
		if (st_map->map[i] == NULL)
			return (0);
		while (j < size)
		{
			st_map->map[i][j] = c;
			j++;
		}
		st_map->map[i][j] = '\0';
		i++;
	}
	return (1);
}

int	change_map_state(t_tetr *tetro, t_map *st_map, char state)
{
	int y;
	int x;
	int block;

	block = 0;
	while (block < BLOCKS)
	{
		y = tetro->fin_xy[block].y;
		x = tetro->fin_xy[block].x;
		st_map->map[y][x] = state;
		block++;
	}
	return (1);
}
