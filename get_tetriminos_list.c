/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 08:10:23 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/11 08:11:42 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	count_indexes(int *indexes, int *current_indexes)
{
	int block;

	block = 1;
	arr_zero(indexes);
	while (block < BLOCKS)
	{
		indexes[block] = current_indexes[block] - current_indexes[block - 1];
		block++;
	}
}

static void	add_tetro_to_list(t_data *data, int *current_indexes)
{
	t_tetr *figure;
	t_tetr *last_node;

	if ((figure = (t_tetr *)malloc(sizeof(t_tetr))) == NULL)
		error_case("error");
	if (data->head == NULL)
	{
		data->head = figure;
		figure->prev = NULL;
	}
	else if (data->head)
	{
		last_node = data->current;
		figure->prev = last_node;
		last_node->next = figure;
	}
	figure->next = NULL;
	data->list_size++;
	figure->c = data->tetr_char;
	data->tetr_char++;
	data->current = figure;
	count_indexes(figure->indexes, current_indexes);
}

static int	read_file(int fd, t_data *data)
{
	char	buf[TETRO_SQUARE + 2];
	int		ret;
	int		current_indexes[BLOCKS];

	ret = read(fd, buf, (TETRO_SQUARE + 1));
	buf[ret] = '\0';
	if (ret == 0)
	{
		if (data->temp == data->list_size)
			error_case("error");
		return (1);
	}
	if (ret == -1)
		return (-1);
	if (data->list_size == MAX_TETRI_NUM)
		error_case("error");
	if (buf[TETRO_SQUARE - 1] != '\n')
		error_case("error");
	if (ret == TETRO_SQUARE + 1 && buf[ret - 1] == '\n')
		data->temp++;
	first_check_nl_blocks(buf);
	verify_tetrimino_is_valid(buf, current_indexes);
	add_tetro_to_list(data, current_indexes);
	return (read_file(fd, data));
}

int			get_tetriminos_list(t_data *data, char *filename)
{
	int		fd;
	t_tetr	*tetriminos;

	tetriminos = NULL;
	data->head = tetriminos;
	data->current = tetriminos;
	if ((fd = open(filename, O_RDONLY)) == -1)
		error_case("error");
	if ((read_file(fd, data)) == -1)
		error_case("error");
	close(fd);
	return (1);
}
