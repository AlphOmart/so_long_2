/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:13:05 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/22 20:17:16 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_free(t_data *data, int n)
{
	if (n == 3)
		free(data->mlx_ptr);
	if (n == 2 || n == 3)
		free(data->object);
	if (n == 1 || n == 2 || n == 3)
		free_map(data->map_cpy);
	if (n == 0 || n == 1 || n == 2 || n == 3)
		free_map(data->map);
	free(data);
}

void	ft_error(char *str, t_data *data, int n)
{
	int i;
	ft_free(data, n);
	i = write(2, str, ft_strlen(str));
	(void)i;
	exit(-1);
}
