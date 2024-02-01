/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:38:37 by jlu               #+#    #+#             */
/*   Updated: 2024/02/01 18:33:26 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_monster(t_game *game)
{
	size_t	y;
	size_t	x;
	size_t	i;

	y = 0;
	i = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'X')
				i++;
			x++;
		}
		y++;
	}
	return (i);	
}

void	check_touched(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->monster)
	{
		if (game->player_x * PIXELS == (size_t)game->img->monster_left->instances[i].x && game->player_y * PIXELS == (size_t)game->img->monster_left->instances[i].y)
		{
			clear_player(game);
			game->img->player_die->enabled = true;
			game->img->you_lose = mlx_put_string(game->mlx_ptr, "You Lose :(", ((game->width - 2) * PIXELS) / 2, ((game->height - 1) * PIXELS) / 2);
			game->condition = 2;
			mlx_key_hook(game->mlx_ptr, end_game, game);
		}
		i++;
	}
}

void	monster_move(t_game *game, int count)
{
	t_var var;

	var.x = &game->img->monster_left->instances[count].x;
	var.y = &game->img->monster_left->instances[count].y;
	var.ran_x = (rand() % 3 - 1) * 32;
	var.ran_y = (rand() % 3 - 1) * 32;
	var.idx_x = *var.x + var.ran_x;
	var.idx_y = *var.y + var.ran_y;
	if (var.idx_x != 0)
		var.idx_x /= PIXELS;
	if (var.idx_y != 0)
		var.idx_y /= PIXELS;
	if (game->map[var.idx_y][var.idx_x] != '1' && game->map[var.idx_y][var.idx_x] != 'E')
	{
		*var.x += var.ran_x;
		*var.y += var.ran_y;
	}
}

void	monster_patrol(void *temp)
{
	t_game *game;
	size_t	count;
	static int	i;

	game = temp;
	count = 0;
	check_touched(game);
	if (i++ < EMOVE)
	{
		return ;
	}
	while (count < game->monster && game->condition == 0)
	{
		monster_move(game, count);
		count++;
	}
	i = 0;
}

void	end_game(mlx_key_data_t key, void *data)
{
	t_game *game;

	game = (t_game *) data;
	if (game->condition == 2)
	{
		if (mlx_is_key_down(game->mlx_ptr, key.key))
		{
			mlx_close_window(game->mlx_ptr);
			ft_putstr_fd("The Goblin got you! Let's try again\n", 1);
		}
	}
	else
	{
		if (mlx_is_key_down(game->mlx_ptr, key.key))
		{
			mlx_close_window(game->mlx_ptr);
			ft_putstr_fd("You found all the chest and avoided all the goblins!\n", 1);
		}
	}
}

