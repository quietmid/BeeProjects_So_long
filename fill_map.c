/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:01:43 by jlu               #+#    #+#             */
/*   Updated: 2024/01/19 14:09:55 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (mlx_image_to_window(data->mlx_ptr, data->img->floor, x * PIXELS, y *PIXELS) < 0)
				error_msg_params("Failed to load image to window");
			x++;
		}
		y++;
	}
}