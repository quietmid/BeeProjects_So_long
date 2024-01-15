/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:33:31 by jlu               #+#    #+#             */
/*   Updated: 2024/01/15 18:22:44 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// use GNL to get str to be read.

char	**get_map_str(int fd, char *argv[1])
{
	int		i;
	char	**resu;
	char	*line;

	fd = open(fd, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	i = 0;
	while (line != NULL)
	{
		resu[i] = ft_strdup(line); //resu is where joining the read 
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (resu);
}


// check if the map is valid. If the map has other letters than 0, 1, C, E, P, B, then it is not a valid map. 

int	check_map_char(char c)
{
	if (c == '0'|| c == '1'|| c == 'C' || c == 'E' || c == 'P' || c == 'B')
		return (1);
}
void	check_map_vali_length(char **map, t_map *n_map)
{
	int	len;

	n_map->height = 0;
	if (map[n_map->height] != NULL)
	{
		len = ft_strlen(map[n_map->height]);
		if (len < 3)
			error_msg_params("Map too short", map);
		n_map->width = len;
		if (len != n_map->width)
			error_msg_params("Map must be rectangular", map);
		n_map->height++;
	}
	if ((n_map->height - 1) < 3)
		error_msg_params("Map too short", map);
}

void	check_map_vali_content(char **map, t_game *game, t_map *n_map)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < n_map->height)
	{
		while (x < n_map->width)
		{
			if (!check_map_char(map[y][x]))
				error_msg_params("Invalid Map", map);
			if (map[y][x] == 'C')
				game->chest++;
			else if (map[y][x] == 'P')
				game->player++;
			else if (map[y][x] == 'E')
				game->exit++;
			x++;
		}
		x = 0;
		y++;
	}
	if (game->exit != 1 || game->player != 1 || game->chest < 1)
		error_msg_params("Invalid Map", map);
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
				error_msg_params("Invalid Map, not surrounded by Wall", map);
			if ((x == 0 || x == n_map->width - 1) && (map[y][x] != 1))
				error_msg_params("Invalid Map, not surrounded by Wall", map);
		x++;
		}
		x = 0;
		y++;
	}
}

int	parse_map(char *argv[], t_game *game)
{
	int		fd;
	t_map	n_map;

	fd = 0;
	game->map = get_map_str(fd, argv[1]);
	if (game->map == NULL)
		error_msg_params("Empty Map", game->map);
	check_map_vali_length(game->map, &n_map);
	check_map_vali_cont(game->map, *game, &n_map);
	check_wall(game->map, &n_map);
	
}

//void	load_wall(t_game *game)
//{
//	mlx_texture_t *wall;

//	wall = mlx_load_png("assets/walls/wall_2.png");
//	if (!wall)
//		return (0); // image load fail
	
//}

//int	load_images(t_game *game)
//{
//	load_wall(game); // 1
//	load_floor(game); // 0
//	load_exit(game); // E
//	load_player(game); // P
//	load_monster(game); // B
//	load_chest(game); // C
//}