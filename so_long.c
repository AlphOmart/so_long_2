#include "so_long.h"

void	ft_error(char *str, t_data *data, int n);

char **get_map(t_data *data, char **map, char *argv)
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

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_error(char *str, t_data *data, int n)
{

	if (n == 1)
		free_map(data->map_cpy);
	if (n == 0 || n == 1)
		free_map(data->map);
	free(data);
	write(2, str, ft_strlen(str));
	exit(-1);
}

int	get_map_len(char *argv)
{
	int	fd;
	int	i;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-2);
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

void	mapping(t_data *data, char *argv)
{
	int	j;

	j = get_map_len(argv) + 1;
	printf("%i", j);
	if (j == 0)
		ft_error("Error : file not found\n", data, 0);
	data->map = calloc(sizeof(char *), j);
	if (!data->map)
		ft_error("Error : map allocation", data, 0);
	data->map_cpy = calloc(sizeof(char *), j);
	if (!data->map_cpy)
		ft_error("Error : map_cpy allocation", data, 1);
	get_map(data, data->map, argv);
	get_map(data, data->map_cpy, argv);
	j = -1;
	while (data->map[++j])
	{
		printf("%s\n", data->map[j]);
		printf("%s\n", data->map_cpy[j]);
	}
}

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (write(2, "Usage : <./so_long> <map.ber>\n", 30));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (write(2, "Error : invalid map format\n", 27));
	data = malloc (sizeof(t_data) * 1);
	if (!data)
		return (write(2, "Error : data initialisation\n", 28));
	mapping(data, argv[1]);
	free_map(data->map);
	free_map(data->map_cpy);
	free(data);
	return (0);
}
