/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_lab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:43:48 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/21 23:12:04 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	*get_pos(t_data *data, char **map, int *pos, char c);
static void	resolution(char **map, int x, int y);

void	can_be_finished(t_data *data)
{
	int	x;
	int	y;
	int	*start;

	start = NULL;
	start = get_pos(data, data->map_cpy, start, 'P');
	resolution(data->map_cpy, start[0], start[1]);
	y = -1;
	while (data->map_cpy[++y])
	{
		x = -1;
		while (data->map_cpy[y][++x])
			if (data->map_cpy[y][x] == 'C' || data->map_cpy[y][x] == 'E')
				return (free(start), ft_error(
						"Error : item or exit aren't reachable\n", data, 2));
	}
	free(start);
}

static int	*get_pos(t_data *data, char **map, int *pos, char c)
{
	int	y;
	int	x;

	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (free(pos),
			ft_error("Error : pos alloc failed\n", data, 2), NULL);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
			{
				pos[0] = x;
				pos[1] = y;
				return (pos);
			}
		}
	}
	return (free(pos),
		ft_error("Error : no start position found\n", data, 2), NULL);
}

static void	resolution(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	map[x][y] = 'X';
	resolution(map, x + 1, y);
	resolution(map, x, y + 1);
	resolution(map, x - 1, y);
	resolution(map, x, y - 1);
}
