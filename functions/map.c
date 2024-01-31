/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:33:31 by jlu               #+#    #+#             */
/*   Updated: 2024/01/31 16:50:35 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check for map shape and also get width and see if its a rectangle
void	check_map_len(char **map)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != len)
			error_msg_params("Come On! Give me a Rectangle");
		i++;
	}
}

void	check_wall(t_game *game)
{
	size_t	x;
	size_t	y;
	
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			error_msg_params("It needs the best wall");
		y++;
	}
	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			error_msg_params("It needs the best wall");
		x++;
	}
}

// check for map content that only P,C,E,0,1,X and \n is present in the map string
void	check_map_content(char *map)
{
	int	i;
	size_t	chest;
	size_t	exit;
	size_t	player;

	i = 0;
	chest = 0;
	exit = 0;
	player = 0;
	while (map[i++])
	{
		if (map[i] == 'P')
			player++;
		else if (map[i] == 'E')
			exit++;
		else if (map[i] == 'C')
			chest++;
		else if (map[i] != '0' && map[i] != '1' && map[i] != '\n' && map[i] != '\0' && map[i] != 'X')
			error_msg_params("An illegal Char has been found");
	}
	if (exit != 1 || player != 1 || chest < 1)
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

t_game	*check_map(char *mapfile)
{
	char	*map_str;
	char	**map_array;
	t_game	*data;

	map_str = get_map_str(mapfile);
	if (map_str == NULL)
		error_msg_params("Empty Map");
	check_map_content(map_str);
	map_array = ft_split(map_str, '\n');
	check_map_len(map_array);
	data = initialzing_game_struct(map_array);
	check_wall(data);
	temp_map(data);
	free(map_str);
	return (data);
}
