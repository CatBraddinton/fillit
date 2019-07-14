#include "fillit.h"

int	check_if_fits(t_map *st_map, t_tetr *tetro, int y, int x)
{
	int block;
	int i;
	int j;

	block = 0;
	while (block < BLOCKS)
	{
		i = y + tetro->x_y[block].y;
		j = x + tetro->x_y[block].x;
		if ((i >= 0 && i < st_map->map_size) && (j >= 0 && j < st_map->map_size) && 
			st_map->map[i][j] == '.')
		{
			tetro->fin_xy[block].y = i;
			tetro->fin_xy[block].x = j;
			block++;
		}	
		else
			return (0);
	}
	return (change_map_state(tetro, st_map, tetro->c));
}

int	put_tetriminos_on_map(t_tetr *tetro, t_map *st_map, int y, int x)
{
	while (y < st_map->map_size)
	{
		while (x < st_map->map_size)
		{
			if (st_map->map[y][x] == st_map->map_char)
				if (check_if_fits(st_map, tetro, y, x))
					return (1);
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

int	fillit(t_tetr *head, t_map *st_map, int map_size)
{
	t_tetr		*current;
	int			y;
	int			x;

	if (!create_map(st_map, map_size, st_map->map_char))
		return (0);
	current = head;
	y = 0;
	x = 0;
	while (current)
	{
		if (!put_tetriminos_on_map(current, st_map, y, x))
		{
			if (current->prev)
			{
				current = current->prev;
				change_map_state(current, st_map, st_map->map_char);
				y = current->fin_xy[0].y;
				x = current->fin_xy[0].x + 1;
			}
			else
			{
				free_map(st_map);
				return (fillit(head, st_map, map_size + 1));
			}
		}
		else
		{
			current = current->next;
			y = 0;
			x = 0;
		}
	}
	return (1);
}
