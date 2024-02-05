/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:56:01 by jlu               #+#    #+#             */
/*   Updated: 2024/02/04 16:58:19 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// prints out the error msg and also free the array of map string
void	error_msg_params(char *msg)
{
	ft_putstr_fd("Error\n", 1);
	ft_putendl_fd(msg, 1);
	exit (1);
}

void	count_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	ft_putstr_fd("Moves:", 1);
	ft_putendl_fd(str, 1);
	free(str);
}

void	check_game(t_game *game)
{
	count_moves(game);
	count_moves_bonus(game);
	count_collected_bonus(game);
	if (game->collected == game->chest)
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->exit_open, \
		game->exit_x * PIXELS, game->exit_y * PIXELS) < 0)
			error_msg_params("Failed to put exit_open image to window!");
		game->map[game->exit_y][game->exit_x] = '0';
		if (game->player_y == game->exit_y && game->player_x == game->exit_x)
		{
			game->img->you_win = mlx_put_string(game->mlx_ptr, "You WIN!", \
			((game->width - 2) * PIXELS) / 2, \
			((game->height - 1) * PIXELS) / 2);
			game->condition = 1;
			mlx_key_hook(game->mlx_ptr, end_game, game);
		}
	}
}

void	clear_player(t_game *game)
{
	game->img->player_down->enabled = false;
	game->img->player_left->enabled = false;
	game->img->player_up->enabled = false;
	game->img->player_right->enabled = false;
	game->img->player->enabled = false;
	game->img->player_die->enabled = false;
}
