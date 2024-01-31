/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:00:45 by jlu               #+#    #+#             */
/*   Updated: 2024/01/31 17:20:33 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	remove_chest(t_game *game, int y, int x)
{
	size_t	i;
	
	x = x * 32;
	y = y * 32;
	i = 0;
	while (i < game->chest)
	{	
		if (game->img->chest_closed->instances[i].x == x && game->img->chest_closed->instances[i].y == y)
			game->img->chest_closed->instances[i].enabled = false;
		i++;
	}
}

t_game	*player_right(t_game *game)
{	
	clear_player(game);
	game->img->player_right->enabled = true;
	if (game->map[game->player_y][game->player_x + 1] != '1' && game->map[game->player_y][game->player_x +1] != 'E')
	{
		if (game->map[game->player_y][game->player_x + 1] == 'C')
		{
			remove_chest(game, game->player_y, game->player_x + 1);
			game->map[game->player_y][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_x += 1;
		game->img->player_right->instances[0].x += 1 * PIXELS;
		game->img->player_up->instances[0].x += 1 * PIXELS;
		game->img->player_left->instances[0].x += 1 * PIXELS;
		game->img->player_down->instances[0].x += 1 * PIXELS;
		game->img->player_die->instances[0].x += 1 * PIXELS;
		game->steps += 1;
	}
	if (game->map[game->player_y][game->player_x + 1] == 'X')
		check_touched(game);
	check_game(game);
	return (game);
}
t_game	*player_left(t_game *game)
{
	clear_player(game);
	game->img->player_left->enabled = true;
	if (game->map[game->player_y][game->player_x - 1] != '1' && game->map[game->player_y][game->player_x - 1] != 'E')
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
		{
			remove_chest(game, game->player_y, game->player_x - 1);
			game->map[game->player_y][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_x -= 1;
		game->img->player_left->instances[0].x -= 1 * PIXELS;
		game->img->player_down->instances[0].x -= 1 * PIXELS;
		game->img->player_up->instances[0].x -= 1 * PIXELS;
		game->img->player_right->instances[0].x -= 1 * PIXELS;
		game->img->player_die->instances[0].x -= 1 * PIXELS;
		game->steps += 1;
	}
	if (game->map[game->player_y][game->player_x - 1] == 'X')
		check_touched(game);		
	check_game(game);
	return (game);
}

t_game	*player_down(t_game *game)
{
	clear_player(game);
	game->img->player_down->enabled = true;
	if (game->map[game->player_y + 1][game->player_x] != '1' && game->map[game->player_y + 1][game->player_x] != 'E')
	{
		if (game->map[game->player_y + 1][game->player_x] == 'C')
		{
			remove_chest(game, game->player_y + 1, game->player_x);
			game->map[game->player_y][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y += 1;
		game->img->player_down->instances[0].y += 1 * PIXELS;
		game->img->player_up->instances[0].y += 1 * PIXELS;
		game->img->player_right->instances[0].y += 1 * PIXELS;
		game->img->player_left->instances[0].y += 1 * PIXELS;
		game->img->player_die->instances[0].y += 1 * PIXELS;
		game->steps += 1;
	}
	if (game->map[game->player_y + 1][game->player_x])
		check_touched(game);
	check_game(game);
	return (game);
}
t_game	*player_up(t_game *game)
{
	clear_player(game);
	game->img->player_up->enabled = true;
	if (game->map[game->player_y - 1][game->player_x] != '1' && game->map[game->player_y - 1][game->player_x] != 'E')
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
		{
			remove_chest(game, game->player_y - 1, game->player_x);
			game->map[game->player_y - 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y -= 1;
		game->img->player_up->instances[0].y -= 1 * PIXELS;
		game->img->player_down->instances[0].y -= 1 * PIXELS;
		game->img->player_right->instances[0].y -= 1 * PIXELS;
		game->img->player_left->instances[0].y -= 1 * PIXELS;
		game->img->player_die->instances[0].y -= 1 * PIXELS;
		game->steps += 1;
	}
	check_game(game);
	return (game);
}
