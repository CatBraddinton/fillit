/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 08:12:09 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/11 08:14:19 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_map_size(int nb)
{
	int size;
	int total_nb;

	size = 2;
	total_nb = nb * BLOCKS;
	while ((size * size) < total_nb)
		size++;
	return (size);
}

int		change_map_state(char *map, t_tetr *node, char state, int size)
{
	int block;
	int p;
	int next;

	block = 0;
	p = node->start;
	while (block < BLOCKS)
	{
		next = node->indexes[block];
		if (node->indexes[block] == 4)
			next = size;
		else if (node->indexes[block] == 5)
			next = size + 1;
		else if (node->indexes[block] == 3)
			next = size - 1;
		p += next;
		map[p] = state;
		block++;
	}
	return (1);
}

void	create_map(char *map, int size, int len, char map_char)
{
	int	nl_char;

	nl_char = size;
	ft_memset(map, map_char, len - 1);
	while (nl_char < len)
	{
		map[nl_char] = '\n';
		nl_char += size + 1;
	}
}
