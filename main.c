/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:05:34 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/09 20:53:30 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_tetr	*tetriminos;
	t_data	data;

	tetriminos = NULL;
	if (ac != 1 || !av[0])
		error_case("usage: ./fillit filename");
	data.head = tetriminos;
	data.list_size = 0;
	data.curr_c = 'A';
	data.temp = 0;
	if ((get_tetriminos_list(&data)) == -1)
	{
		if (data.head)
			free_list(&(data.head));
		data.head = NULL;
		error_case("error");
	}
	data.temp = init_map_size(data.list_size);
	if ((fillit(&data, data.temp)) == -1)
		error_case("error");
	if (data.head)
		free_list(&(data.head));
	data.head = NULL;
	return (0);
}
