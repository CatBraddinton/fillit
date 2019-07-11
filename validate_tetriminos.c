/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 08:14:59 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/11 08:16:29 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_connections(char const *buffer, int i)
{
	int neighbour;

	neighbour = 0;
	if (buffer[i + 1] == '#')
		neighbour++;
	if (buffer[i + 5] == '#')
		neighbour++;
	if (buffer[i - 1] == '#')
		neighbour++;
	if (buffer[i - 5] == '#')
		neighbour++;
	return (neighbour);
}

void			verify_tetrimino_is_valid(char const *buf, int *initial_indexes)
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
			initial_indexes[block] = i;
			connections += check_connections(buf, i);
			block++;
		}
		i++;
	}
	if (connections < 6)
		error_case("error");
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
			error_case("error");
		if (buf[i] == '\n')
		{
			nl++;
			temp = nl * NL_POS - 1;
			if (temp < TETRO_SQUARE && i != temp)
				error_case("error");
		}
		if (buf[i] == '#')
			block++;
		i++;
	}
	if (block != BLOCKS)
		error_case("error");
}
