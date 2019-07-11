/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:05:11 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/11 03:35:27 by kdudko           ###   ########.fr       */
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

//enum for errors??

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
	int 			map_size;
	char			map_char;
	char			tetr_char;
	int 			temp2;
}					t_data;

int 				get_tetriminos_list(t_data *data);
int 				validate_tetro(char const *tetro, int *indexes);
int					min_map_size(int nb);
int					fillit(t_data *data, int map_size);
int					change_map_state(char **map, t_tetr *node, char state,
					int size);
void				create_map(char **map, int size, int len, char map_char);
void				free_list(t_tetr **tetriminos);
void				arr_zero(int **arr);
void				error_case(char const *str);
void				init_current_data(t_data *data);

#endif
