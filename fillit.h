/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:05:11 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/05 17:05:18 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 21
# define MAX_TETRI_NUM 26
# define BLOCKS 4

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
	int				all_fit[BLOCKS];
	struct s_tetr	*next;
	struct s_tetr	*prev;
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

int					read_file(int fd, t_data *data);
void				add_to_list(char const *buffer,
					t_data *init_data);
void				free_list(t_tetr **tetriminos);
void				error_case(char const *str);
int					fillit(t_data *data, int map_size);
t_data				init_new_data(void);
t_map				init_new_map(int list_size);
int					change_map_state(t_map *map, int *indexes, char c);
void				arr_zero(int **arr);
int					init_map_size(int nb);

#endif
