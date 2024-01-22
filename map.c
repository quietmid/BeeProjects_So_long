/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:33:31 by jlu               #+#    #+#             */
/*   Updated: 2024/01/22 13:57:50 by jlu              ###   ########.fr       */
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
			error_msg_params("Map is not a rectangle");
		i++;
	}
}
// check for map content that only P,C,E,0,1 and \n is present in the map string

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
		else if (map[i] != '0' && map[i] != '1' && map[i] != '\n' && map[i] != '\0')
			printf("Invald map, invalid char %i\n", i);
			//error_msg_params("Invalid Map, Invalid char");
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

size_t	get_player_pos(t_game *game, char c)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

size_t	get_exit_pos(t_game *game, char c)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E')
			{
				if (c == 'x')
					return (x);
				return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
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