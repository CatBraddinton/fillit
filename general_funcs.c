/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:06:58 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/11 07:29:35 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_case(char const *str)
{
	ft_putendl_fd(str, 1);
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

void	init_current_data(t_data *data)
{
	data->list_size = 0;
	data->map_size = 0;
	data->map_char = '.';
	data->map_size = 0;
	data->tetr_char = 'A';	
}
