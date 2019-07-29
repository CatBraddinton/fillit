/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 03:11:49 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/15 03:11:51 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_connections(char const *buffer, int i, int ret)
{
	int neighbour;

	neighbour = 0;
	if (i + 1 >= 0 && i + 1 <= ret && buffer[i + 1] == '#')
		neighbour++;
	if (i + 5 >= 0 && i + 5 <= ret && buffer[i + 5] == '#')
		neighbour++;
	if (i - 1 >= 0 && i - 1 <= ret && buffer[i - 1] == '#')
		neighbour++;
	if (i - 5 >= 0 && i - 5 <= ret && buffer[i - 5] == '#')
		neighbour++;
	return (neighbour);
}

void			tetro_is_valid(char const *buf, int *initial_indexes, int ret)
{
	int i;
	int block;
	int connections;

	i = 0;
	block = 0;
	connections = 0;
	arr_zero(initial_indexes);
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			connections += check_connections(buf, i, ret);
			initial_indexes[block] = i;
			block++;
		}
		i++;
	}
	if ((connections != 6) && (connections != 8))
		error_case("is not tetrimino, wrong num of connectios\n");
}

void			first_check_nl_blocks(char const *buf)
{
	int i;
	int nl;
	int temp;
	int block;

	i = 0;
	nl = 0;
	block = 0;
	while (buf[i] != '\0')
	{
		if ((buf[i] != '\n') && (buf[i] != '#') && (buf[i] != '.'))
			error_case("file contains wrong symbol\n");
		if (buf[i] == '\n')
		{
			nl++;
			temp = nl * NL_POS - 1;
			if (temp < TETRO_SQUARE && i != temp)
				error_case("wrong tetro in file\n");
		}
		if (buf[i] == '#')
			block++;
		i++;
	}
	if (block != BLOCKS)
		error_case("wrong figure, blocks != 4");
}
