/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_and_frees.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:06:58 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/05 17:26:20 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_case(char const *str)
{
	ft_putendl_fd(str, 1);
	exit(EXIT_FAILURE);
}

int		read_file(int fd, t_data *data)
{
	char	buf[BUFF_SIZE];
	int		ret;

	if (data->list_size == MAX_TETRI_NUM)
		error_case("error");
	if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
		return (0);
	if (ret == -1)
		error_case("error");
	buf[ret] = '\0';
	add_to_list(buf, data);
	return (read_file(fd, data));
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

t_data	init_new_data(void)
{
	t_data temp;
	t_tetr *head;

	head = NULL;
	temp.list_size = 0;
	temp.curr_c = 'A';
	temp.head = head;
	temp.current = head;
	return (temp);
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
