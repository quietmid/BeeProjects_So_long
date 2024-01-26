/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:00:45 by jlu               #+#    #+#             */
/*   Updated: 2024/01/26 18:50:23 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

//void	remove_chest(t_game *game, int y, int x)
//{
//	int	chest_count;

//	chest_count = 0;
//	while (chest_count < game->img->chest_closed->count)
//	{
//		if (game->img->chest_closed->instances)
//	}
//}


// draw the new image here
	//mlx_image_to_window(game->mlx_ptr, game->img->player_right, 1, 2);
	//only puts the new char at the top left corner

t_game	*player_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1' && game->map[game->player_y][game->player_x + 1] != 'E')
	{
		//if (game->map[game->player_y][game->player_x + 1] == 'C')
		//{

		//}
		game->player_x += 1;
		game->img->player->instances[0].x += 1 * PIXELS;
		game->steps += 1;
	}
	return (game);
}
t_game	*player_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1' && game->map[game->player_y][game->player_x - 1] != 'E')
	{
		//if (game->map[game->player_y][game->player_x + 1] == 'C')
		//{

		//}
		game->player_x -= 1;
		game->img->player->instances[0].x -= 1 * PIXELS;
		game->steps += 1;
	}
	return (game);
}
t_game	*player_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1' && game->map[game->player_y + 1][game->player_x] != 'E')
	{
		//if (game->map[game->player_y][game->player_x + 1] == 'C')
		//{

		//}
		game->player_y += 1;
		game->img->player->instances[0].y += 1 * PIXELS;
		game->steps += 1;
	}
	return (game);
}
t_game	*player_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1' && game->map[game->player_y - 1][game->player_x] != 'E')
	{
		//if (game->map[game->player_y][game->player_x + 1] == 'C')
		//{

		//}
		game->player_y -= 1;
		game->img->player->instances[0].y -= 1 * PIXELS;
		game->steps += 1;
	}
	return (game);
}