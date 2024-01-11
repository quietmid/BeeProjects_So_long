/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:33:31 by jlu               #+#    #+#             */
/*   Updated: 2024/01/11 18:30:56 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// use GNL to get str to be read.

static char	get_map_str(char *map_path)
{
	int		fd;
	char	*resu;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	resu = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		resu = ft_strjoin();
	}
}

// check if the map is valid. If the map has other letters than 0, 1, C, E, P, B, then it is not a valid map. 

int	check_map_char(char c)
{
	if (c == '0'|| c == '1'|| c == 'C' || c == 'E' || c == 'P' || c == 'B')
		return (1);
}

void	load_wall(t_game *game)
{
	mlx_texture_t *wall;

	wall = mlx_load_png("assets/walls/wall_2.png");
	if (!wall)
		return (0); // image load fail
	
}

int	load_images(t_game *game)
{
	load_wall(game); // 1
	load_floor(game); // 0
	load_exit(game); // E
	load_player(game); // P
	load_monster(game); // B
	load_chest(game); // C
}