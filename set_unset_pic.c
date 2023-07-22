/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:31:51 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/22 12:00:49 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_pic(t_data *data)
{
	data->pic.height = 32;
	data->pic.width = 32;
	data->pic.w_path = "./sprites/wall.xpm";
	data->pic.pa_path = "./sprites/path.xpm";
	data->pic.ex_path = "./sprites/exit.xpm";
	data->pic.it_path = "./sprites/item.xpm";
	data->pic.pl_path = "./sprites/player.xpm";
	data->pic.wall = mlx_xpm_file_to_image(data->mlx_ptr, data->pic.w_path,
			&(data->pic.width), &(data->pic.height));
	data->pic.path = mlx_xpm_file_to_image(data->mlx_ptr,
			data->pic.pa_path, &(data->pic.width), &(data->pic.height));
	data->pic.exit = mlx_xpm_file_to_image(data->mlx_ptr, data->pic.ex_path,
			&(data->pic.width), &(data->pic.height));
	data->pic.item = mlx_xpm_file_to_image(data->mlx_ptr,
			data->pic.it_path, &(data->pic.width), &(data->pic.height));
	data->pic.player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->pic.pl_path, &(data->pic.width), &(data->pic.height));
}

int	finish_game(t_data *data)
{
	if (data->map != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->pic.wall);
		mlx_destroy_image(data->mlx_ptr, data->pic.path);
		mlx_destroy_image(data->mlx_ptr, data->pic.item);
		mlx_destroy_image(data->mlx_ptr, data->pic.player);
		mlx_destroy_image(data->mlx_ptr, data->pic.exit);
	//	mlx_destroy_window(data->mlx_ptr, data->window);
	}
	mlx_destroy_display(data->mlx_ptr);
//	ft_free(data, 3);
	return (0);
}
