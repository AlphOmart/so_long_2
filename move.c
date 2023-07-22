/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:41:11 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/22 15:11:28 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_top(t_data *data, int *pos);
static void	move_right(t_data *data, int *pos);
static void	move_left(t_data *data, int *pos);
static void	move_down(t_data *data, int *pos);

int	key_press(int keysym, t_data *data)
{
	int		*pos;

	pos = NULL;
	pos = get_pos(data, data->map, pos, 'P');
	if (keysym == XK_Escape)
	{
		free(pos);
		finish_game(data);
	}
	if (keysym == XK_w)
		move_top(data, pos);
	if (keysym == XK_d)
		move_right(data, pos);
	if (keysym == XK_a)
		move_left(data, pos);
	if (keysym == XK_s)
		move_down(data, pos);
	free(pos);
	return (0);
}

static void	move_top(t_data *data, int *pos)
{
	int	x;
	int	y;

	x = pos[0];
	y = pos[1];
	if (data->map[y - 1][x] != data->object->wall)
	{
		if (data->map[y - 1][x] != data->object->exit)
		{
			data->map[y - 1][x] = data->object->player;
			data->map[y][x] = data->object->path;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (item_left(data) == 0)
			{
				ft_printf("Congrats you won with : %d moves !\n", data->count);
				free(pos);
				finish_game(data);
			}
		}
	}
}

void	move_right(t_data *data, int *pos)
{
	int	x;
	int	y;

	x = pos[0];
	y = pos[1];
	if (data->map[y][x + 1] != data->object->wall)
	{
		if (data->map[y][x + 1] != data->object->exit)
		{
			data->map[y][x + 1] = data->object->player;
			data->map[y][x] = data->object->path;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (item_left(data) == 0)
			{
				ft_printf("Congrats you won with : %d moves !\n", data->count);
				free(pos);
				finish_game(data);
			}
		}
	}
}

void	move_left(t_data *data, int *pos)
{
	int	x;
	int	y;

	x = pos[0];
	y = pos[1];
	if (data->map[y][x - 1] != data->object->wall)
	{
		if (data->map[y][x - 1] != data->object->exit)
		{
			data->map[y][x - 1] = data->object->player;
			data->map[y][x] = data->object->path;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (item_left(data) == 0)
			{
				ft_printf("Congrats you won with : %d moves !\n", data->count);
				free(pos);
				finish_game(data);
			}
		}
	}
}

void	move_down(t_data *data, int *pos)
{
	int	x;
	int	y;

	x = pos[0];
	y = pos[1];
	if (data->map[y + 1][x] != data->object->wall)
	{
		if (data->map[y + 1][x] != data->object->exit)
		{
			data->map[y + 1][x] = data->object->player;
			data->map[y][x] = data->object->path;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (item_left(data) == 0)
			{
				ft_printf("Congrats you won with : %d moves !\n", data->count);
				free(pos);
				finish_game(data);
			}
		}
	}
}
