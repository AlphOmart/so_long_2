/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:38:21 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/24 13:02:52 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	print(t_data *data);
static void	print_back(t_data *data);
static void	print_front(t_data *data);
static void	print_img(t_data *data, void *img, int x, int y);

void	print_window(t_data *data)
{
	data->window = mlx_new_window(data->mlx_ptr,
			(data->width * data->pic.width), (data->height * data->pic.height),
			"so_long");
	if (!data->window)
		return (ft_error("Error : windows creation failed\n", data, 3));
	mlx_loop_hook(data->mlx_ptr, &print, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, &key_press, data);
	mlx_hook(data->window, 17, 0, &finish_game, data);
	mlx_loop(data->mlx_ptr);
	finish_game(data);
}

static int	print(t_data *data)
{
	if (mlx_hook(data->window, KeyRelease, KeyReleaseMask, &key_press, data))
	{
		print_back(data);
		print_front(data);
	}
	return (0);
}

static void	print_back(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == data->object->wall)
				print_img(data, data->pic.wall, i, y);
			if (data->map[y][i] != data->object->wall)
				print_img(data, data->pic.path, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}

static void	print_front(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->object->items)
				print_img(data, data->pic.item, i, y);
			if (data->map[y][i] == data->object->player)
				print_img(data, data->pic.player, i, y);
			if (data->map[y][i] == data->object->exit)
				print_img(data, data->pic.exit, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}

static void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->window, img,
		data->pic.width * x, data->pic.height * y);
}
