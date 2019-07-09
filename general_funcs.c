/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:06:58 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/09 09:00:30 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_case(char const *str)
{
	ft_putendl_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	arr_zero(int **arr)
{
	int block;

	block = 0;
	while (block < BLOCKS)
	{
		(*arr)[block] = 0;
		block++;
	}
}

void	free_list(t_tetr **tetriminos)
{
	t_tetr *node;

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

int		count_indexes(int *indexes)
{
	int i;

	i = BLOCKS - 1;
	while (i > 0)
	{
		indexes[i] -= indexes[i - 1];
		i--;
	}
	if (i == 0)
	{
		indexes[i] = 0;
		return (1);
	}
	return (-1);
}
