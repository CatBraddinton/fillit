/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:15:55 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/22 23:50:05 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if ((i >= 0 && i < st_map->map_size) && (j >= 0 && j < st_map->map_size)
			&& st_map->map[i][j] == '.')
		{
			tetro->fin_xy[block].y = i;
			tetro->fin_xy[block].x = j;
			block++;
		}
		else
			return (0);
	}
	return (1);
}

int	find_correct_pattern(t_tetr *node, t_map *st_map, int y, int x)
{
	if (node == NULL)
		return (0);
	while (y < st_map->map_size)
	{
		while (x < st_map->map_size)
		{
			if (check_if_fits(st_map, node, y, x))
			{
				change_map_state(node, st_map, node->c);
				if (!find_correct_pattern(node->next, st_map, 0, 0))
					return (0);
				change_map_state(node, st_map, '.');
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}

int	fillit(t_tetr *head, t_map *st_map)
{
	st_map->map_char = '.';
	create_map(st_map, st_map->map_size, st_map->map_char);
	while (find_correct_pattern(head, st_map, 0, 0))
	{
		free_map(st_map);
		st_map->map_size++;
		create_map(st_map, st_map->map_size, st_map->map_char);
	}
	print_map(st_map);
	free_map(st_map);
	return (1);
}
