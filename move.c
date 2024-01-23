/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:29:22 by jlu               #+#    #+#             */
/*   Updated: 2024/01/23 17:42:49 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_hook(mlx_key_data_t keydata, void *data)
{
	t_game *game;
	
	game = (t_game *) data;

	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx_ptr);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'u');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'l');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'd');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'r');
}

void	move_player(t_game *game, char line, char dir)
{
	if (line == 'y')
	{
		if (dir == 'u')
			player_up(game);
		else
			player_down(game);
	}
	if (line == 'x')
	{
		if (dir == 'r')
			player_right(game);
		else
			player_left(game);
	}
	if (dir == 'u')
		mlx_texture_to_image(game->mlx_ptr, game->player_Up);
	if (dir == 'd')
		mlx_texture_to_image(game->mlx_ptr, game->player_Down);
	if (dir == 'r')
		mlx_texture_to_image(game->mlx_ptr, game->player_Right);
	if (dir == 'l')
		mlx_texture_to_image(game->mlx_ptr, game->player_Left);
}