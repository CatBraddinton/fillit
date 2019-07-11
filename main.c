#include "fillit.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		error_case("usage: ./fillit filename");
	init_current_data(&data);
	get_tetriminos_list(&data, av[1]);
	data.map_size = min_map_size(data.list_size);
	fillit(&data, data.map_size);
	if (data.head)
		free_list(&(data.head));
	data.head = NULL;
	return (0);
}
