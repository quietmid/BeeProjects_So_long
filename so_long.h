/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:24:39 by jlu               #+#    #+#             */
/*   Updated: 2024/01/16 17:32:43 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// library functions
# include "MLX42/include/MLX42/MLX42.h"
# include "lib/printf/ft_printf.h"
# include "lib/libft/libft.h"
# include "lib/get_next_line/get_next_line.h"

// C library
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_img
{
	mlx_image_t *wall;
	mlx_image_t *floor;
	mlx_image_t *chest_closed;
	mlx_image_t *chest_open;
	mlx_image_t *exit_closed;
	mlx_image_t *exit_open;
	mlx_image_t *player;
	mlx_image_t *monster;
	mlx_image_t *monster;
};


typedef struct s_game
{
	char	**map; // the map pointer 2D array
	size_t 	player; // the player	
	size_t 	exit; // exit pointer
	size_t	step;
	size_t 	chest;	// the chest pointer
	size_t	collected;
	size_t	player_x;
	size_t	player_y;
	size_t	exit_x;
	size_t	exit_y;
	size_t	monster; // the pointer for monster 
	size_t	monster_x;
	size_t	monster_y;
	mlx_t	*mlx_ptr; // MLX pointer
	
}		t_game;

typedef struct s_map
{
	size_t	height;
	size_t	width;
}		t_map;

//utils functions
void	error_msg_params(char *msg);

//map functions

t_game	*check_map(char *mapfile, t_game *game);
char	*get_map_str(char *mapfile);
void	check_map_content(char *map, t_game *game);
void	check_map_len(char **map, t_map *dim);

#endif
