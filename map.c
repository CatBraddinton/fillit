/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:22:07 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/05 19:00:16 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			change_map_state(t_map *map, int *indexes, char c)
{
	int block;
	int p;

	block = 0;
	while (block < BLOCKS)
	{
		p = indexes[block];
		map->map_arr[p] = c;
		block++;
	}
	if (block == BLOCKS)
		return (1);
	return (-1);
}

int			init_map_size(int nb)
{
	int size;
	int total_nb;

	size = 2;
	total_nb = nb * BLOCKS;
	while ((size * size) < total_nb)
		size++;
	return (size);
}

static char	*create_map(int size)
{
	char	*map;
	int		len;
	int		nl;

	nl = size;
	len = (size * size) + size;
	map = ft_strnew(len);
	if (map == NULL)
		return (NULL);
	ft_memset(map, '.', len);
	while (nl < len)
	{
		map[nl] = '\n';
		nl += size + 1;
	}
	return (map);
}

t_map		init_new_map(int size)
{
	t_map map;

	map.size = size;
	map.len = (size * size) + size;
	map.case_four = size;
	map.case_five = size + 1;
	map.case_three = size - 1;
	map.map_arr = create_map(map.size);
	return (map);
}
