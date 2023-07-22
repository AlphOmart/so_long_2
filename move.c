/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:41:11 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/22 13:39:51 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//static void	move_top(t_data *data);
//static void	move_right(t_data *data);
//static void	move_left(t_data *data);
static void	move_down(t_data *data, int *pos);

int	key_press(int keysym, t_data *data)
{
	int		*pos;

	pos = NULL;
	pos = get_pos(data, data->map, pos, 'P');
	pos[0] = pos[0] / data->pic.height;
	pos[1] = pos[1] / data->pic.width;
	if (keysym == XK_Escape)
		finish_game(data);
//	if (keysym == XK_w)
//		move_top(data);
//	if (keysym == XK_d)
//		move_right(data);
//	if (keysym == XK_a)
//		move_left(data);
	if (keysym == XK_s)
		move_down(data, pos);
	return (0);
}

static int	item_left(t_data *data)
{
	int		x;
	int		y;
	int		it_nbr;

	it_nbr = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
			if (data->map[y][x] == data->object->items)
				it_nbr++;
	}
	return (it_nbr);
}

//static void	move_top(t_data *data)
//{
//	int		*pos;
//
//	pos = NULL;
//	pos = get_pos(data, data->map, pos, 'P');
//	pos[0] = pos[0] / data->pic.height;
//	pos[1] = pos[1] / data->pic.width;
//	if (data->map[pos[1] - 1][pos[0]] != data->object->wall)
//	{
//		if (!(data->map[pos[1] - 1][pos[0]] == data->object->exit))
//		{
//			data->map[pos[1] - 1][pos[0]] = data->object->player;
//			data->map[pos[1]][pos[0]] = data->object->path;
//			data->count += 1;
//			printf("count: %d\n", data->count);
//		}
//		else
//		{
//			if (item_left(data) == 0)
//			{
//				printf("Congrats you won with : %d moves !\n", data->count);
//				free(pos);
//				finish_game(data);
//			}
//		}
//	}
//	free(pos);
//}
//
//void	move_right(t_data *data)
//{
//	int		*pos;
//
//	pos = NULL;
//	pos = get_pos(data, data->map, pos, 'P');
//	pos[0] = pos[0] / data->pic.height;
//	pos[1] = pos[1] / data->pic.width;
//	if (data->map[pos[1]][pos[0] + 1] != data->object->wall)
//	{
//		if (!(data->map[pos[1]][pos[0] + 1] == data->object->exit))
//		{
//			data->map[pos[1]][pos[0] + 1] = data->object->player;
//			data->map[pos[1]][pos[0]] = data->object->path;
//			data->count += 1;
//			printf("count: %d\n", data->count);
//		}
//		else
//		{
//			if (item_left(data) == 0)
//			{
//				printf("Congrats you won with : %d moves !\n", data->count);
//				free(pos);
//				finish_game(data);
//			}
//		}
//	}
//	free(pos);
//}
//
//void	move_left(t_data *data)
//{
//	int		*pos;
//
//	pos = NULL;
//	pos = get_pos(data, data->map, pos, 'P');
//	pos[0] = pos[0] / data->pic.height;
//	pos[1] = pos[1] / data->pic.width;
//	if (data->map[pos[1]][pos[0] - 1] != data->object->wall)
//	{
//		if (!(data->map[pos[1]][pos[0] - 1] == data->object->exit))
//		{
//			data->map[pos[1]][pos[0] - 1] = data->object->player;
//			data->map[pos[1]][pos[0]] = data->object->path;
//			data->count += 1;
//			printf("count: %d\n", data->count);
//		}
//		else
//		{
//			if (item_left(data) == 0)
//			{
//				printf("Congrats you won with : %d moves !\n", data->count);
//				free(pos);
//				finish_game(data);
//			}
//		}
//	}
//	free(pos);
//}
//
void	move_down(t_data *data, int *pos)
{
	if (data->map[pos[1] + 1][pos[0]] != data->object->wall)
	{
		if (!(data->map[pos[1] + 1][pos[0]] == data->object->exit))
		{
			data->map[pos[1] + 1][pos[0]] = data->object->player;
			data->map[pos[1]][pos[0]] = data->object->path;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (item_left(data) == 0)
			{
				printf("Congrats you won with : %d moves !\n", data->count);
				free(pos);
				finish_game(data);
			}
		}
	}
	free(pos);
}
