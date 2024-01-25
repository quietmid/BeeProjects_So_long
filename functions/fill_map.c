/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:01:43 by jlu               #+#    #+#             */
/*   Updated: 2024/01/23 14:59:58 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	select_image(t_game *game , size_t y, size_t x)
{
	size_t	img_size;

	img_size = 32;
	if (game->map[y][x] == '1')
		if (mlx_image_to_window(game->mlx_ptr, game->img->wall, x * PIXELS, y * PIXELS) < 0)
			error_msg_params("Failed to put image to Wall");
	if (game->map[y][x] == 'C')
		if (mlx_image_to_window(game->mlx_ptr, game->img->chest_closed, x * PIXELS, y * PIXELS) < 0)
			error_msg_params("Failed to put image to Chest");
	if (game->map[y][x] == 'P')
		if (mlx_image_to_window(game->mlx_ptr, game->img->player, x * PIXELS, y * PIXELS) < 0)
			error_msg_params("Failed to put image to Player");
	if (game->map[y][x] == 'E')
		if (mlx_image_to_window(game->mlx_ptr, game->img->exit_closed, x * PIXELS, y * PIXELS) < 0)
			error_msg_params("Failed to put image to Exit");

}

void	fill_map(t_game *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;

	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (mlx_image_to_window(data->mlx_ptr, data->img->floor, x * PIXELS, y * PIXELS) < 0)
				error_msg_params("Failed to load image to window");
			x++;
		}
		y++;
	}
}

void	render_map(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			select_image(game, y, x);
			x++;
		}
		y++;
	}
}