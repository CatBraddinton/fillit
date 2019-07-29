/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:16:20 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/16 18:16:22 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct		s_indexes
{
	int				x;
	int				y;
}					t_indexes;

typedef struct		s_map
{
	char			**map;
	int				map_size;
	char			map_char;
}					t_map;

typedef struct		s_tetr
{
	char			c;
	struct s_tetr	*next;
	t_indexes		x_y[BLOCKS];
	t_indexes		fin_xy[BLOCKS];
}					t_tetr;

typedef struct		s_data
{
	t_tetr			*head;
	t_tetr			*current;
	int				list_size;
	char			tetr_char;
	int				has_nl;
}					t_data;

void				error_case(char const *str);
void				arr_zero(int *arr);
void				free_list(t_tetr **tetriminos);
int					get_tetriminos_list(t_data *data, char *filename);
void				first_check_nl_blocks(char const *buf);
void				tetro_is_valid(char const *buf, int *indexes, int ret);
int					min_map_size(int nb);
int					fillit(t_tetr *head, t_map *st_map);
int					create_map(t_map *st_map, int size, char c);
void				print_map(t_map *st_map);
int					change_map_state(t_tetr *tetro, t_map *st_map, char state);
void				free_map(t_map *st_map);

#endif
