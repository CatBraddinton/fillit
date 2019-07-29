/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:16:08 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/22 23:54:25 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	st_map;

	if (ac != 2)
	{
		write(1, "usage: ./fillit [path_to_file]\n", 31);
		exit(1);
	}
	data.list_size = 0;
	data.tetr_char = 'A';
	data.has_nl = 0;
	get_tetriminos_list(&data, av[1]);
	st_map.map_size = min_map_size(data.list_size);
	st_map.map = NULL;
	fillit(data.head, &st_map);
	if (data.head)
		free_list(&(data.head));
	data.head = NULL;
	return (0);
}
