/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:57:11 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/21 22:11:53 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_open(t_data *data, int size)
{
	int	y;
	int	x;

//	x = ft_strlen(data->map_cpy[0]) - 2;
//	while (data->map_cpy[0][x] && data->map_cpy[size - 1][x] && x > 0)
//	{
//		if (data->map_cpy[0][x] != data->object->wall ||
//			data->map_cpy[size - 1][x] != data->object->wall)
//			return (ft_error("map not closed\n", data, 2));
//		x--;
//	}
	printf("%i\n", size - 1);
	y = -1;
	x = ft_strlen(data->map_cpy[0]) - 2;
	printf("%i\n", x);
	while (++y <= size) {
		if (data->map_cpy[y][0] != data->object->wall
			|| data->map_cpy[y][x] != data->object->wall)
			ft_error("Error : map not closed 2\n", data, 2);
		printf("y = %i '%c'\n", y, data->map_cpy[y][0]);
		printf("y = %i '%c'\n", y, data->map_cpy[y][x]);
	}
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

void	is_valid(t_data *data, int size)
{
	set_objs(data);
	ft_is_open(data, size - 1);
	//check_content();
	//can_be_finished(data);
}
