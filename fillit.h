#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define TETRO_SQUARE 20
# define MAX_TETRI_NUM 26
# define BLOCKS 4
# define NL_POS 5

typedef struct		s_tetr
{
	char			c;
	int				indexes[BLOCKS];
	struct s_tetr	*next;
	struct s_tetr	*prev;
	int				start;
}					t_tetr;

typedef struct		s_data
{
	t_tetr			*head;
	t_tetr			*current;
	int				list_size;
	int				map_size;
	char			map_char;
	char			tetr_char;
	int				temp;
	char			*map;
}					t_data;

void				error_case(char const *str);
void				arr_zero(int *arr);
void				init_current_data(t_data *data);
void				free_list(t_tetr **tetriminos);

int					get_tetriminos_list(t_data *data, char *filename);
void				first_check_nl_blocks(char const *buf);
void				verify_tetrimino_is_valid(char const *buf, int *indexes);

int					min_map_size(int nb);

int					change_map_state(char *map, t_tetr *node, char state,
					int size);
void				create_map(char *map, int size, int len, char map_char);

int					fillit(t_data *data, int map_size);

#endif
