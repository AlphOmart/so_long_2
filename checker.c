/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:57:11 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/22 14:45:27 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_objs(t_data *data);
static void	ft_is_open(t_data *data, int size);
static void	check_content(t_data *data);

void	is_valid(t_data *data, int size)
{
	set_objs(data);
	check_content(data);
	if (data->object->pl_nbr != 1 || data->object->it_nbr <= 0
		|| data->object->ex_nbr != 1)
		return (ft_error("Error : map is invalid\n", data, 2));
	ft_is_open(data, size - 2);
	can_be_finished(data);
}

static void	ft_is_open(t_data *data, int size)
{
	int	y;
	int	x;

	x = ft_strlen(data->map_cpy[0]) - 2;
	while (data->map_cpy[0][x] && data->map_cpy[size][x] && x > 0)
	{
		if (data->map_cpy[0][x] != data->object->wall ||
			data->map_cpy[size][x] != data->object->wall)
			return (ft_error("Error : map not closed\n", data, 2));
		x--;
	}
	y = -1;
	x = ft_strlen(data->map_cpy[0]) - 2;
	while (++y <= size)
		if (data->map_cpy[y][0] != data->object->wall
			|| data->map_cpy[y][x] != data->object->wall)
			ft_error("Error : map not closed\n", data, 2);
}

static void	set_objs(t_data *data)
{
	data->object = malloc(sizeof(t_mapping) * 1);
	if (!data->object)
		return (ft_error("Error : setting object\n", data, 1));
	data->object->player = 'P';
	data->object->items = 'C';
	data->object->wall = '1';
	data->object->path = '0';
	data->object->exit = 'E';
	data->object->pl_nbr = 0;
	data->object->it_nbr = 0;
	data->object->ex_nbr = 0;
}

static void	check_content(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map_cpy[++y])
	{
		x = -1;
		while (data->map_cpy[y][++x])
		{
			if (data->map_cpy[y][x] == data->object->path ||
				data->map_cpy[y][x] == data->object->wall ||
				data->map_cpy[y][x] == '\n')
				;
			else if (data->map_cpy[y][x] == data->object->player)
				data->object->pl_nbr++;
			else if (data->map_cpy[y][x] == data->object->items)
					data->object->it_nbr++;
			else if (data->map_cpy[y][x] == data->object->exit)
				data->object->ex_nbr++;
			else
				return (ft_error("Error : unavailable object\n", data, 3));
		}
		if (ft_strlen(data->map_cpy[y]) != ft_strlen(data->map_cpy[0]))
			return (ft_error("Error : map should be a rectangle\n", data, 2));
	}
}

int	item_left(t_data *data)
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
