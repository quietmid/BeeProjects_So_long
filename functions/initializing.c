/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:42:08 by jlu               #+#    #+#             */
/*   Updated: 2024/01/23 15:03:25 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_player_texts(t_game *game)
{
	game->player_Right = mlx_load_png("./assets/hero/Walk_Right.png");
	if (!game->player_Right)
		error_msg_params("Problem with png loading");
	game->player_Left = mlx_load_png("./assets/hero/Walk_Left.png");
	if (!game->player_Left)
		error_msg_params("Problem with png loading");
	game->player_Down = mlx_load_png("./assets/hero/Walk_Down.png");
	if (!game->player_Down)
		error_msg_params("Problem with png loading");
	game->player_Up = mlx_load_png("./assets/hero/Walk_Up.png");
	if (!game->player_Up)
		error_msg_params("Problem with png loading");
	return (0);
}

t_game	*initialzing_game_struct(char **map_array)
{
	t_game *game;
	
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_msg_params("Struct Memory Allocation Failed");
	game->width = ft_strlen(map_array[0]);
	game->height = map_height(map_array);
	game->map = map_array;
	game->steps = 0;
	game->chest = count_chests(game);
	game->player_x = get_player_pos(game, 'x');
	game->player_y = get_player_pos(game, 'y');
	game->exit_x = get_exit_pos(game, 'x');
	game->exit_y = get_exit_pos(game, 'y');
	load_player_texts(game); 
	return (game);
}

t_img	*init_img_struct(mlx_t *mlx_ptr)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_wall_text(mlx_ptr, assets); 
	assets = load_floor_text(mlx_ptr, assets); 
	assets = load_chestcl_text(mlx_ptr, assets);
	assets = load_chestop_text(mlx_ptr, assets);
	assets = load_exitclosed_text(mlx_ptr, assets);
	assets = load_player_text(mlx_ptr, assets);
	assets = load_exitopen_text(mlx_ptr, assets); 
	assets = load_monster_text(mlx_ptr, assets);
	return (assets);
}
