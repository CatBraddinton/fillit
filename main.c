/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:05:34 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/05 17:24:24 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac != 1 || !av[0])
		error_case("usage: ./fillit filename");
	if ((fd = open("valid_18",  O_RDONLY)) == -1)
		error_case("error");
	data = init_new_data();
	read_file(fd, &data);
	data.temp = init_map_size(data.list_size);
	if ((fillit(&data, data.temp)) == -1)
		error_case("error");
	if (data.head)
		free_list(&(data.head));
	return (0);
}
