/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:13:05 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/21 20:22:27 by mwubneh          ###   ########.fr       */
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
	if (n == 1)
		free_map(data->map_cpy);
	if (n == 0 || n == 1)
		free_map(data->map);
	free(data);
}

void	ft_error(char *str, t_data *data, int n)
{
	ft_free(data, n);
	write(2, str, ft_strlen(str));
	exit(-1);
}
