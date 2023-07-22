/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:12:12 by mwubneh           #+#    #+#             */
/*   Updated: 2023/07/22 17:58:52 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int		get_map_len(char *argv, t_data *data);
static char		**get_map(t_data *data, char **map, char *argv);

void	mapping(t_data *data, char *argv)
{
	int	j;

	j = get_map_len(argv, data) + 1;
	data->map = calloc(sizeof(char *), j);
	if (!data->map)
		ft_error("Error : map allocation", data, 0);
	data->map_cpy = calloc(sizeof(char *), j);
	if (!data->map_cpy)
		ft_error("Error : map_cpy allocation", data, 1);
	get_map(data, data->map, argv);
	get_map(data, data->map_cpy, argv);
	is_valid(data, j);
	data->width = ft_strlen(data->map[0]) - 1;
	data->height = j - 1;
	data->count = 0;
}

static int	get_map_len(char *argv,t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_error("Error : file not found\n", data, -1), -1);
	i = 0;
	while (42)
	{
		line = NULL;
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

static char	**get_map(t_data *data, char **map, char *argv)
{
	int	fd;
	int	i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("Error : bad file access\n", data, 1);
	i = 0;
	while (42)
	{
		map[i] = NULL;
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	close(fd);
	return (map);
}
