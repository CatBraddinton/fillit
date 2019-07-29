/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:16:53 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/16 18:16:55 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	count_y_and_x(t_tetr *node, int block, int i)
{
	if (i == 1)
	{
		node->x_y[block].y = node->x_y[block - 1].y;
		node->x_y[block].x = node->x_y[block - 1].x + 1;
	}
	else if (i == 3)
	{
		node->x_y[block].y = node->x_y[block - 1].y + 1;
		node->x_y[block].x = node->x_y[block - 1].x - 2;
	}
	else if (i == 4)
	{
		node->x_y[block].y = node->x_y[block - 1].y + 1;
		node->x_y[block].x = node->x_y[block - 1].x - 1;
	}
	else if (i == 5)
	{
		node->x_y[block].y = node->x_y[block - 1].y + 1;
		node->x_y[block].x = node->x_y[block - 1].x;
	}
}

static void	count_indexes(t_tetr *node, int *current_indexes)
{
	int i;
	int block;

	block = 1;
	node->x_y[0].y = 0;
	node->x_y[0].x = 0;
	while (block < BLOCKS)
	{
		i = current_indexes[block] - current_indexes[block - 1];
		count_y_and_x(node, block, i);
		block++;
	}
}

static void	add_tetro_to_list(t_data *data, int *current_indexes)
{
	t_tetr *figure;

	if ((figure = (t_tetr *)malloc(sizeof(t_tetr))) == NULL)
		error_case("error");
	if (data->head == NULL)
		data->head = figure;
	else if (data->head)
		data->current->next = figure;
	figure->next = NULL;
	data->list_size++;
	figure->c = data->tetr_char;
	data->tetr_char++;
	data->current = figure;
	count_indexes(figure, current_indexes);
}

static int	read_file(int fd, t_data *data, char *buf, int *current_indexes)
{
	int		ret;

	ret = read(fd, buf, (TETRO_SQUARE + 1));
	buf[ret] = '\0';
	if (ret == 0)
	{
		if (data->has_nl == data->list_size)
			error_case("file has redundant \\ns\n");
		return (1);
	}
	if (ret == -1)
		return (-1);
	if (data->list_size == MAX_TETRI_NUM)
		error_case("file contain more that 26 tetriminos\n");
	if (buf[TETRO_SQUARE - 1] != '\n')
		error_case("no new line, wrong gile\n");
	if (ret == TETRO_SQUARE + 1 && buf[ret - 1] == '\n')
		data->has_nl++;
	first_check_nl_blocks(buf);
	tetro_is_valid(buf, current_indexes, ret);
	add_tetro_to_list(data, current_indexes);
	return (read_file(fd, data, buf, current_indexes));
}

int			get_tetriminos_list(t_data *data, char *filename)
{
	char	*buf;
	int		fd;
	t_tetr	*tetriminos;
	int		*current_indexes;

	tetriminos = NULL;
	data->head = tetriminos;
	data->current = tetriminos;
	data->has_nl = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		error_case("error opening the file\n");
	if ((buf = (char *)malloc((TETRO_SQUARE + 2) * sizeof(char))) == NULL)
		error_case("failed to allocate buf\n");
	if ((current_indexes = (int *)malloc(BLOCKS * sizeof(int))) == NULL)
		error_case("failed to allocate indexes arr\n");
	if ((read_file(fd, data, buf, current_indexes)) == -1)
		error_case("error while reading file\n");
	close(fd);
	free(buf);
	free(current_indexes);
	return (1);
}
