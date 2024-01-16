/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:33:31 by jlu               #+#    #+#             */
/*   Updated: 2024/01/16 17:21:37 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check if the map is valid. If the map has other letters than 0, 1, C, E, P, B, then it is not a valid map. 

int	check_map_char(char c)
{
	if (c == '0'|| c == '1'|| c == 'C' || c == 'E' || c == 'P' || c == 'B' || c == '\n')
		return (1);
	return (0);
}

void	check_wall(char **map, t_map *n_map)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (y < n_map->height)
	{
		while (x < n_map->width)
		{
			if ((y == 0 || y == n_map->height - 1) && (map[y][x] != 1))
				error_msg_params("Invalid Map, not surrounded by Wall");
			if ((x == 0 || x == n_map->width - 1) && (map[y][x] != 1))
				error_msg_params("Invalid Map, not surrounded by Wall");
		x++;
		}
		x = 0;
		y++;
	}
}

// check for map shape and also get its length and width
void	check_map_len(char **map, t_map *dim)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != len)
			error_msg_params("Map is not a rectangle");
		i++;
	}
	dim->width = len;
	dim->height = i - 1;
}
// check for map content that only P,C,E,0,1 and \n is present in the map string

void	check_map_content(char *map, t_game *game)
{
	int	i;

	game->chest = 0;
	game->exit = 0;
	game->player = 0;
	while (map[i++])
	{
		if (map[i] == 'P')
			game->player++;
		else if (map[i] == 'E')
			game->exit++;
		else if (map[i] == 'C')
			game->chest++;
		else if (map[i] != '0' && map[i] != '1' && map[i] != '\n')
			error_msg_params("Invalid Map, Wrong Charater");
	}
	if (game->exit != 1 || game->player != 1 || game->chest < 1)
		error_msg_params("Invalid Map, # of Player, chest, or exit is wrong");
}

// use GNL to get one giant str to be read.

char	*get_map_str(char *mapfile)
{
	int		fd;
	char	*resu;
	char	*line;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (NULL);
	resu = ft_calloc(1,1);
	if (!resu)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			resu = ft_strjoin(resu, line);
			free(line);
		}
		else
			break ;
	}
	close(fd);
	return (resu);
}

t_game	*check_map(char *mapfile, t_game *game)
{
	char	*map_str;
	char	**map_array;
	t_game	*data;
	t_map	*dim;

	map_str = get_map_str(mapfile);
	if (map_str == NULL)
		error_msg_params("Empty Map");
	check_map_content(map_str, game);
	map_array = ft_split(map_str, '\n');
	check_map_len(map_array, dim);
	check_wall(game->map, &n_map);
	return (data);
}

//int	main(int argc, char **argv)
//{
//	int	fd;
//	char	**line;
//	int	i;

//	fd = open(argv[1], O_RDONLY);

//	if (fd == -1)
//	{
//		perror("Error opening file");
//		return (1);
//	}
//	i = 0;
//	line = get_map_str(fd, &argv[1]);
//	if (line == NULL)
//		return (0);
//	while (line[i] != NULL)
//	{
//		printf("%s", line[i]);
//		free(line[i]);
//		i++;
//	}
//	close(fd);
//	return 0;
//}

	//while ((line = get_next_line(fd)) != NULL)
	//{
	//	printf("%s", line);
	//	free(line);
	//}