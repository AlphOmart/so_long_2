/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:50:03 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/21 23:42:04 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*---HEADERS-----------------------------------*/
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

/*---STRUCTURES--------------------------------*/
typedef struct s_pictures
{
	void	*player;
	void	*item;
	void	*wall;
	void	*path;
	void	*exit;
	int		height;
	int		width;
	char	*pl_path;
	char	*it_path;
	char	*w_path;
	char	*pa_path;
	char	*ex_path;
}				t_pic;

typedef struct s_mapping
{
	char	player;
	char	items;
	char	wall;
	char	path;
	char	exit;
	int		pl_nbr;
	int		it_nbr;
	int		ex_nbr;
}				t_mapping;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*window;
	char		**print_map;
	char		**map;
	char		**map_cpy;
	t_mapping	*object;
	t_pic		pic;
	int			count;
	int			width;
	int			height;
}				t_data;

/*---checker.c---------------------------------*/
void	is_valid(t_data *data, int size);

/*---mapping.c---------------------------------*/
void	mapping(t_data *data, char *argv);

/*---render.c----------------------------------*/
void	print_window(t_data *data);

/*---res_lab.c---------------------------------*/
void	can_be_finished(t_data *data);
int		*get_pos(t_data *data, char **map, int *pos, char c);
/*---set_unset_pic.c---------------------------*/
void	set_pic(t_data *data);
int		finish_game(t_data *data);
/*---utils.c-----------------------------------*/
void	free_map(char **map);
void	ft_free(t_data *data, int n);
void	ft_error(char *str, t_data *data, int n);

#endif
