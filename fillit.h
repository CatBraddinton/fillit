/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:05:11 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/09 19:41:20 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

# define TETRO_SQUARE 20
# define MAX_TETRI_NUM 26
# define BLOCKS 4
# define NL_POS 5

typedef	struct		s_map
{
	int				size;
	int				len;
	char			*map_arr;
	int				case_four;
	int				case_five;
	int				case_three;
}					t_map;

typedef struct		s_tetr
{
	char			c;
	int				indexes[BLOCKS];
	struct s_tetr	*next;
	struct s_tetr	*prev;
	int 			start;
}					t_tetr;

typedef struct		s_data
{
	t_tetr			*head;
	t_tetr			*current;
	int				list_size;
	char			curr_c;
	int				temp;
	t_map			p_map;
}					t_data;

void				error_case(char const *str);
int 				get_tetriminos_list(t_data *data);
int					init_map_size(int nb);
int					fillit(t_data *data, int map_size);

void				create_map(char **map, int size, int len);
void				init_new_map(t_map *map, int size);
void				free_list(t_tetr **tetriminos);


int 				validate_tetro(char const *tetro, int *indexes);
int					count_indexes(int *indexes);




void				add_to_list(char const *buffer,
					t_data *init_data);




int				change_map_state(char **map, t_data *data, char state);
void				arr_zero(int **arr);


#endif
