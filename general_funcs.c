/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 23:38:51 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/22 23:45:30 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_case(char const *s)
{
	(void)s;
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}

void	arr_zero(int *arr)
{
	int block;

	block = 0;
	while (block < BLOCKS)
	{
		arr[block] = 0;
		block++;
	}
}

void	free_list(t_tetr **tetriminos)
{
	t_tetr *node;

	node = NULL;
	if ((*tetriminos) && tetriminos)
	{
		node = (*tetriminos);
		while (node)
		{
			(*tetriminos) = node->next;
			free(node);
			node = (*tetriminos);
		}
		tetriminos = NULL;
	}
}

void	print_map(t_map *st_map)
{
	int i;

	i = 0;
	while (i < st_map->map_size)
	{
		write(1, st_map->map[i], st_map->map_size);
		write(1, "\n", 1);
		i++;
	}
}

void	free_map(t_map *st_map)
{
	int i;

	i = 0;
	while (i < st_map->map_size)
	{
		free(st_map->map[i]);
		i++;
	}
	free(st_map->map);
	st_map->map = NULL;
}
