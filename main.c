#include "fillit.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	st_map;

	if (ac != 2)
		error_case("usage: ./fillit [file_name]");
	data.list_size = 0;
	data.tetr_char = 'A';
	get_tetriminos_list(&data, av[1]);
	st_map.map_size = min_map_size(data.list_size);
	st_map.map_char = '.';
	if (fillit(data.head, &st_map, st_map.map_size))
		print_map(&st_map);
	if (data.head)
		free_list(&(data.head));
	data.head = NULL;
	return (0);
}
