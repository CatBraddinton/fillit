#include "fillit.h"

static int add_tetro_to_list(char const *buf, t_data *data)
{
	t_tetr *figure;
	t_tetr *last_node;

	figure = (t_tetr *)malloc(sizeof(t_tetr));
	if (figure == NULL)
		return (-1);
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
	if ((validate_tetro(buf, figure->indexes)) == -1 ||
		(count_indexes(figure->indexes)) == -1)
		return (-1);
	return (1);
}

static int	read_file(int fd, t_data *data)
{
	char	*buf;
	int		ret;
	
	buf = ft_strnew(TETRO_SQUARE + 1);
	ret = read(fd, buf, (TETRO_SQUARE + 1));
	if (ret == 0)
	{
		if (data->temp == data->list_size)
			error_case("error");
		return (1);
	}
	if ((data->list_size == MAX_TETRI_NUM) || (ret == -1) 
		|| (buf[TETRO_SQUARE - 1] != '\n'))
		error_case("error");
	if (ret == TETRO_SQUARE + 1 && buf[ret - 1] == '\n')
		data->temp++;
	if ((add_tetro_to_list(buf, data)) == -1)
		return (-1);
	return (read_file(fd, data));
}

int			get_tetriminos_list(t_data *data)
{
	int		fd;

	if ((fd = open("valid_18",  O_RDONLY)) == -1)
		error_case("error");
	if ((read_file(fd, data)) == -1)
		return (-1);
	close(fd);
	return (1);
}