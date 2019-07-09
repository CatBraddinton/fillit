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

int		check_blocks(char const *buffer, int *indexes)
{
	int i;
	int block;

	i = 0;
	block = 0;
	arr_zero(&indexes);
	while (i < TETRO_SQUARE)
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

int		nl_check(char const *buffer)
{
	int i;
	int nl;
	int temp;

	nl = 0;
	i = 0;
	while (i < TETRO_SQUARE)
	{
		if ((buffer[i] != '\n') && (buffer[i] != '#') && (buffer[i] != '.'))
			return (-1);
		if (buffer[i] == '\n')
		{
			nl++;
			temp = nl * NL_POS - 1;
			if (i != temp)
				return (-1);
		}
		i++;
	}
	return (1);
}

int validate_tetro(char const *buf, int *indexes)
{
	if ((nl_check(buf)) == -1)
		return (-1);
	if ((check_blocks(buf, indexes)) == -1)
		return (-1);
	if ((check_connections(buf, indexes)) == -1)
		return (-1);
	return (1);
}
