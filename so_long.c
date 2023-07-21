/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:11:16 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/21 23:37:43 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	j;
	t_data	*data;

	if (argc != 2)
		return ((int)write(2, "Usage : <./so_long> <map.ber>\n", 30));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return ((int)write(2, "Error : invalid map format\n", 27));
	data = malloc (sizeof(t_data) * 1);
	if (!data)
		return ((int)write(2, "Error : data initialisation\n", 28));
	mapping(data, argv[1]);
	data->mlx_ptr = mlx_init();
	if (data->map)
	{
		set_pic(data);
	}
	else
		finish_game(data);
	ft_free(data, 3);
	return (0);
}
