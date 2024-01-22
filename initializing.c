/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:42:08 by jlu               #+#    #+#             */
/*   Updated: 2024/01/22 16:50:07 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (game);
}

t_img	*load_player_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*player_right;
	mlx_texture_t	*player_left;

	player_right = mlx_load_png("./assets/hero/knight_lookingRight.png");
	if (!player_right)
		error_msg_params("Problem with png loading");
	img->player_right = mlx_texture_to_image(mlx_ptr, player_right);
	if (!img->player_right)
		error_msg_params("Problem with texture to image");
	mlx_delete_texture(player_right);
	player_left = mlx_load_png("./assets/hero/knight_LeftLooking.png");
	if (!player_left)
		error_msg_params("Problem with png loading");
	img->player_left = mlx_texture_to_image(mlx_ptr, player_left);
	if (!img->player_left)
		error_msg_params("Problem with texture to image");
	mlx_delete_texture(player_left);
	return (img);
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
	assets = load_player_text(mlx_ptr, assets); 
	assets = load_exitclosed_text(mlx_ptr, assets); 
	assets = load_exitopen_text(mlx_ptr, assets); 
	assets = load_monster_text(mlx_ptr, assets);
	return (assets);
}
