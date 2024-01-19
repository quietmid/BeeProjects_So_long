/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:24:39 by jlu               #+#    #+#             */
/*   Updated: 2024/01/19 15:48:28 by jlu              ###   ########.fr       */
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

# define PIXELS 64
# define EMOVE 30

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
	mlx_image_t *player_right;
	mlx_image_t *player_left;
	mlx_image_t *monster_right;
	mlx_image_t *monster_left;
}		t_img;


typedef struct s_game
{
	char	**map; // the map pointer 2D array
	size_t 	player; // the player	
	size_t 	exit; // exit pointer
	size_t	steps;
	size_t 	chest;	// the chest pointer
	size_t	collected;
	size_t	player_x;
	size_t	player_y;
	size_t	exit_x;
	size_t	exit_y;
	size_t	monster; // the pointer for monster 
	size_t	monster_x;
	size_t	monster_y;
	size_t	height;
	size_t	width;
	mlx_texture_t player_right;
	mlx_texture_t player_left;
	t_img	*img;
	mlx_t	*mlx_ptr; // MLX pointer
	
}		t_game;


//utils functions
void	error_msg_params(char *msg);

//map functions

t_game	*check_map(char *mapfile);
t_game	*initialzing_game_struct(char **map_array);
char	*get_map_str(char *mapfile);
void	check_map_content(char *map);
void	check_map_len(char **map);
void	check_wall(t_game *game);
size_t	get_player_pos(t_game *game, char c);
size_t	get_exit_pos(t_game *game, char c);
void	temp_map(t_game *game);
int		check_path(t_game *temp, size_t y, size_t x);
void	free_map(char **map, size_t height);
size_t	map_height(char **map);

// load images
t_img	*init_img_struct(mlx_t *mlx_ptr);
t_img	*load_monster_text(mlx_t *mlx_ptr, t_img *img);
t_img	*load_exitopen_text(mlx_t *mlx_ptr, t_img *img);
t_img	*load_exitclosed_text(mlx_t *mlx_ptr, t_img *img);
t_img	*load_chestop_text(mlx_t *mlx_ptr, t_img *img);
t_img	*load_chestcl_text(mlx_t *mlx_ptr, t_img *img);
t_img	*load_floor_text(mlx_t *mlx_ptr, t_img *img);
t_img	*load_wall_text(mlx_t *mlx_ptr, t_img *img);
t_img	*load_player_text(mlx_t *mlx_ptr, t_img *img);

//Make Image to Window Map
void	fill_map(t_game *data);

#endif
