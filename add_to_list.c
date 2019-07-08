/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:41:54 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/05 18:10:37 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_connections(char const *buffer, int *indexes)
{
	int block;
	int conn;
	int i;

	block = 0;
	conn = 0;
	while (block < BLOCKS)
	{
		i = indexes[block];
		if (buffer[i + 1] == '#')
			conn++;
		if (buffer[i + 5] == '#')
			conn++;
		if (buffer[i - 1] == '#')
			conn++;
		if (buffer[i - 5] == '#')
			conn++;
		block++;
	}
	if (conn < 6)
		return (-1);
	return (1);
}

int		low_buf_check(char const *buffer)
{
	int i;
	int nl;
	int step;
	int temp;
	int block;

	block = 0;
	nl = 0;
	i = 0;
	step = 5;
	while (i < BUFF_SIZE - 1)
	{
		if ((buffer[i] != '\n') && (buffer[i] != '#') && (buffer[i] != '.'))
			return (-1);
		if (buffer[i] == '\n')
		{
			nl++;
			temp = (step * nl) - 1;
			if (temp != i)
				return (-1);
		}
		i++;
	}
	return (1);
}

int		check_blocks(char const *buffer, int *indexes)
{
	int i;
	int block;

	i = 0;
	block = 0;
	arr_zero(&indexes);
	while (buffer[i])
	{
		if (buffer[i] == '#')
		{
			indexes[block] = i;
			block++;
			if (block > BLOCKS)
				return (-1);
		}
		i++;
	}
	return (1);
}

void	find_blocks(char const *buffer, int *indexes)
{
	int i;

	i = BLOCKS - 1;
	if ((low_buf_check(buffer)) == -1)
		error_case("error");
	if ((check_blocks(buffer, indexes)) == -1)
		error_case("error");
	if ((check_connections(buffer, indexes)) == -1)
		error_case("error");
	while (i > 0)
	{
		indexes[i] -= indexes[i - 1];
		i--;
	}
	indexes[i] = 0;
}

void	add_to_list(char const *buffer, t_data *data)
{
	t_tetr *figure;
	t_tetr *last_node;

	figure = (t_tetr *)malloc(sizeof(t_tetr));
	if (figure == NULL)
		error_case("node allocation error");
	if (data->head == NULL)
		data->head = figure;
	else if (data->head)
	{
		last_node = data->current;
		figure->prev = last_node;
		last_node->next = figure;
	}
	figure->next = NULL;
	data->list_size++;
	figure->c = data->curr_c;
	data->curr_c++;
	data->current = figure;
	find_blocks(buffer, figure->indexes);
}
