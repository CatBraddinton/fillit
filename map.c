/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:22:07 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/09 21:13:59 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			change_map_state(char **map, t_data *data, char state)
{
	int block;
	int p;
	int next;

	block = 0;
	p = data->current->start;
	while (block < BLOCKS)
	{
		next = data->current->indexes[block];
		if (data->current->indexes[block] == 4)
			next = data->p_map.case_four;
		else if (data->current->indexes[block] == 5)
			next = data->p_map.case_five;
		else if (data->current->indexes[block] == 3)
			next = data->p_map.case_three;
		p += next;
		(*map)[p] = state;
		block++;
	}
	return (1);
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

void	create_map(char **map, int size, int len)
{
	int	nl;

	nl = size;
	ft_memset((*map), '.', len);
	while (nl < len)
	{
		(*map)[nl] = '\n';
		nl += size + 1;
	}
	(*map)[len - 1] = '\n';
}

void		init_new_map(t_map *map, int size)
{
	map->size = size;
	map->len = (size * size) + size;
	map->case_four = size;
	map->case_five = size + 1;
	map->case_three = size - 1;
}
